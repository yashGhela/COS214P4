#include "TaskOnlyIterator.h"
#include "CaseComponent.h"
#include "Phase.h"

TaskOnlyIterator::TaskOnlyIterator(const std::vector<CaseComponent*>& items) : index(0) {
    collectTasks(items);   
}

void TaskOnlyIterator::collectTasks(const std::vector<CaseComponent*>& items) {
    for (CaseComponent* item : items) {
        if (dynamic_cast<Task*>(item) != nullptr) {
            list.push_back(item);
        } else if (Phase* p = dynamic_cast<Phase*>(item)) {
            collectTasks(p->getChildren());
        }
    }
}

CaseComponent* TaskOnlyIterator::first() {
    index = 0;
    return current();
}

CaseComponent* TaskOnlyIterator::next() {
    index++;
    return current();
}

bool TaskOnlyIterator::hasNext() {
    return index < list.size();
}


CaseComponent* TaskOnlyIterator::current() {
    return hasNext() ? list[index] : nullptr;
}