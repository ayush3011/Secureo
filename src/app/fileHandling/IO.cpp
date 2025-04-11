// IO.cpp - Implementation file for the IO class, handling file opening and closing.

#include <iostream> // Standard I/O operations
#include "IO.hpp"   // Including the header file for IO class
#include <fstream>  // File handling operations
using namespace std;

// Constructor: Opens the given file in binary mode for reading and writing.
IO::IO(const string &file_path)
{
    file_stream.open(file_path, ios::in | ios::out | ios::binary);

    // Check if the file stream failed to open.
    if (!file_stream.is_open())
    {
        cout << "Unable to open the file: " << file_path << endl;
    }
}

// Function to return the file stream object to the caller.
fstream IO::getFileStream()
{
    return move(file_stream); // Moving the file stream to avoid unnecessary copies.
}

// Destructor: Ensures the file is closed when the object is destroyed.
IO::~IO()
{
    if (file_stream.is_open()) // Check if the file is open before closing.
    {
        file_stream.close();
    }
}
