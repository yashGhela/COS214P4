#ifndef HIGHPRIORITYITERATOR_H
#define HIGHPRIORITYITERATOR_H
#include <vector>
#include "CaseIterator.h"
#include "CaseComponent.h"

class CaseComponent;

class HighPriorityIterator : public CaseIterator {
    private:
        std::vector<CaseComponent*> HighPrioritylist;
        size_t index;
    public:
        HighPriorityIterator(std::vector<CaseComponent*>& items);
        CaseComponent* first() override;
        CaseComponent* next() override;
        bool hasNext() override;
        CaseComponent* current() override;
    
};

#endif