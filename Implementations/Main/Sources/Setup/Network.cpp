#include "Setup/MainNetwork.h"

#include "Network/Protocol/Local.h"
#include "Network/Protocol/Minuit.h"
#include "Network/Protocol/OSC.h"

#include <iostream> //! \todo to remove. only here for debug purpose

# pragma mark -
# pragma mark Life cycle

namespace OSSIA
{
namespace Toolkit
{
  shared_ptr<Network> Network::create()
  {
    return make_shared<MainNetwork>();
  }
}
}

MainNetwork::MainNetwork()
{}

MainNetwork::~MainNetwork()
{}

Network::~Network()
{}

# pragma mark -
# pragma mark Loading

bool MainNetwork::load(const string& json)
{
  if (mDocument.Parse(json.data()).HasParseError())
    return false;
  
  if (!mDocument.IsObject())
    return false;
  
  // while it is not store inside the json,
  // create a Local device called i-score
  //! \todo work on a better Network json convention
  mDevices.push_back(Device::create(Local::create(), "i-score"));
  
  // parse each device setup
  for (rapidjson::Value::ConstMemberIterator it = mDocument.MemberBegin(); it != mDocument.MemberEnd(); ++it)
  {
    if (!mDocument[it->name.GetString()].ObjectEmpty())
      mDevices.push_back(load_device(mDocument[it->name.GetString()]["Children"][0]));
  }
  
  return true;
}

# pragma mark -
# pragma mark Accessors

const Container<Device> MainNetwork::getDevices()
{
  return mDevices;
}

# pragma mark -
# pragma mark Implementation specific

shared_ptr<Device> MainNetwork::load_device(const rapidjson::Value& json_device)
{
  // get device name
  string name = json_device["DeviceSettings"]["Name"].GetString();
  
  // make device's protocol
  shared_ptr<Protocol> protocol;
  string protocol_type = json_device["DeviceSettings"]["Protocol"].GetString();
  
  if (protocol_type == "OSC")
  {
    string ip = json_device["DeviceSettings"]["Host"].GetString();
    int in_port = json_device["DeviceSettings"]["InputPort"].GetInt();
    int out_port = json_device["DeviceSettings"]["OutputPort"].GetInt();
    protocol = OSC::create(ip, in_port, out_port);
  }
  else if (protocol_type == "Minuit")
  {
    string ip = json_device["DeviceSettings"]["Host"].GetString();
    int in_port = json_device["DeviceSettings"]["InputPort"].GetInt();
    int out_port = json_device["DeviceSettings"]["OutputPort"].GetInt();
    protocol = Minuit::create(ip, in_port, out_port);
  }
  
  shared_ptr<Device> device = Device::create(protocol, name);
  
  // load children recursively
  load_node(json_device["Children"], device);
  
  return device;
}

void MainNetwork::load_node(const rapidjson::Value& json_children, shared_ptr<Node> parent_node)
{
  for (rapidjson::Value::ConstValueIterator it = json_children.Begin(); it != json_children.End(); ++it)
  {
    const rapidjson::Value& json_child = *it;
    
    //! \debug
    cout << "MainNetwork::load_node : " << json_child["AddressSettings"]["Name"].GetString() << endl;
    
    // create Node
    auto child_node = parent_node->emplace(parent_node->children().begin(), json_child["AddressSettings"]["Name"].GetString());
    
    // edit Address
    load_address(json_child["AddressSettings"], *child_node);
    
    // load children recursively
    load_node(json_child["Children"], *child_node);
  }
}

void MainNetwork::load_address(const rapidjson::Value& json_address, shared_ptr<Node> node)
{
  // create Address if needed by looking at ioType
  //! \todo work on a better Network json convention
  if (json_address["ioType"] != "")
  {
    // load ValueType
    //! \todo work on a better Network json convention
    OSSIA::Value::Type type;
    
    if (json_address["Type"] == "impulse")
      type = OSSIA::Value::Type::IMPULSE;
    else if (json_address["Type"] == "bool")
      type = OSSIA::Value::Type::BOOL;
    else if (json_address["Type"] == "int")
      type = OSSIA::Value::Type::INT;
    else if (json_address["Type"] == "float")
      type = OSSIA::Value::Type::FLOAT;
    else if (json_address["Type"] == "char")
      type = OSSIA::Value::Type::CHAR;
    else if (json_address["Type"] == "QString")
      type = OSSIA::Value::Type::STRING;
    else if (json_address["Type"] == "Tuple")
      type = OSSIA::Value::Type::TUPLE;
    else if (json_address["Type"] == "Destination")
      type = OSSIA::Value::Type::DESTINATION;
    else if (json_address["Type"] == "Behavior")
      type = OSSIA::Value::Type::BEHAVIOR;
    else
      type = OSSIA::Value::Type::IMPULSE;
    
    auto address = node->createAddress(type);
    
    // load AccessMode
    if (json_address["ioType"] == "->")
      address->setAccessMode(OSSIA::Address::AccessMode::SET);
    else if (json_address["ioType"] == "<-")
      address->setAccessMode(OSSIA::Address::AccessMode::GET);
    else if (json_address["ioType"] == "<->")
      address->setAccessMode(OSSIA::Address::AccessMode::BI);
    
    // load BoundingMode
    if (json_address["ClipMode"] == "Free")
      address->setBoundingMode(OSSIA::Address::BoundingMode::FREE);
    else if (json_address["ClipMode"] == "Clip")
      address->setBoundingMode(OSSIA::Address::BoundingMode::CLIP);
    else if (json_address["ClipMode"] == "Wrap")
      address->setBoundingMode(OSSIA::Address::BoundingMode::WRAP);
    else if (json_address["ClipMode"] == "Fold")
      address->setBoundingMode(OSSIA::Address::BoundingMode::FOLD);
    
    // load RepetitionFilter
    address->setRepetitionFilter(json_address["RepetitionFilter"].GetBool());
    
    // load Domain
    if (json_address.HasMember("Domain"))
    {
      OSSIA::Value* min;
      if (json_address["Domain"].HasMember("Min"))
        min = load_value(json_address["Domain"]["Min"]);
      else
        min = new OSSIA::Impulse();
        
      OSSIA::Value* max;
      if (json_address["Domain"].HasMember("Max"))
        max = load_value(json_address["Domain"]["Max"]);
      else
        max = new OSSIA::Impulse();
      
      vector<const OSSIA::Value*> values;
      if (json_address["Domain"].HasMember("Values"))
        for (rapidjson::Value::ConstValueIterator it = json_address["Domain"]["Values"].Begin(); it != json_address["Domain"]["Values"].End(); ++it)
          values.push_back(load_value(*it));
      
      auto domain = Domain::create(min, max, values);
      address->setDomain(domain);
    }
    
    // load Value
    address->setValue(load_value(json_address["Value"]));
  }
}

OSSIA::Value* MainNetwork::load_value(const rapidjson::Value& json_value)
{
  if (json_value.IsBool())
    return new OSSIA::Bool(json_value.GetBool());
  
  else if (json_value.IsInt())
    return new OSSIA::Int(json_value.GetInt());
  
  else if (json_value.IsDouble())
    return new OSSIA::Float(json_value.GetDouble());
  
  else if (json_value.IsString())
    return new OSSIA::String(json_value.GetString());
  
  else if (json_value.IsArray())
  {
    vector<const OSSIA::Value*> values;
    for (rapidjson::Value::ConstValueIterator it = json_value.Begin(); it != json_value.End(); ++it)
      values.push_back(load_value(*it));
    
    return new OSSIA::Tuple(values);
  }
  
  else
    return new OSSIA::Impulse();
}