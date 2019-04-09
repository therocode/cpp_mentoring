/*
6. Error handling

C++ filestreams have a somewhat complicated error handling system, so in this part we will only take a 
look at the basics.
*/

#include <fstream>

void error_check() {
    std::ofstream file("example_files/output.txt");
    
    // How do we know if the file is actually open? There are a few functions for this.
    // The most logical is file.is_open(). If we take a look at cppreference though, it becomes clear that
    // file.good() checks for all possible errors, while file.is_open() only checks whether it is open. It may
    // still be in an invalid state. That's why file.good() usually the best option.

    if (!file.good()) {
        // Log an error message or throw an exception.
    } else {
        // Use file, because we know it's safe to do so.
    }
}

// A nice application of this error handling system is a function that checks whether a file exists or not
bool file_exists(const char* fname) {
    // When trying to open a file with std::ifstream and the file doesn't exist, an internal error state is set.
    // We can test for this error by calling file.good()
    std::ifstream file(fname);

    // Same as if (file.good()) return true; else return false;
    return file.good();
}

#include <iostream>

int main() {
    error_check();
    if (file_exists("virus.exe")) {
        std::cout << "Emergency alert: Virus detected!";
    } else {
        std::cout << "Everything is safe";
    }
}