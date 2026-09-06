#include "HighPriorityIterator.h"
#include "CaseComponent.h"


HighPriorityIterator::HighPriorityIterator(std::vector<CaseComponent*>& items) : index(0) {
    HighPrioritylist = items;
    
    for (size_t i = 0; i < items.size(); ++i) {
        CaseComponent* key = items[i];
        int keyPriority = key->getPriority();
        int j = i - 1;

        while (j >= 0 && items[j]->getPriority() < keyPriority) {
            items[j + 1] = items[j];
            j--;
        }
        HighPrioritylist[j + 1] = key;
    }
}

CaseComponent* HighPriorityIterator::first() {
    index = 0;
    return HighPrioritylist.empty() ? nullptr : HighPrioritylist[0];
}

CaseComponent* HighPriorityIterator::next() {
    if (!hasNext()) {
        return nullptr;
    }
    return HighPrioritylist[index++];
}

bool HighPriorityIterator::hasNext() {
    return index < (size_t)HighPrioritylist.size();
}


CaseComponent* HighPriorityIterator::current() {
    return hasNext() ? HighPrioritylist[index] : nullptr;
}
