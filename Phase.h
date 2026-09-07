#ifndef PHASE_H
#define PHASE_H

#include "CaseComponent.h"
#include "CaseIterator.h"
#include <vector>
#include <string>

class Phase  : public CaseComponent {
    private:
        std::string phaseName;
        std::vector<CaseComponent*> children;
    public:
        Phase(const std::string& name);
        ~Phase();
        void add(CaseComponent* );
        void remove(CaseComponent* );
        void assign() override;
        void start() override; 
        void hold() override;
        void complete() override;
        std::string getName() const override;
        int getPriority() const override;
        std::string getStatus() override;
        const std::vector<CaseComponent*>& getChildren() const;
        CaseIterator* createChronologicalIterator();
        CaseIterator* createHighPriorityIterator();
        CaseIterator* createTaskOnlyIterator();
};
#endif