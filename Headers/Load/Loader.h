/*!
 * \file Loader.h
 *
 * \defgroup Load
 *
 * \brief Ease the loading of a Network setup or/and an Editor project.
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

namespace OSSIA
{
namespace Toolkit
{

class Loader
{

public:

# pragma mark -
# pragma mark Life cycle

  /*! factory
   \return a new loader */
  static std::shared_ptr<Loader> create();

  /*! destructor */
  virtual ~Loader() = default;

# pragma mark -
# pragma mark Loading

  /*! load OSSIA objects from a file
   \param the file to load
   \return true if the loading succeeded */
  virtual bool load(std::string) = 0;

# pragma mark -
# pragma mark Accessors

};
}
}
