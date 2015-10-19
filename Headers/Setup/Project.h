/*!
 * \file Project.h
 *
 * \defgroup Setup
 *
 * \brief Ease the management of a Network and a Score setup
 *
 * \details
 *
 * \author Théo de la Hogue
 *
 * \copyright This code is licensed under the terms of the "CeCILL-C"
 * http://www.cecill.info
 */

#pragma once

#include "Network.h"
#include "Score.h"

namespace OSSIA
{
namespace Toolkit
{

class Project
{
            
public:
            
# pragma mark -
# pragma mark Life cycle
            
    /*! factory
    \return a new Project */
    static std::shared_ptr<Project> create();
            
    /*! destructor */
    virtual ~Project() = default;
            
# pragma mark -
# pragma mark Loading
            
    /*! load Network and Score from a json string
    \param json string
    \return true if the loading succeeded */
    virtual bool load(const std::string&) = 0;
            
# pragma mark -
# pragma mark Accessors
    
    /*! get Network setup
     \return std::shared_ptr<Network> */
    virtual std::shared_ptr<Network> getNetwork() = 0;
    
    /*! get Score setup
     \return std::shared_ptr<Score> */
    virtual std::shared_ptr<Score> getScore() = 0;
};
}
}