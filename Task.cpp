#include "Task.h"

Task::Task( int id, const std::string& name, int priority) : taskID(id) , taskName(name), priority(priority) {
    state = new AssigningState();
}

Task::~Task() {
    delete state;
}

int Task::getId() const{
    return taskID;
}

int Task::getPriority() const {
    return priority;
}

std::string Task::getName() const {
    return taskName;
}

void Task::setState(TaskState* newState) {
    delete state;
    state = newState;
}

void Task::assign() {
    state->assign(this);
}

void Task::start() {
    state->start(this);
}

void Task::hold() {
    state->hold(this);
}

void Task::complete() {
    state->complete(this);
}

std::string Task::getStatus() {
    return state->getName();
}
