/*!
 * \file MainPrinter.h
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

#include "Debug/Printer.h"

using namespace OSSIA;
using namespace OSSIA::Toolkit;
using namespace std;

class MainPrinter : public Printer
{
    
private:
    
# pragma mark -
# pragma mark Implementation specific
    
    int depth;
    
public:
    
# pragma mark -
# pragma mark Life cycle
    
    MainPrinter();
    
    ~MainPrinter();
    
# pragma mark -
# pragma mark Printing
    
    /* print a space
     \return std::string */
    string space() const;
    
    /* print #TimeConstraint */
    void visit(std::shared_ptr<OSSIA::TimeConstraint>);
    
    /* print #TimeEvent */
    void visit(std::shared_ptr<OSSIA::TimeEvent>);
    
    /* print #TimeNode */
    void visit(std::shared_ptr<OSSIA::TimeNode>);
    
    /* print #Scenario */
    void visit(std::shared_ptr<OSSIA::Scenario>);
    
    /* print #Automation */
    void visit(std::shared_ptr<OSSIA::Automation>);
    
    /* print #CurveAbstract */
    void visit(std::shared_ptr<OSSIA::CurveAbstract>);
    
    /* print #CurveSegment<float>> */
    void visit(std::shared_ptr<OSSIA::CurveSegment<float>>);
};
