#include "Load/MainLoader.h"

#include <iostream> //! \todo to remove. only here for debug purpose

# pragma mark -
# pragma mark Life cycle

namespace OSSIA
{
namespace Toolkit
{
  shared_ptr<Loader> Loader::create()
  {
    return make_shared<MainLoader>();
  }
}
}

MainLoader::MainLoader()
{}

MainLoader::~MainLoader()
{}

# pragma mark -
# pragma mark Execution

bool MainLoader::load(string filepath)
{
  ifstream stream(filepath);
  stringstream buffer;
  
  buffer << stream.rdbuf();
  string json = buffer.str();
  
  if (mDocument.Parse(json.data()).HasParseError())
    return false;
  
  if (!mDocument.IsObject())
    return false;
  
  Value& editor = mDocument["Document"];
  
  cout << "DocumentId : " << editor["DocumentId"].GetInt() << endl;
  cout << "ObjectName : " << editor["ObjectName"].GetString() << endl;
  cout << "id : " << editor["id"].GetInt() << endl;
  
  Value& network = mDocument["Plugins"];
  
  return true;
}

# pragma mark -
# pragma mark Accessors



# pragma mark -
# pragma mark Implementation specific