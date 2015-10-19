/*!
 * \file MainScore.h
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

#include "Setup/Score.h"

#include "rapidjson/document.h"

using namespace OSSIA;
using namespace OSSIA::Toolkit;
using namespace std;
using namespace rapidjson;

class MainScore : public Score
{
  
private:
  
# pragma mark -
# pragma mark Implementation specific
    
  Document mDocument;
  
public:
  
# pragma mark -
# pragma mark Life cycle
  
  MainScore();
  
  ~MainScore();

# pragma mark -
# pragma mark Loading

  bool load(const string&) override;
  
# pragma mark -
# pragma mark Accessors
  
private:
  
# pragma mark -
# pragma mark Implementation specific

};
