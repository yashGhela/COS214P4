#include "Phase.h"
#include "ChronologicalIterator.h"
#include "HighPriorityIterator.h"
#include "TaskOnlyIterator.h"
#include <string>
#include <vector>

Phase::Phase(const std::string& name) : phaseName(name) {}

Phase::~Phase() {
    for (CaseComponent* child : children) {
        delete child;
    }
    children.clear();
}

void Phase::add(CaseComponent* component) {
    children.push_back(component);
}

void Phase::remove(CaseComponent* component) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == component) {
            children.erase(it);
            break;
        }
    }
}

void Phase::assign() {
    for (CaseComponent* child : children) {
        child->assign();
    }
}

void Phase::start() {
    for (CaseComponent* child : children) {
        child->start();
    }
}

void Phase::hold() {
    for (CaseComponent* child : children) {
        child->hold();
    }
}

void Phase::complete() {
    for (CaseComponent* child : children) {
        child->complete();
    }
}

std::string Phase::getStatus(){ //return no of complete tasks/phases
    int total = 0;
    int done = 0;
    for (CaseComponent* child : children) {
        total++;
        if (child->getStatus() == "Completed"){
            done++;
        }
    }

    return std::to_string(done) + "/" + std::to_string(total) + " complete.";
}

std::string Phase::getName() const {
    return phaseName;
}

int Phase::getPriority() const {
    if (children.empty()) {
        return 0;
    }
    int maxPriority = -1;
    for (CaseComponent* child : children) {
        if (child && child->getPriority() > maxPriority) {
            maxPriority = child->getPriority();
        }
    }
    return maxPriority;
}

CaseIterator* Phase::createChronologicalIterator() {
    return new ChronologicalIterator(children);
}

CaseIterator* Phase::createHighPriorityIterator() {
    return new HighPriorityIterator(children);
}

CaseIterator* Phase::createTaskOnlyIterator() {
    return new TaskOnlyIterator(children);
}

