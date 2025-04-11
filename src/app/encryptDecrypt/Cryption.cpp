// Cryption.cpp - Implements the executeCryption function to perform encryption or decryption.

#include "Cryption.hpp"                // Declaration of executeCryption
#include "../processes/Task.hpp"       // Task structure and Action enum
#include "../fileHandling/ReadEnv.cpp" // Reads key from .env file
using namespace std;

// Executes encryption or decryption based on task data
int executeCryption(const string &taskData)
{
    // Deserialize the string into a Task object
    Task task = Task::fromString(taskData);

    // Create a ReadEnv object to fetch the key from .env
    ReadEnv env;
    string envKey = env.getenv(); // Example: "3" (encryption/decryption shift key)

    // Convert the string key into integer
    int key = stoi(envKey);

    if (task.action == Action::ENCRYPT)
    {
        char ch;
        // Read and encrypt each character in the file
        while (task.f_stream.get(ch))
        {
            ch = (ch + key) % 256;             // Apply Caesar cipher shift
            task.f_stream.seekp(-1, ios::cur); // Move put pointer back to overwrite the character
            task.f_stream.put(ch);             // Write encrypted character
        }
        task.f_stream.close(); // Close the stream after processing
    }
    else // DECRYPT
    {
        char ch;
        // Read and decrypt each character in the file
        while (task.f_stream.get(ch))
        {
            ch = (ch - key + 256) % 256;       // Reverse Caesar cipher shift (modulo 256)
            task.f_stream.seekp(-1, ios::cur); // Move put pointer back to overwrite the character
            task.f_stream.put(ch);             // Write decrypted character
        }
        task.f_stream.close(); // Close the stream after processing
    }

    return 0; // Indicate successful completion
}