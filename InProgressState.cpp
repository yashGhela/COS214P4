#include "InProgressState.h"
#include "OnHoldState.h"

void InProgressState::hold(Task* t) {
    std::cout << "Task " << t->getId() << ": InProgress -> OnHold" << std::endl;
    t->setState(new OnHoldState());
}

void InProgressState::complete(Task* t) {
    std::cout << "Task " << t->getId() << ": InProgress -> Completed" << std::endl;
    t->setState(new CompletedState());
}

std::string InProgressState::getName() const {
    return "InProgress";
}

