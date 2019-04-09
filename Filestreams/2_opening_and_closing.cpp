/*
2. Opening and closing a stream

In this part of the lesson, we will be talking about how to open and close a file stream. 
To start, let's include the filestream header:
*/

#include <fstream>

/*
There are two main ways to open a file stream. The first is by using the constructor, the second is by calling
the .open() method on a filestream. Let's take a look at both
*/

void open_filestream() {
    // Using constructor
    std::fstream file("path_to_file.txt");

    // Using the .open() method
    std::fstream file2;
    file2.open("path_to-file.txt");

    /*
    As you can see, the open() method is useful if you want to filestream constructed first and only opened after.
    */
}

/*
To close a filestream, there are also two main options: One is to call the .close() method, the other one is
to let the destructor do it's work.
*/

void close_filestream() {
    std::fstream file("path_to_file.txt");

    // Call the .close() method
    file.close();

    file.open("path_to_file.txt");
} // file goes out of scope here. The destructor for std::fstream is called and the file closes automatically

/*
The final topic in this part are file opening flags. You may have used a similar thing when working with the C 
FILE* way of working with files. In C++, you use enums to pass flags to the open() function (or the constructor).
*/

void file_flags() {
    // Opens the file as a binary file. 
    std::fstream file("path_to_file.txt", std::fstream::binary);

    /*
    There are a number of flags to choose from. Here is a list of all flags with their effects:
    (The namespace is omitted here for clarity)
    
    app     -   Seek to end of stream before each write
    binary  -   Open in binary mode
    in      -   Open file for reading
    out     -   Open file for writing
    trunc   -   Discard the contents of the stream when opening
    ate     -   Seek to the end of stream immediately after opening

    */

    // These flags can be combined using the binary 'or' operator |

    // Opens a file with both binary and app flags
    std::fstream file("path_to_file.txt", std::fstream::binary | std::fstream::app);

    // One common use for these flags is to clear a file easily:
    std::fstream file("path_to_file.txt", std::fstream::out); // Clears a file (if it exists)

    // Another trick is an easy way to test is a file exits by opening it with the fstream::in flag, but we will
    // get to this when we talk about error handling
}

int main() {
    open_filestream();
    close_filestream();
    file_flags();
}