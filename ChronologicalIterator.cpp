#include "ChronologicalIterator.h"
#include "CaseComponent.h"


ChronologicalIterator::ChronologicalIterator(const std::vector<CaseComponent*>& items) : list(items), index(0) {}



CaseComponent* ChronologicalIterator::first() {
    index = 0;
    return list.empty() ? nullptr : list[0];
}

CaseComponent* ChronologicalIterator::next() {
    if(!hasNext()) {
        return nullptr;
    }
    return list[index++];
}

bool ChronologicalIterator::hasNext() {
    return index < (size_t)list.size();
}

CaseComponent* ChronologicalIterator::current() {
    return hasNext() ? list[index] : nullptr;
}
