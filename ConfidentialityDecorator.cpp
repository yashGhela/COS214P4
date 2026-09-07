#include "ConfidentialityDecorator.h"
#include "CaseComponent.h"


ConfidentialityDecorator::ConfidentialityDecorator(int cl, CaseComponent* c): CaseDecorator(c){

    clearanceLevel = cl;
}


void ConfidentialityDecorator::setClearance(int l){
    clearanceLevel=l;
}

std::string ConfidentialityDecorator::getStatus(int level){
    if (level < clearanceLevel){
        return "Confidentiality Level too low";
    }
    else{
        return component->getStatus(level);
    }
}


std::string ConfidentialityDecorator::getStatus(){
    return "Restricted"; //default when no level is given.
}
