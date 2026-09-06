#ifndef ONHOLDSTATE_H
#define ONHOLDSTATE_H

#include "TaskState.h"
#include "Task.h"
#include "InProgressState.h"

class OnHoldState : public TaskState {
    public:
        void start(Task* t) override;
        std::string getName() const override;
};


#endif