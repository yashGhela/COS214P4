#pragma once
#include "CaseDecorator.h"
#include "string"
#include "CaseComponent.h"

class ConfidentialityDecorator: public CaseDecorator{
    private:
    int clearanceLevel;

    public:
    ConfidentialityDecorator(int cl, CaseComponent* c);
    void setClearance(int l);
    std::string getStatus() override;
    std::string getStatus(int level) override;
    ~ConfidentialityDecorator(){};
};