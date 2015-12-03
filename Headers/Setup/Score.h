/*!
 * \file Score.h
 *
 * \defgroup Setup
 *
 * \brief Ease the management of a Score setup
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
        
class Score
{
            
public:
            
# pragma mark -
# pragma mark Life cycle
            
    /*! factory
    \return a new Score */
    static std::shared_ptr<Score> create();
            
    /*! destructor */
    virtual ~Score();
            
# pragma mark -
# pragma mark Loading
            
    /*! load OSSIA Score objects from a json string
    \param json string
    \return true if the loading succeeded */
    virtual bool load(const std::string&) = 0;
            
# pragma mark -
# pragma mark Accessors
            
};
}
}