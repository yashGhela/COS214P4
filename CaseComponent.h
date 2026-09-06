#ifndef CASECOMPONENT_H
#define CASECOMPONENT_H

#include <string>

class CaseComponent {
    public:
        CaseComponent() = default;
        virtual ~CaseComponent() = default;
        virtual void add(CaseComponent*) {};
        virtual void remove(CaseComponent*) {};
        virtual void assign() = 0;
        virtual void start() = 0;
        virtual void hold() = 0;
        virtual void complete() = 0;
        virtual std::string getStatus() = 0;
        virtual std::string getName() const = 0;
        virtual int getPriority() const = 0;
};

#endif