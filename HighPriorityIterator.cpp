#include "HighPriorityIterator.h"
#include "CaseComponent.h"


HighPriorityIterator::HighPriorityIterator(std::vector<CaseComponent*>& items) : index(0) {
    HighPrioritylist = items;

    for (size_t i = 1; i < HighPrioritylist.size(); ++i) {
        CaseComponent* key = HighPrioritylist[i];
        int keyPriority = key->getPriority();
        int j = i - 1;

        while (j >= 0 && HighPrioritylist[j]->getPriority() < keyPriority) {
            HighPrioritylist[j + 1] = HighPrioritylist[j];
            j--;
        }
        HighPrioritylist[j + 1] = key;
    }
}

CaseComponent* HighPriorityIterator::first() {
    index = 0;
    return current();
}

CaseComponent* HighPriorityIterator::next() {
    index++;
    return current();
}

bool HighPriorityIterator::hasNext() {
    return index < HighPrioritylist.size();
}


CaseComponent* HighPriorityIterator::current() {
    return hasNext() ? HighPrioritylist[index] : nullptr;
}
