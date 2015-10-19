#include "Setup/MainScore.h"

#include <iostream> //! \todo to remove. only here for debug purpose

# pragma mark -
# pragma mark Life cycle

namespace OSSIA
{
namespace Toolkit
{
  shared_ptr<Score> Score::create()
  {
    return make_shared<MainScore>();
  }
}
}

MainScore::MainScore()
{}

MainScore::~MainScore()
{}

# pragma mark -
# pragma mark Execution

bool MainScore::load(const string& json)
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