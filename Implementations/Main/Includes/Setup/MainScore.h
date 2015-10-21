/*!
 * \file MainScore.h
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

#include "Setup/Score.h"

#include "Editor/Message.h"
#include "Editor/State.h"
#include "Editor/TimeConstraint.h"
#include "Editor/TimeEvent.h"
#include "Editor/TimeNode.h"

#include "rapidjson/document.h"

using namespace OSSIA;
using namespace OSSIA::Toolkit;
using namespace std;
using namespace rapidjson;

class MainScore : public Score
{
  
private:
  
# pragma mark -
# pragma mark Implementation specific
    
  Document mDocument;
  
  shared_ptr<TimeNode> mStartTimeNode;
  shared_ptr<TimeEvent> mStartTimeEvent;
  shared_ptr<State> mStartState;
  
  shared_ptr<TimeNode> mEndTimeNode;
  shared_ptr<TimeEvent> mEndTimeEvent;
  shared_ptr<State> mEndState;
  
  shared_ptr<TimeConstraint> mMainTimeConstraint;
  
  
public:
  
# pragma mark -
# pragma mark Life cycle
  
  MainScore();
  
  ~MainScore();

# pragma mark -
# pragma mark Loading

  bool load(const string&) override;
  
# pragma mark -
# pragma mark Accessors
  
private:
  
# pragma mark -
# pragma mark Implementation specific
  
  shared_ptr<TimeNode> load_timenode(const rapidjson::Value&);
  shared_ptr<TimeEvent> load_timeevent(const rapidjson::Value&, shared_ptr<TimeNode>);
  shared_ptr<State> load_state(const rapidjson::Value&);
  shared_ptr<Message> load_message(const rapidjson::Value&);
  shared_ptr<Expression> load_expression(const rapidjson::Value&);
  shared_ptr<TimeConstraint> load_timeconstraint(const rapidjson::Value&, shared_ptr<TimeEvent>, shared_ptr<TimeEvent>);
};
