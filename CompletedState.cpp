#include "CompletedState.h"
#include <string>

std::string CompletedState::getName() const {
    return "Completed";
}

bool CompletedState::isTerminal() const {
    return true;
}