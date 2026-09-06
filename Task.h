#ifndef TASK_H
#define TASK_H
#include "CaseComponent.h"
#include "TaskState.h"
#include "AssigningState.h"
#include <string>

class Task : public CaseComponent {
    private:
        TaskState* state;
        int taskID;
        std::string taskName;
        int priority;
        
    public:
        Task(int id, const std::string& name, int priority);
        ~Task();
        void setState(TaskState* newState);
        void assign() override;
        void start() override;
        void hold() override;
        void complete() override;
        int getId() const;
        std::string getName() const override;
        int getPriority() const override;
        std::string getStatus() override;
};

#endif