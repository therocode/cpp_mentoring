/*
7. Conclusion & assignment

While we haven't covered everything C++ filestreams have to offer, you should by now have a strong
knowledge of how they work and how to use them. Remember that there is always cppreference if you do not 
remember the name or signature of a function, or what it does exactly. 

There is a small assignment connected to this lesson. You will get a file with some data, and read it into an
array of the following struct:
*/

#include <string>

struct StudentInfo {
    int age;
    std::string name;
    float grade_pct;
};

// The file starts with the number of students and might look like this:
/*
2
22 Jeff 70.8
19 Arthur 88.4
*/

// Once that is done, you create a new file in which you output the students sorted by grade.
// To sort the students, use the function below:

#include <algorithm>

// begin is a pointer to the first element, end is a pointer to the element past the last one
void sort_students(StudentInfo* begin, StudentInfo* end) {
    std::sort(begin, end, [](StudentInfo const& a, StudentInfo const& b) {
        return a.grade_pct < b.grade_pct;
    });
}

int main() {

}