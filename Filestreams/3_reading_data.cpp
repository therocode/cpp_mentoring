/*
3. Reading data from a file stream
*/

// Now that we know how to open and close a stream, let's get started by reading some data!

#include <fstream>
#include <string>

#include <cassert> // For assert()

void reading_data() {
    // Note that when using ifstream, you don't have to specify the fstream::in flag. 
    std::ifstream file("example_files/data.txt");

    /* 
    Reading data from a file is very similar to reading data from std::cin. You simply use the 
    overloaded operator >>

    */

    std::string str;
    file >> str; // Read into 'str' until the first whitespace. This is the same behaviour as std::cin has

    // If we take a look at our example file, we can see that str should contain "Hello"
    assert(str == "Hello");

    // If we want to read a full line into a string, we have to use std::getline()
    str = ""; // getline() should clear the string, but I added this for clarity.
    std::getline(file, str);

    /* When reading from the file earlier, the file pointer (a marker that indicates our current 
    position in the file) has moved forward to the second line. Reading one full line from that position
    gives us the following result.
    */
    assert(str == "This is a file!");

    // Of course, you can read data into more things than just strings. For example:
    int n;
    file >> n;
    
    assert(n == 123);

    // Or a float:
    float pi;
    file >> pi;
    assert(pi == 3.14159);

} //file is closed here

// As you can see, reading data from a file is very similar to using std::cin for input.

int main() {
    reading_data();
}