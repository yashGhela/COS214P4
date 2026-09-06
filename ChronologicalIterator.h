#ifndef CHRONOLOGICALITERATOR_H
#define CHRONOLOGICALITERATOR_H
#include "CaseIterator.h"
#include "CaseComponent.h"
#include <vector>

class ChronologicalIterator : public CaseIterator {
    private:
        std::vector<CaseComponent*> list;
        size_t index;
    public:
        ChronologicalIterator(const std::vector<CaseComponent*>& items);
        ~ChronologicalIterator() = default;
        CaseComponent* first() override;
        CaseComponent* next() override;
        bool hasNext() override;
        CaseComponent* current() override;
};

#endif