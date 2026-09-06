#ifndef TASKSTATE_H
#define TASKSTATE_H

#include <string>
#include <iostream>

class Task;

class TaskState{
    public:
        virtual ~TaskState() = default;
        virtual void assign(Task*);
        virtual void start(Task*);
        virtual void hold(Task*);
        virtual void complete(Task*);
        virtual std::string getName() const = 0;
        virtual bool isTerminal() const ;
    
    protected:
        void invalidTransition(Task*, const std::string& action);
};

#endif