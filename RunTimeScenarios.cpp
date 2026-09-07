#include <iostream>
#include <string>
#include <vector>
#include "Phase.h"
#include "Task.h"
#include "ChronologicalIterator.h"
#include "TaskOnlyIterator.h"
#include "HighPriorityIterator.h"
#include "CaseDecorator.h"
#include "AuditTrailDecorator.h"
#include "ConfidentialityDecorator.h"

int RunTimeScenarios(){

    //Build of a software project
    Phase* project = new Phase("Software Project");
    Phase* planning = new Phase("Planning");
    Phase* development = new Phase("Development");
    Phase* testing = new Phase("Testing");

    Phase* requirements = new Phase("Requirements");
    Phase* backend = new Phase("Backend");

    Task* gatherReqs = new Task(1,"Gather requirements",0);
    Task* spec = new Task(2, "Write specifications",1);

    Task* api = new Task(3, "Implement API", 2);
    Task* db = new Task(4, "Implement Database", 3);

    requirements->add(gatherReqs);
    requirements->add(spec);

    backend->add(api);
    backend->add(db);

    planning->add(requirements);
    development->add(backend);

    project->add(planning);
    project->add(development);
    project->add(testing);


    //scenario 1 normal processing

    std::cout<<"SCENARIO 1"<<std::endl;

    CaseIterator* iterator = project->createChronologicalIterator();

    while(iterator->hasNext()){
        CaseComponent* comp = iterator->next();
        std::cout<< comp->getStatus() <<std::endl;
    }

    //attempt run time changes

    api->assign();
    api->start();

    api->setState(new InProgressState());

    api->complete();

    CaseComponent* decoratedapi = new AuditTrailDecorator(api, false);

    //stacking decs

    decoratedapi = new ConfidentialityDecorator(2,decoratedapi);

    decoratedapi->assign();
    decoratedapi->start();

    //runtime structural change
    development->remove(api);
    testing->add(api);


    CaseIterator* iterator2 =
    project->createChronologicalIterator();

    while (iterator2->hasNext())
    {
        CaseComponent* component = iterator2->next();

        std::cout << component->getStatus() << std::endl;
    }



    //scenario 2: High priority task processing 

    std::cout<<"SCENARIO 2"<<std::endl;

    CaseIterator* priority = project->createHighPriorityIterator();

    while (priority->hasNext())
    {
        CaseComponent* component = priority->next();

        std::cout << component->getStatus() << std::endl;
    }


    //cleanup

    while (priority->hasNext())
    {
        CaseComponent* component = priority->next();

        std::cout << component->getStatus() << std::endl;
    }




}