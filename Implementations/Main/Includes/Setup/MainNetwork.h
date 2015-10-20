/*!
 * \file MainNetwork.h
 *
 * \brief
 *
 * \details
 *
 * \author Théo de la Hogue
 *
 * \copyright This code is licensed under the terms of the "CeCILL-C"
 * http://www.cecill.info
 */

#pragma once

#include "Setup/Network.h"

#include "rapidjson/document.h"

using namespace OSSIA;
using namespace OSSIA::Toolkit;
using namespace std;
using namespace rapidjson;

class MainNetwork : public Network
{
  
private:
  
# pragma mark -
# pragma mark Implementation specific
    
  Document mDocument;
  
  Container<Device> mDevices;
  
public:
  
# pragma mark -
# pragma mark Life cycle
  
  MainNetwork();
  
  ~MainNetwork();

# pragma mark -
# pragma mark Loading

  bool load(const string&) override;
  
# pragma mark -
# pragma mark Accessors

  const Container<Device> getDevices() override;
  
private:
  
# pragma mark -
# pragma mark Implementation specific
  
  shared_ptr<Device> load_device(const rapidjson::Value&);
  void load_node(const rapidjson::Value&, shared_ptr<Node>);
  void load_address(const rapidjson::Value&, shared_ptr<Node>);
  OSSIA::Value* load_value(const rapidjson::Value&);
};
