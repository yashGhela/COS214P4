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
        AuditTrailDecorator(CaseComponent* c, bool enabled);
        const std::vector<std::string>& getAuditLog() const;
        void enableAudit(bool enabled);
        void assign() override;
        void start() override;
        void hold() override;
        void complete() override;
        std::string getStatus() override ;
        ~AuditTrailDecorator(){};
     
};