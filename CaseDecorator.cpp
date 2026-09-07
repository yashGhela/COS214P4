#include "CaseDecorator.h"

CaseDecorator::CaseDecorator(CaseComponent* c) : component(c) {}

CaseDecorator::~CaseDecorator() {
    delete component;
}

void CaseDecorator::add(CaseComponent* c) {
    component->add(c);
}

void CaseDecorator::remove(CaseComponent* c) {
    component->remove(c);
}

void CaseDecorator::assign() {
    component->assign();
}

void CaseDecorator::start() {
    component->start();
}

void CaseDecorator::hold() {
    component->hold();
}

void CaseDecorator::complete() {
    component->complete();
}

std::string CaseDecorator::getStatus(int level) {
    return component->getStatus(level);
}

std::string CaseDecorator::getStatus() {
    return component->getStatus();
}

int CaseDecorator::getPriority() const {
    return component->getPriority();
}

std::string CaseDecorator::getName() const {
    return component->getName();
}