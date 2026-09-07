#pragma once
#include "CaseComponent.h"


class CaseDecorator : public CaseComponent {
    protected:
        CaseComponent* component;

    public:
        CaseDecorator(CaseComponent* c);
        void add(CaseComponent* c) override;
        void remove(CaseComponent* c) override;
        void assign() override;
        void start() override;
        void hold() override;
        void complete() override;
        int getPriority() const;
        std::string getName() const;
        std::string getStatus() override;
        std::string getStatus(int level) override;
        ~CaseDecorator();

};