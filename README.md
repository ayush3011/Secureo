# Secureo - Parallel File Encryption/Decryption System

Secureo is a robust C++17-based file encryption and decryption system designed for efficient parallel processing of multiple files. This system provides a secure and fast way to encrypt or decrypt entire directories and their subdirectories simultaneously, making it ideal for bulk file operations.

## Key Features

- **Parallel Processing**: Leverages multi-threading to process multiple files simultaneously, significantly reducing processing time for large directories
- **Recursive Directory Handling**: Automatically processes all files within a directory and its subdirectories
- **Intelligent File Filtering**: Automatically excludes system files, executables, and source code files from processing
- **Robust Error Handling**: Comprehensive error handling for filesystem operations and file access
- **Environment Configuration**: Supports flexible configuration through .env file
- **Cross-Platform Compatibility**: Works on Windows, Linux, and macOS systems

## Technical Details

- Built with C++17 standard
- Utilizes modern C++ features and the filesystem library
- Implements parallel processing for optimal performance
- Includes comprehensive error handling and logging
- Modular architecture for easy maintenance and extension

## Project Structure
Secureo/
├── main.cpp # Main program entry point
├── src/
│ ├── app/
│ │ ├── fileHandling/ # File I/O operations
│ │ ├── encryptDecrypt/ # Encryption/decryption logic
│ │ └── processes/ # Parallel processing management
├── .env # Environment configuration
└── README.md # Project documentation


## Security Features

- Automatic exclusion of sensitive system files
- Protection of source code files (.cpp, .hpp)
- Secure handling of environment variables
- Built-in safeguards against processing critical system files

## Getting Started

1. Ensure you have a C++17 compatible compiler installed
2. Clone the repository
3. Build the project using the provided build command
4. Run the executable and follow the interactive prompts

## Contributing

We welcome contributions! Please feel free to submit issues and pull requests.

