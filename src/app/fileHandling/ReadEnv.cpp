#include <iostream> // Standard input/output operations
#include <string>   // Handling string operations
#include <fstream>  // File handling operations
#include "IO.hpp"   // Including the IO class
#include <sstream>  // String stream for reading file content
using namespace std;

// ReadEnv class is responsible for reading environment variables from a .env file.
class ReadEnv
{
public:
    // Function to read the content of the .env file and return it as a string.
    string getenv()
    {
        string env_path = ".env"; // The environment file path

        IO io(env_path);                       // Create an instance of the IO class to handle file operations
        fstream f_stream = io.getFileStream(); // Get the file stream object

        stringstream buffer;        // String stream to store file content
        buffer << f_stream.rdbuf(); // Read the entire file content into buffer

        string content = buffer.str(); // Convert buffer content to string
        return content;                // Return the file content
    }
};
