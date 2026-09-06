#ifndef ASSIGNINGSTATE_H
#define ASSIGNINGSTATE_H

#include "TaskState.h"
#include "Task.h"
#include "InProgressState.h"

class AssigningState : public TaskState {
    public:
        void start(Task* t) override;
        std::string getName() const override;
};

#endif