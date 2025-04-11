// g++ -std=c++17 -o Secureo.exe main.cpp src/app/fileHandling/IO.cpp src/app/fileHandling/ReadEnv.cpp src/app/encryptDecrypt/Cryption.cpp src/app/processes/ProcessManagement.cpp -Isrc/app/fileHandling -Isrc/app/encryptDecrypt -Isrc/app/processes

// main.cpp - Entry point for the parallel file encryptor/decryptor system
// This program takes a directory path and an action (ENCRYPT or DECRYPT) from the user,
// and applies the specified action to all regular files in the directory recursively.

#include <iostream>                                // For console input/output
#include <filesystem>                              // For traversing directories and files
#include "./src/app/processes/ProcessManagement.hpp" // Handles task queue and processing
#include "./src/app/processes/Task.hpp"            // Defines Task struct and Action enum

namespace fs = std::filesystem;
using namespace std;

int main(int argc, char *argv[])
{
    string directory; // Directory path input from user
    string action;    // Action input from user (ENCRYPT or DECRYPT)

    // Prompt and read directory path
    cout << "Enter the directory path: " << endl;
    getline(cin, directory);

    // Prompt and read action to perform
    cout << "Enter action (ENCRYPT or DECRYPT): " << endl;
    getline(cin, action);

    try
    {
        // Check if the directory exists and is valid
        if (fs::exists(directory) && fs::is_directory(directory))
        {
            // Create an instance to manage and execute tasks
            ProcessManagement processManagement;

            // Traverse the directory and its subdirectories
            for (const auto &entry : fs::recursive_directory_iterator(directory))
            {
                // Process only regular files (skip directories, symlinks, etc.)
                if (entry.is_regular_file())
                {
                    string filePath = entry.path().string(); // Full path to file

                    // ✅ Add this exclusion check
                    if (entry.path().filename() == ".env" ||
                        entry.path().filename() == "Secureo.exe" ||
                        entry.path().extension() == ".cpp" ||
                        entry.path().extension() == ".hpp")
                    {
                        continue; // Skip .env, the executable, and source files
                    }

                    IO io(filePath);                             // Initialize IO wrapper for file handling
                    fstream f_stream = move(io.getFileStream()); // Get file stream

                    // Proceed only if the file stream opened successfully
                    if (f_stream.is_open())
                    {
                        // Convert user input to corresponding Action enum value
                        Action taskAction = (action == "ENCRYPT" ? Action::ENCRYPT : Action::DECRYPT);

                        // Create a new Task and add it to the task queue
                        auto task = make_unique<Task>(move(f_stream), taskAction, filePath);
                        processManagement.submitToQueue(move(task));
                    }
                    else
                    {
                        // Inform if a file could not be opened
                        cout << "Unable to open the file: " << filePath << endl;
                    }
                }
            }

            // Execute all queued encryption/decryption tasks
            processManagement.executeTasks();
        }
        else
        {
            // Inform if the path is invalid or not a directory
            cout << "Invalid directory path." << endl;
        }
    }
    catch (const fs::filesystem_error &ex)
    {
        // Handle and report any filesystem-related errors
        cout << "Filesystem error: " << ex.what() << endl;
    }

    return 0; // Exit the program
}