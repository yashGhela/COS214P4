#ifndef TASKONLYITERATOR_H
#define TASKONLYITERATOR_H

#include "CaseIterator.h"
#include "CaseComponent.h"
#include "Task.h"
#include <vector>

class TaskOnlyIterator : public CaseIterator {
    private:
        std::vector<CaseComponent*> list;
        size_t index;
    public:
        TaskOnlyIterator(const std::vector<CaseComponent*>& items);
        ~TaskOnlyIterator() = default;
        CaseComponent* first() override;
        CaseComponent* next() override;
        bool hasNext() override;
        CaseComponent* current() override;
};

#endif