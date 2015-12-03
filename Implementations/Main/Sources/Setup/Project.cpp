#include "Setup/MainProject.h"

#include <iostream> //! \todo to remove. only here for debug purpose

# pragma mark -
# pragma mark Life cycle

namespace OSSIA
{
namespace Toolkit
{
  shared_ptr<Project> Project::create()
  {
    return make_shared<MainProject>();
  }
}
}

MainProject::MainProject() :
mNetwork(Network::create()),
mScore(Score::create())
{}

MainProject::~MainProject()
{}

Project::~Project()
{}

# pragma mark -
# pragma mark Loading

bool MainProject::load(const string& json)
{
  // clear former setups
  mNetwork = nullptr;
  mScore = nullptr;
  
  if (mDocument.Parse(json.data()).HasParseError())
    return false;
  
  if (!mDocument.IsObject())
    return false;
  
  // get json string network setup
  rapidjson::Value& network = mDocument["Plugins"];
  if (network.IsObject())
  {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    network.Accept(writer);
    
    mNetwork = Network::create();
    mNetwork->load(buffer.GetString());
  }
  
  // get json string score setup
  rapidjson::Value& score = mDocument["Document"];
  if (score.IsObject())
  {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    score.Accept(writer);
    
    mScore = Score::create();
    mScore->load(buffer.GetString());
  }
  
  return true;
}

# pragma mark -
# pragma mark Accessors

std::shared_ptr<Network> MainProject::getNetwork()
{
  return mNetwork;
}

std::shared_ptr<Score> MainProject::getScore()
{
  return mScore;
}