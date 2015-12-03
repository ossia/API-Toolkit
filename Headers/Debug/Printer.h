/*!
 * \file Printer.h
 *
 * \defgroup Debug
 *
 * \brief Ease debugging by printing OSSIA API objects attributes
 *
 * \details
 *
 * \author Jean-Michaël Célérier, Théo de la Hogue
 *
 * \copyright This code is licensed under the terms of the "CeCILL-C"
 * http://www.cecill.info
 */

#pragma once

#include <Editor/TimeConstraint.h>
#include <Editor/TimeNode.h>
#include <Editor/TimeEvent.h>
#include <Editor/Scenario.h>
#include <Editor/Curve.h>
#include <Editor/CurveSegment.h>
#include <Editor/Automation.h>

#include <iostream>

namespace OSSIA
{
namespace Toolkit
{
    
class Printer
{

public:
    
# pragma mark -
# pragma mark Life cycle
    
    /*! factory
     \return a new Printer */
    static std::shared_ptr<Printer> create();
    
    /*! destructor */
    virtual ~Printer();
    
# pragma mark -
# pragma mark Printing
    
    /* print a space 
     \return std::string */
    virtual std::string space() const = 0;

    /* print #TimeConstraint */
    virtual void visit(std::shared_ptr<OSSIA::TimeConstraint>) = 0;

    /* print #TimeEvent */
    virtual void visit(std::shared_ptr<OSSIA::TimeEvent>) = 0;

    /* print #TimeNode */
    virtual void visit(std::shared_ptr<OSSIA::TimeNode>) = 0;
    
    /* print #Scenario */
    virtual void visit(std::shared_ptr<OSSIA::Scenario>) = 0;
    
    /* print #Automation */
    virtual void visit(std::shared_ptr<OSSIA::Automation>) = 0;

    /* print #CurveAbstract */
    virtual void visit(std::shared_ptr<OSSIA::CurveAbstract>) = 0;

    /* print #CurveSegment<float>> */
    virtual void visit(std::shared_ptr<OSSIA::CurveSegment<float>>) = 0;
};

}
}
