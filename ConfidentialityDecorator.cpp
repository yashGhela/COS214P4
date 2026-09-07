#include "ConfidentialityDecorator.h"
#include "CaseComponent.h"


ConfidentialityDecorator::ConfidentialityDecorator(int cl, CaseComponent* c): CaseDecorator(c){

    clearanceLevel = cl;
}


void ConfidentialityDecorator::setClearance(int l){
    clearanceLevel=l;
}

std::string ConfidentialityDecorator::getStatus(){
    
}

