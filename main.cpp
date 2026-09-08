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

using namespace std;

int RunTimeScenarios(); //function to test various runtime scenarios of ownership and state changes of tasks and phases

void printSeparator(const string& title) {
    cout << "\n========== " << title << " ==========" << endl;
}


void printAllItems(CaseIterator* iter, const string& label) {
    cout << "\n--- " << label << " ---" << endl;
    int count = 0;

    for (iter->first(); iter->hasNext(); iter->next()) {
        CaseComponent* comp = iter->current();
        count++;
        cout << count << ". " << comp->getName()
             << " (Priority: " << comp->getPriority() << ")"
             << " [Status: " << comp->getStatus() << "]" << endl;
    }

    if (count == 0) {
        cout << "  (No items found)" << endl;
    }
    cout << "Total items: " << count << endl;
}

int main() {
    cout << "\n=========================================" << endl;
    cout << "    TASKFORGE - Case Management System" << endl;
    cout << "=========================================" << endl;

    printSeparator("Building Project Hierarchy");

    Phase* project = new Phase("Fraud Investigation Project");
    Phase* phase1 = new Phase("Phase 1: Initial Review");
    Phase* phase2 = new Phase("Phase 2: Investigation");
    Phase* phase3 = new Phase("Phase 3: Resolution");

    project->add(phase1);
    project->add(phase2);
    project->add(phase3);

    Task* task1 = new Task(1, "Review case files", 3);
    Task* task2 = new Task(2, "Interview client", 4);
    phase1->add(task1);
    phase1->add(task2);

    Task* task3 = new Task(3, "Gather evidence", 7);
    Task* task4 = new Task(4, "Interview witnesses", 6);
    Task* task5 = new Task(5, "Analyze financial records", 9);
    phase2->add(task3);
    phase2->add(task4);
    phase2->add(task5);

    Task* task6 = new Task(6, "Write final report", 5);
    Task* task7 = new Task(7, "Submit to legal team", 8);
    phase3->add(task6);
    phase3->add(task7);

    Task* task8 = new Task(8, "Initial case assessment", 2);
    project->add(task8);

    cout << "\nHierarchy built successfully!" << endl;

    // ---- Chronological ----
    printSeparator("Chronological Iterator Test");
    CaseIterator* chronoIter = project->createChronologicalIterator();
    printAllItems(chronoIter, "Chronological Order");
    delete chronoIter;

    // ---- Task-only ----
    printSeparator("Task-Only Iterator Test");
    CaseIterator* taskIter = project->createTaskOnlyIterator();
    printAllItems(taskIter, "Task Only (direct children)");
    delete taskIter;

    // ---- High priority ----
    printSeparator("High-Priority Iterator Test");
    CaseIterator* highIter = project->createHighPriorityIterator();
    printAllItems(highIter, "Sorted by Priority (High to Low)");
    delete highIter;

    // ---- State pattern ----
    printSeparator("State Pattern Test");
    cout << "Task: " << task3->getName() << " | Initial: " << task3->getStatus() << endl;
    task3->assign();
    cout << "After assign: " << task3->getStatus() << endl;
    task3->start();
    cout << "After start: " << task3->getStatus() << endl;
    task3->hold();
    cout << "After hold: " << task3->getStatus() << endl;
    task3->start();
    cout << "After resume: " << task3->getStatus() << endl;
    task3->complete();
    cout << "After complete: " << task3->getStatus() << endl;
    cout << "Trying invalid transition (start on completed):" << endl;
    task3->start();

    // ---- Cleanup ----
    printSeparator("Cleanup");
    delete project;   // deletes phase1/2/3 and all tasks recursively

    // ============================================================
    // 6. TEST DECORATOR PATTERN
    // ============================================================
    printSeparator("Decorator Pattern Test");

    Task* baseTask = new Task(9, "Sensitive Investigation", 4);
    cout << "Base task: " << baseTask->getName()
     << " | Status: " << baseTask->getStatus() << endl;

    // Stack: AuditTrail wraps Confidentiality wraps the raw Task
    CaseComponent* decorated = new AuditTrailDecorator(
        new ConfidentialityDecorator(5, baseTask), true
    );

    cout << "\n--- Checking status with LOW clearance (2) ---" << endl;
    cout << "Status: " << decorated->getStatus(2) << endl;   // should print "Restricted"

    cout << "\n--- Checking status with SUFFICIENT clearance (7) ---" << endl;
    cout << "Status: " << decorated->getStatus(7) << endl;   // should print real status

    cout << "\n--- Performing lifecycle actions through the decorator ---" << endl;
    decorated->assign();
    decorated->start();
    decorated->complete();

    cout << "\n--- Audit log contents ---" << endl;
    AuditTrailDecorator* auditPtr = dynamic_cast<AuditTrailDecorator*>(decorated);
    if (auditPtr) {
        for (const string& entry : auditPtr->getAuditLog()) {
            cout << "  " << entry << endl;
        }
    }
    

    delete decorated;   // deletes ConfidentialityDecorator, which deletes baseTask

    printSeparator("Runtime Scenarios");
    RunTimeScenarios();

    cout << "\nALL TESTS COMPLETED\n" << endl;
    return 0;
}