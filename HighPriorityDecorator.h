#pragma once 
#include "CaseDecorator.h"
#include "CaseComponent.h"

class HighPriorityDecorator: public CaseDecorator{
    private:
    int priorityLevel;

    public:
    HighPriorityDecorator(int pl, CaseComponent* c);
    void setPriorityLevel(int pl);
    ~HighPriorityDecorator(){};
};