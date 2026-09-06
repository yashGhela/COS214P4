#include "TaskOnlyIterator.h"
#include "CaseComponent.h"

TaskOnlyIterator::TaskOnlyIterator(const std::vector<CaseComponent*>& items) : index(0) {
    for (CaseComponent* item : items) {
        if (dynamic_cast<Task*>(item) != nullptr) {
            list.push_back(item);
        }
    }    
}

CaseComponent* TaskOnlyIterator::first() {
    index = 0;
    return list.empty() ? nullptr : list[0];
}

CaseComponent* TaskOnlyIterator::next() {
    if(!hasNext()) {
        return nullptr;
    }
    return list[index++];
}

bool TaskOnlyIterator::hasNext() {
    return index < (size_t)list.size();
}


CaseComponent* TaskOnlyIterator::current() {
    return hasNext() ? list[index] : nullptr;
}