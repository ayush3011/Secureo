// Cryption.hpp - Header file for the encryption/decryption execution function.

#ifndef CRYPTION_HPP
#define CRYPTION_HPP

#include <string>
using namespace std;

// Executes encryption or decryption based on the provided serialized task data.
// The taskData is expected to be in the format: "filePath,ENCRYPT" or "filePath,DECRYPT"
// Returns 0 on success, or a non-zero error code on failure.
int executeCryption(const string &taskData);

#endif // CRYPTION_HPP
