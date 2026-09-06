#include <iostream>
#include <string>
#include <vector>
#include "Phase.h"
#include "Task.h"
#include "ChronologicalIterator.h"
#include "TaskOnlyIterator.h"
#include "HighPriorityIterator.h"

using namespace std;

// Helper function to print a separator
void printSeparator(const string& title) {
    cout << "\n========== " << title << " ==========" << endl;
}

// Helper function to print all items using any iterator
void printAllItems(CaseIterator* iter, const string& label) {
    cout << "\n--- " << label << " ---" << endl;
    int count = 0;
    
    // Use first() to reset
    CaseComponent* comp = iter->first();
    
    while (comp != nullptr) {
        count++;
        cout << count << ". " << comp->getName();
        
        // Show priority if available
        cout << " (Priority: " << comp->getPriority() << ")";
        
        // Show status
        cout << " [Status: " << comp->getStatus() << "]";
        cout << endl;
        
        comp = iter->next();
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
    
    // ============================================================
    // 1. BUILD THE HIERARCHY
    // ============================================================
    printSeparator("Building Project Hierarchy");
    
    // Create root Phase (Project)
    Phase* project = new Phase("Fraud Investigation Project");
    cout << "Created: " << project->getName() << endl;
    
    // Create sub-phases
    Phase* phase1 = new Phase("Phase 1: Initial Review");
    Phase* phase2 = new Phase("Phase 2: Investigation");
    Phase* phase3 = new Phase("Phase 3: Resolution");
    
    cout << "Created: " << phase1->getName() << endl;
    cout << "Created: " << phase2->getName() << endl;
    cout << "Created: " << phase3->getName() << endl;
    
    // Add phases to project
    project->add(phase1);
    project->add(phase2);
    project->add(phase3);
    
    // Create tasks for Phase 1
    Task* task1 = new Task(1, "Review case files", 3);
    Task* task2 = new Task(2, "Interview client", 4);
    phase1->add(task1);
    phase1->add(task2);
    
    // Create tasks for Phase 2
    Task* task3 = new Task(3, "Gather evidence", 7);
    Task* task4 = new Task(4, "Interview witnesses", 6);
    Task* task5 = new Task(5, "Analyze financial records", 9);
    phase2->add(task3);
    phase2->add(task4);
    phase2->add(task5);
    
    // Create tasks for Phase 3
    Task* task6 = new Task(6, "Write final report", 5);
    Task* task7 = new Task(7, "Submit to legal team", 8);
    phase3->add(task6);
    phase3->add(task7);
    
    // Additional task directly in project (unlikely in real case, but good for testing)
    Task* task8 = new Task(8, "Initial case assessment", 2);
    project->add(task8);
    
    cout << "\nHierarchy built successfully!" << endl;
    cout << "Root: " << project->getName() << endl;
    cout << "  - Contains " << phase1->getName() << endl;
    cout << "  - Contains " << phase2->getName() << endl;
    cout << "  - Contains " << phase3->getName() << endl;
    cout << "  - Contains " << task8->getName() << endl;
    
    // ============================================================
    // 2. TEST CHRONOLOGICAL ITERATOR
    // ============================================================
    printSeparator("Chronological Iterator Test");
    
    CaseIterator* chronoIter = project->createChronologicalIterator();
    printAllItems(chronoIter, "Chronological Order (Depth-First)");
    
    // Test hasNext() with while loop
    cout << "\n--- Testing hasNext() with while loop ---" << endl;
    chronoIter->first();
    int i = 0;
    while (chronoIter->hasNext()) {
        CaseComponent* comp = chronoIter->next();
        cout << ++i << ". " << comp->getName() << endl;
    }
    
    delete chronoIter;
    
    // ============================================================
    // 3. TEST TASK-ONLY ITERATOR
    // ============================================================
    printSeparator("Task-Only Iterator Test");
    
    CaseIterator* taskIter = project->createTaskOnlyIterator();
    printAllItems(taskIter, "Task Only (Skipping Phases)");
    
    // Count tasks
    taskIter->first();
    int taskCount = 0;
    while (taskIter->hasNext()) {
        taskIter->next();
        taskCount++;
    }
    cout << "\nTotal Tasks in system: " << taskCount << endl;
    
    delete taskIter;
    
    // ============================================================
    // 4. TEST HIGH-PRIORITY ITERATOR
    // ============================================================
    printSeparator("High-Priority Iterator Test");
    
    CaseIterator* highIter = project->createHighPriorityIterator();
    printAllItems(highIter, "High Priority (Priority > 5)");
    delete project;
    delete highIter;
    
    // ============================================================
    // 5. TEST STATE TRANSITIONS
    // ============================================================
    printSeparator("State Pattern Test");
    
    cout << "\nTask: " << task3->getName() << endl;
    cout << "Initial Status: " << task3->getStatus() << endl;
    
    // Assign task
    cout << "Assigning task..." << endl;
    task3->assign();
    cout << "Status after assign: " << task3->getStatus() << endl;
    
    // Start task
    cout << "Starting task..." << endl;
    task3->start();
    cout << "Status after start: " << task3->getStatus() << endl;
    
    // Put on hold
    cout << "Putting task on hold..." << endl;
    task3->hold();
    cout << "Status after hold: " << task3->getStatus() << endl;
    
    // Resume
    cout << "Resuming task..." << endl;
    task3->start();
    cout << "Status after resume: " << task3->getStatus() << endl;
    
    // Complete
    cout << "Completing task..." << endl;
    task3->complete();
    cout << "Status after complete: " << task3->getStatus() << endl;
    
    // Test invalid transition
    cout << "\nTesting invalid transition..." << endl;
    cout << "Trying to start a completed task..." << endl;
    task3->start();  // Should show invalid transition error
    
    // ============================================================
    // 6. TEST DECORATOR PATTERN
    // ============================================================
    printSeparator("Decorator Pattern Test");
    
    // Create a task to decorate
    Task* baseTask = new Task(9, "Sensitive Investigation", 4);
    cout << "Base Task: " << baseTask->getName() << endl;
    cout << "Priority: " << baseTask->getPriority() << endl;
    
    // TODO: Add decorators here when implemented
    cout << "\n(Decorator tests will be added when decorator classes are implemented)" << endl;
    cout << "Expected: AuditTrailDecorator + HighPriorityDecorator stacking" << endl;
    
    delete baseTask;
    
    // ============================================================
    // 7. TEST OWNERSHIP AND CLEANUP
    // ============================================================
    printSeparator("Cleanup");
    
    cout << "Deleting entire hierarchy..." << endl;
    delete project;
    
    cout << "\n=========================================" << endl;
    cout << "    ALL TESTS COMPLETED SUCCESSFULLY" << endl;
    cout << "=========================================\n" << endl;
    
    return 0;
}