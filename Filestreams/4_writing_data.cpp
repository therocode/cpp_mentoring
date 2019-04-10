/*
4. Writing data to a file stream
*/

// We just saw how easy reading data was, and luckily writing data is not much harder!

#include <fstream>
#include <cassert> // For assert()

void writing_data() {
    // Again, when creating an object of type std::ofstream, you don't have to specify the out flag.
    // Note that if this file doesn't exist, it will create a new (empty) file, and if it does the file 
    // will be cleared.
    std::ofstream file("example_files/output.txt");

    // Writing to a file is exactly the same as using std::cout. You use the overloaded operator <<

    file << "This is some output text" << "\n"; //Just like with std::cout, fstream::operator<< can be chained
    file << 456 << std::endl; // std::endl also works for filestreams
    file << 2.16;

} // As we know already, the file is closed here

// And that's all you have to do to write to a file!

void main() {
    writing_data();
}