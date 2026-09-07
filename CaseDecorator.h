#pragma once
#include "CaseComponent.h"


class CaseDecorator{
    private:
    CaseComponent* component;

    public:
    CaseDecorator(CaseComponent* c);
    void add(CaseComponent* c);
    void remove(CaseComponent* c);
    void assign();
    void start();
    void hold();
    void complete();
    std::string getStatus();
    ~CaseDecorator();

};