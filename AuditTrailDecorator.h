#pragma once
#include "CaseDecorator.h"
#include <vector>
#include <string>
#include "CaseComponent.h"


class AuditTrailDecorator: public CaseDecorator{
    private:
    std::vector<std::string> auditLog;
    bool auditEnabled;

    public:
    AuditTrailDecorator(std::vector<std::string> al, CaseComponent* c);
    void enableAudit();
    void assign();

    ~AuditTrailDecorator(){};
     
};