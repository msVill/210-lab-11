// comsc 210 | Martha Stephanie Villalta | Lab 11

#include <iostream>
using namespace std;

// -> use struct
//.  -> the struct definition will include a dynamic array (+ other members).
// -> dynamic array of structs.
// Before I begin: I want to make sure I follow my plan correctly:
//  --> I want to create an assignment tracker because my current system is not working:
// --> I need to know the number of assignments due for each class , 
// and maybe I need to let the program know HOW many classes to track.
// --> I want to output the class names, and the number of assignments due.

struct Course {
    string courseName;
    int numAssignments;
    int completed;
    bool* assignments; // this is the dynamic array in struct definition.
};

int main() {
    int numCourses; // variable to hold the number of courses we want to track

    // I want the user to enter the number of courses they want to track.
    cout << "How many courses do you want to track: ";
    cin >> numCourses;

    // Okay, what do I want to do now?... I need to dynamically allocate array of Course structs
    Course* courses = new Course[numCourses];

    // I want to be able to get the user data for name of courses and store it
    for(int i = 0; i < numCourses; i++) {
        cout << "Enter name for course #" << i + 1 << "; ";
        cin >> courses[i].courseName;

    // this one needs to tell me how many assignments I have for the courses.
    cout << "Enter number of assignments: ";
    cin >> courses[i].numAssignments;

    // Okay, now I think I need to actually allocate memory for the assignments array
    // each course has a different number of assignments.
    courses[i].assignments = new bool[courses[i].numAssignments];
    }

    // I want to free memory for ach course's assignment array.
for(int i = 0; i < numCourses; i++) {
    delete[] courses[i].assignments;
    //almost forgot that it's within main().
}

    delete[] courses; // 
    return 0;
}

// output of info will be handled here: