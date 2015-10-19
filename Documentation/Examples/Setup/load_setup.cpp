/*!
 * \file load_setup.cpp
 *
 * \author Théo de la Hogue
 *
 * This code is licensed under the terms of the "CeCILL-C"
 * http://www.cecill.info
 */

#include <fstream>
#include <sstream>
#include <streambuf>

#include "Setup/Network.h"
#include "Setup/Project.h"
#include "Setup/Score.h"

using namespace OSSIA;
using namespace OSSIA::Toolkit;

#include <iostream>

using namespace std;

int main()
{
  ifstream stream("/Users/WALL-E/Documents/Developpements/OSSIA/APIToolkit/Documentation/Examples/Setup/setup_example.scorejson");
  stringstream buffer;
  
  buffer << stream.rdbuf();
  string json = buffer.str();
  
  auto myProject = Project::create();
  myProject->load(json);
}
