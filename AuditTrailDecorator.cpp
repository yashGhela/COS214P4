#include "AuditTrailDecorator.h"
#include "CaseComponent.h"
#include "CaseDecorator.h"

AuditTrailDecorator::AuditTrailDecorator(CaseComponent* c, bool enabled): CaseDecorator(c), auditEnabled(enabled) {}

void AuditTrailDecorator::enableAudit(bool enabled){
    auditEnabled=enabled;
}

const std::vector<std::string>& AuditTrailDecorator::getAuditLog() const {
    return auditLog;
}



void AuditTrailDecorator::assign(){
    std::string before = component->getStatus();
    component->assign();
    if (auditEnabled) {
        std::string after = component->getStatus();
        auditLog.push_back("assign: " + before + " -> " + after);
    }
}

void AuditTrailDecorator::start(){
    std::string before = component->getStatus();
    component->start();
    if (auditEnabled) {
        std::string after = component->getStatus();
        auditLog.push_back("start: " + before + " -> " + after);
    }
}

void AuditTrailDecorator::hold(){
    std::string before = component->getStatus();
    component->hold();
    if (auditEnabled) {
        std::string after = component->getStatus();
        auditLog.push_back("hold: " + before + " -> " + after);
    }
}

void AuditTrailDecorator::complete(){
    std::string before = component->getStatus();
    component->complete();
    if (auditEnabled) {
        std::string after = component->getStatus();
        auditLog.push_back("complete: " + before + " -> " + after);
    }
}


std::string AuditTrailDecorator::getStatus() {
    return component->getStatus();
}



