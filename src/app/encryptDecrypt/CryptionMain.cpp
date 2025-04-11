// CryptionMain.cpp - Entry point for invoking the Cryption logic from the command line

#include <iostream>     // For standard I/O operations
#include "Cryption.hpp" // For the executeCryption function

using namespace std;

int main(int argc, char *argv[])
{
    // Expect exactly one command line argument: the task data string
    if (argc != 2)
    {
        cerr << "Usage: ./cryption <task_data>" << endl; // Inform user of correct usage
        return 1;                                        // Return non-zero exit code to indicate error
    }

    // Call the encryption/decryption function using the input argument
    executeCryption(argv[1]);

    return 0; // Indicate successful completion
}
