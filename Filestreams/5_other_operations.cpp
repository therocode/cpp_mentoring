/*
5. Other operations on file streams

In this part we will take a look at other things you can do with filestreams, apart from reading and writing data.
The thing from this lesson you will use the most is seeking to a position in the file. 
*/

#include <fstream>
#include <cassert>
#include <string>

void file_seeking() {
    // The tricky part of seeking in a file is that the function names are different for ifstream and ofstream.
    // This is because there are two different markers, one for input and one for output. When using std::ifstream
    // or std::ofstream this isn't very important, but watch out for this when using std::fstream (both input and
    // output). Let's first take a look at seeking in a std::ifstream.

    std::ifstream file("example_files/data.txt");

    // To get the current position of the file marker, we use the tellg() function.
    // pos_type is an integer type, the easiest alternative is int
    std::ifstream::pos_type pos = file.tellg(); // Or: int pos = file.tellg();

    // To move to a different position in the file, there is the seekg() function. 
    // This function has different versions. The first accepts just a position: 
    file.seekg(10); // Navigate to position '10'
    // The other version takes an offset and a 'seekdir'. A seekdir is one of end, beg or cur
    // The function then moves to a position with an offset relative to the seekdir specified.
    file.seekg(5, std::ios_base::beg); // Seeks 5 places from beginning of file.
    file.seekg(-3, std::ios_base::cur); // Seeks 3 places back from current position

    // For std::ofstream, seeking in a file is very similar. The only difference is that the functions are named
    // tellp() and seekp() instead.
}

void misc_operations() {

    // The first two functions only exist for std::ifstream (and std::fstream of course)
    std::ifstream file("example_files/data.txt");

    // Another thing you can do with std::ifstream is the peek() function. This function returns the next
    // character that will be read, but without removing it from the stream. This means that if we read some
    // data after calling peek(), that character will still be read. 

    char next = file.peek();
    assert(next == 'H'); // We're at the start of the file, so this should be the first character.

    // Now check if the peeked character is still there:
    std::string str;
    file >> str;
    assert(str == "Hello"); // The 'H' we have peeked is still in the stream.

    // A second function we will take a look at is ignore(). This function reads characters and ignores them
    // until it finds a given character:
    file.ignore(100, '!'); // Ignores up to 100 characters until an '!' is found.

    // The last function is only available for std::ofstream (and again also for std::fstream)
    std::ofstream ofile("example_files/output.txt");

    // The last operation that we'll discuss here is flush(). C++ streams are implemented using a buffering method.
    // When writing to a file the output is stored into a buffer, and every now and then that buffer is actually
    // written to the file. Writing the buffer to the file is what we call flushing. If you want to make absolutely
    // sure the data you just submitted is being written to the file, you can call flush().

    ofile << "Flush me please";
    ofile.flush();

    // Note that there are still a few more functions that we haven't looked at here. They are all listed at
    // https://en.cppreference.com/w/cpp/io/basic_fstream
}

int main() {
    file_seeking();
    misc_operations();
}