#include "Setup/MainNetwork.h"

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

# pragma mark -
# pragma mark Execution

bool MainNetwork::load(const string& json)
{
  if (mDocument.Parse(json.data()).HasParseError())
    return false;
  
  if (!mDocument.IsObject())
    return false;
  
  return true;
}

# pragma mark -
# pragma mark Accessors



# pragma mark -
# pragma mark Implementation specific