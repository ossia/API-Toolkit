#include "Setup/MainScore.h"

#include <iostream> //! \todo to remove. only here for debug purpose

# pragma mark -
# pragma mark Life cycle

namespace OSSIA
{
  namespace Toolkit
  {
    shared_ptr<Score> Score::create()
    {
      return make_shared<MainScore>();
    }
  }
}

MainScore::MainScore()
{}

MainScore::~MainScore()
{}

# pragma mark -
# pragma mark Loading

bool MainScore::load(const string& json)
{
  if (mDocument.Parse(json.data()).HasParseError())
    return false;
  
  if (!mDocument.IsObject())
    return false;
  
  mStartTimeNode = load_timenode(mDocument["BaseScenario"]["StartTimeNode"]);
  mStartTimeEvent = load_timeevent(mDocument["BaseScenario"]["StartEvent"], mStartTimeNode);
  mStartState = load_state(mDocument["BaseScenario"]["StartState"]);
  
  mEndTimeNode = load_timenode(mDocument["BaseScenario"]["EndTimeNode"]);
  mEndTimeEvent = load_timeevent(mDocument["BaseScenario"]["EndEvent"], mEndTimeNode);
  mEndState = load_state(mDocument["BaseScenario"]["EndState"]);
  
  mMainTimeConstraint = load_timeconstraint(mDocument["BaseScenario"]["Constraint"], mStartTimeEvent, mEndTimeEvent);
  
  return true;
}

# pragma mark -
# pragma mark Accessors



# pragma mark -
# pragma mark Implementation specific

shared_ptr<TimeNode> MainScore::load_timenode(const rapidjson::Value& json_timenode)
{
  auto node = TimeNode::create();
  
  if (json_timenode.HasMember("Trigger"))
  {
    auto expression = load_expression(json_timenode["Trigger"]["Expression"]);
    node->setExpression(expression);
  }
  
  return node;
}

shared_ptr<TimeEvent> MainScore::load_timeevent(const rapidjson::Value& json_event, shared_ptr<TimeNode> parent_timenode)
{
  TimeEvent::ExecutionCallback callback;
  std::shared_ptr<Expression> expression = ExpressionTrue;
  
  if (json_event.HasMember("Condition"))
    expression = load_expression(json_event["Condition"]);
  
  auto it = parent_timenode->emplace(parent_timenode->timeEvents().begin(), callback, expression);
  
  return *it;
}

shared_ptr<State> MainScore::load_state(const rapidjson::Value& json_state)
{
  auto state = State::create();
  
  //! \todo load all message
  for (rapidjson::Value::ConstValueIterator it = json_state["Messages"].Begin(); it != json_state["Messages"].End(); ++it)
  {
    state->stateElements().push_back(load_message(*it));
  }
  
  return state;
}

shared_ptr<Message> MainScore::load_message(const rapidjson::Value& json_message)
{
  //! \todo retreive address into the Network setup
  //! \todo get value
  
  //return Message::create();
  return nullptr;
}

shared_ptr<Expression> MainScore::load_expression(const rapidjson::Value& json_expression)
{
  auto expression = Expression::create();
  
  //! \todo load expression (I need a json example)
  
  return expression;
}

shared_ptr<TimeConstraint> MainScore::load_timeconstraint(const rapidjson::Value& json_constraint, shared_ptr<TimeEvent> start_event, shared_ptr<TimeEvent> end_event)
{
  TimeConstraint::ExecutionCallback callback;
  const TimeValue& duration = json_constraint["DefaultDuration"].GetDouble();
  const TimeValue& min_duration = json_constraint["MinDuration"].GetDouble();
  const TimeValue& max_duration = json_constraint["MaxDuration"].GetDouble();
  
  auto constraint = TimeConstraint::create(callback, start_event, end_event, duration, min_duration, max_duration);
  
  //! \todo load all processes
  for (rapidjson::Value::ConstValueIterator it = json_constraint["Processes"].Begin(); it != json_constraint["Processes"].End(); ++it)
  {
    const rapidjson::Value& json_process = *it;
    
    //! \debug
    cout << "MainScore::load_timeconstraint : have " << json_process["ProcessName"].GetString() << endl;
  }
  
  return constraint;
}