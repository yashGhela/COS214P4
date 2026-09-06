#include "OnHoldState.h"

void OnHoldState::start(Task* t) {
    std::cout << "Task " << t->getId() << ": OnHold -> InProgress (resumed)" << std::endl;
    t->setState(new InProgressState());
}

std::string OnHoldState::getName() const {
    return "OnHold";
}