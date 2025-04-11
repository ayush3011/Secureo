// processManagement.hpp - Header for the ProcessManagement class, handling task queuing and execution.

#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp" // Include the Task class definition
#include <queue>    // For using std::queue to manage tasks
#include <memory>   // For using std::unique_ptr

// ProcessManagement handles queuing of tasks and their execution.
class ProcessManagement
{

public:
    // Constructor: Initializes any required structures (default constructor used here).
    ProcessManagement();

    // Submits a task to the internal queue. Returns true if successful.
    bool submitToQueue(unique_ptr<Task> task);

    // Executes all tasks currently in the queue.
    void executeTasks();

private:
    // A queue to hold unique pointers to Task objects.
    queue<unique_ptr<Task>> taskQueue;
};

#endif // PROCESS_MANAGEMENT_HPP
