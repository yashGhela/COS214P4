#include "HighPriorityDecorator.h"
#include "CaseDecorator.h"
#include "CaseComponent.h"


HighPriorityDecorator::HighPriorityDecorator(int pl, CaseComponent* c): CaseDecorator(c){
    priorityLevel=pl;
}

void HighPriorityDecorator::setPriorityLevel(int pl){
    priorityLevel=pl;
}




