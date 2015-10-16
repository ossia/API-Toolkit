/*!
 * \file MainLoader.h
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

#include "Load/Loader.h"

using namespace OSSIA;
using namespace OSSIA::Toolkit;
using namespace std;

class MainLoader : public Loader
{
  
private:
  
# pragma mark -
# pragma mark Implementation specific
  
public:
  
# pragma mark -
# pragma mark Life cycle
  
  MainLoader();
  
  ~MainLoader();

# pragma mark -
# pragma mark Loading

  bool load(string) override;
  
# pragma mark -
# pragma mark Accessors
  
private:
  
# pragma mark -
# pragma mark Implementation specific

};
