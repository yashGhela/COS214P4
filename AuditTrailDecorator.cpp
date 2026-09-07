#include "AuditTrailDecorator.h"
#include "CaseComponent.h"


AuditTrailDecorator::AuditTrailDecorator(std::vector<std::string> al, CaseComponent* c): CaseDecorator(c){
    auditEnabled=false;
    auditLog=al; 
}

void AuditTrailDecorator::enableAudit(){
    auditEnabled=true;
}

void AuditTrailDecorator::assign(){

}



