#include "AssigningState.h"


void AssigningState::start(Task* t) {
    std::cout << "Task " << t->getName() << ": Assigning -> InProgress" << std::endl;
    t->setState(new InProgressState());
}

std::string AssigningState::getName() const {
    return "Assigning";
}