#include "Debug/MainPrinter.h"

# pragma mark -
# pragma mark Life cycle

namespace OSSIA
{
namespace Toolkit
{
  shared_ptr<Printer> Printer::create()
  {
    return make_shared<MainPrinter>();
  }
}
}

MainPrinter::MainPrinter()
{}

MainPrinter::~MainPrinter()
{}

Printer::~Printer()
{}

# pragma mark -
# pragma mark Printing

string MainPrinter::space() const
{
    return string(depth, ' ');
}

void MainPrinter::visit(shared_ptr<OSSIA::TimeConstraint> cst)
{
    cerr << space() << "TimeConstraint " << double(cst->getDurationNominal()) << endl;
    depth++;
    
    for(const auto& proc : cst->timeProcesses())
    {
        if(auto scenar = dynamic_pointer_cast<OSSIA::Scenario>(proc))
            visit(scenar);
        else if(auto autom = dynamic_pointer_cast<OSSIA::Automation>(proc))
            visit(autom);
    }
    
    visit(cst->getEndEvent());
    depth--;
}

void MainPrinter::visit(shared_ptr<OSSIA::TimeEvent> ev)
{
    cerr << space() << "TimeEvent" << endl;
    depth++;
    
    for(const auto& cst : ev->nextTimeConstraints())
    {
        visit(cst);
    }
    depth--;
}

void MainPrinter::visit(shared_ptr<OSSIA::TimeNode> tn)
{
    cerr << space() << "TimeNode" << endl;
    depth++;
    
    for(const auto& event : tn->timeEvents())
    {
        visit(event);
    }
    depth--;
}

void MainPrinter::visit(shared_ptr<OSSIA::Scenario> scenar)
{
    cerr << space() << "Scenario" << endl;
    depth++;
    
    visit(scenar->getStartTimeNode());
    depth--;
}

void MainPrinter::visit(shared_ptr<OSSIA::Automation> autom)
{
    cerr << space() << "Automation" << endl;
    auto d = autom->getDriving();
    
    if(auto b = dynamic_cast<const OSSIA::Behavior*>(d))
    {
        depth++;
        visit(b->value);
        depth--;
    }
}

void MainPrinter::visit(shared_ptr<OSSIA::CurveAbstract> curve)
{
    /*
     if(auto c = dynamic_cast<OSSIA::Curve<float>*>(curve.get()))
     {
        cerr << space() << "Curve " << c->getPointsMap().size() <<  endl;
        depth++;
     
        for(const auto& seg : c->getPointsMap())
        {
            visit(seg.second.second);
        }
        depth--;
     }
     */
}

void MainPrinter::visit(shared_ptr<OSSIA::CurveSegment<float>> curve)
{
    cerr << space() << "CurveSegment" << endl;
}
