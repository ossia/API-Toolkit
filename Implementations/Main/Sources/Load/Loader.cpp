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
    return false;
}

# pragma mark -
# pragma mark Accessors
