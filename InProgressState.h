#ifndef INPROGRESSSTATE_H
#define INPROGRESSSTATE_H

#include "TaskState.h"
#include "Task.h"
#include "OnHoldState.h"
#include "CompletedState.h"

class InProgressState : public TaskState {
    public:
        void hold(Task* t) override;
        void complete(Task* t) override;
        std::string getName() const override;
};


#endif