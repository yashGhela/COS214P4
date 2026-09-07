#include "ChronologicalIterator.h"
#include "CaseComponent.h"


ChronologicalIterator::ChronologicalIterator(const std::vector<CaseComponent*>& items) : list(items), index(0) {}



CaseComponent* ChronologicalIterator::first() {
    index = 0;
    return current();
}

CaseComponent* ChronologicalIterator::next() {
    index++;
    return current();
}

bool ChronologicalIterator::hasNext() {
    return index < list.size();
}

CaseComponent* ChronologicalIterator::current() {
    return hasNext() ? list[index] : nullptr;
}
