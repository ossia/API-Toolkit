/*!
 * \file MainProject.h
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
#include "Setup/Project.h"
#include "Setup/Score.h"

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace OSSIA;
using namespace OSSIA::Toolkit;
using namespace std;
using namespace rapidjson;

class MainProject : public Project
{
  
private:
  
# pragma mark -
# pragma mark Implementation specific
    
  Document mDocument;
  
  shared_ptr<Network> mNetwork;
  shared_ptr<Score> mScore;
  
public:
  
# pragma mark -
# pragma mark Life cycle
  
  MainProject();
  
  ~MainProject();

# pragma mark -
# pragma mark Loading

  bool load(const string&) override;
  
# pragma mark -
# pragma mark Accessors
    
  std::shared_ptr<Network> getNetwork() override;
  
  std::shared_ptr<Score> getScore() override;
};
