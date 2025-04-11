// Task.hpp - Defines the Task structure and its behavior for encryption/decryption tasks.

#ifndef TASK_HPP
#define TASK_HPP

#include <string>                 // For std::string
#include <iostream>               // For console I/O operations
#include <sstream>                // For stringstream and ostringstream
#include "../fileHandling/IO.hpp" // For file stream management

using namespace std;

// Enum to specify the type of action: encryption or decryption.
enum class Action
{
    ENCRYPT,
    DECRYPT
};

// Task struct holds all necessary data to process an encryption/decryption operation.
struct Task
{
    string filePath;  // Path to the file to be processed
    fstream f_stream; // File stream to access file data
    Action action;    // Type of action to perform (ENCRYPT/DECRYPT)

    // Constructor: Initializes a task with a file stream, action, and file path.
    Task(fstream &&stream, Action act, string filePath)
        : f_stream(move(stream)), action(act), filePath(filePath) {}

    // Serialize the task into a string format (for inter-process communication or logging).
    string toString()
    {
        ostringstream oss;
        oss << filePath << "," << (action == Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
        // Example: test.txt,ENCRYPT
        return oss.str();
    }

    // Deserialize a task from a string.
    static Task fromString(const string &taskData)
    {
        stringstream iss(taskData); // Used to split the input string
        string filePath;
        string actionStr;

        // Extract the filePath and action string from the comma-separated input
        if (getline(iss, filePath, ',') && getline(iss, actionStr))
        {
            // Convert action string to Action enum
            Action action = (actionStr == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);

            // Use IO class to get file stream from file path
            IO io(filePath);
            fstream f_stream = move(io.getFileStream());

            // Check if file was opened successfully
            if (f_stream.is_open())
            {
                return Task(move(f_stream), action, filePath);
            }
            else
            {
                throw runtime_error("Failed to open file: " + filePath);
            }
        }
        else
        {
            throw runtime_error("Invalid task data format");
        }
    }
};

#endif // TASK_HPP
