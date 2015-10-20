/*!
 * \file Network.h
 *
 * \defgroup Setup
 *
 * \brief Ease the management of a Network setup
 *
 * \details
 *
 * \author Théo de la Hogue
 *
 * \copyright This code is licensed under the terms of the "CeCILL-C"
 * http://www.cecill.info
 */

#pragma once

#include <memory>
#include <string>

#include "Network/Device.h"
#include "Misc/Container.h"

namespace OSSIA
{
namespace Toolkit
{

class Network
{

public:

# pragma mark -
# pragma mark Life cycle

  /*! factory
   \return a new Network */
  static std::shared_ptr<Network> create();

  /*! destructor */
  virtual ~Network() = default;

# pragma mark -
# pragma mark Loading

  /*! load OSSIA Network objects from a json string
   \param json string
   \return true if the loading succeeded */
  virtual bool load(const std::string&) = 0;

# pragma mark -
# pragma mark Accessors
  
  /*! get all devices
   \return #Container<#Device> */
  virtual const Container<Device> getDevices() = 0;

};
}
}
