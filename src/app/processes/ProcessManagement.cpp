// processManagement.cpp - Implementation of the ProcessManagement class.

#include "ProcessManagement.hpp" // Include the class definition
#include <iostream>              // For console output
#include <cstring>               // For C-style string operations (not used here directly)
// #include <sys/wait.h>            // For process management using wait (currently not used)
#include "../encryptDecrypt/Cryption.hpp" // Include encryption/decryption logic

// Default constructor - No special initialization required here.
ProcessManagement::ProcessManagement() {}

// Adds a Task to the task queue by transferring ownership via unique_ptr.
bool ProcessManagement::submitToQueue(unique_ptr<Task> task)
{
    taskQueue.push(move(task)); // Move the task into the queue
    return true;                // Indicate successful submission
}

// Executes all tasks in the queue.
void ProcessManagement::executeTasks()
{
    while (!taskQueue.empty())
    {
        // Move the front task from the queue to a local unique_ptr
        unique_ptr<Task> taskToExecute = move(taskQueue.front()); // FIXED: changed from frontO() to front()
        taskQueue.pop();                                          // Remove the task from the queue

        // Print the task's description before execution
        cout << "Executing task: " << taskToExecute->toString() << endl;

        // Execute the encryption or decryption logic using the task's parameters
        executeCryption(taskToExecute->toString());
    }
}
