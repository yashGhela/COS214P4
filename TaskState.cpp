#include "TaskState.h"
#include "Task.h"
#include <string>

void TaskState::assign(Task* t){
    invalidTransition(t, "assign");
}

void TaskState::start(Task* t){
    invalidTransition(t, "start");
}

void TaskState::hold(Task* t){
    invalidTransition(t, "hold");
}

void TaskState::complete(Task* t){
    invalidTransition(t, "complete");
}

void TaskState::invalidTransition(Task* t, const std::string& action){
    std::cout << "Invalid action: " << action << " from task " << t->getName() << std::endl;
}

bool TaskState::isTerminal() const {
    return false;
}

