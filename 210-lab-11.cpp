/* Comsc-210 | Lab #11 | Martha Villalta
Description: Write a program that features a simple dynamic array of structs. The 
struct definition should itself include a dynamic array as well as other member 
variables:------
I want to create a program that will keep track of how many assignments I have due
in each class for that week.
*/
#include <iostream>
#include <string>
using namespace std;

struct Course {
    string courseName; //Name of the course, e.g., "COMSC-210".
    int courseNum; //Course number.
    int assignNum; //Number of assignments.
    string* assignments; //Dynamic array of assignment names.

    ~Course() { //Destructor to free dynamic array.
        if (assignments) {
            delete[] assignments;
            assignments = nullptr;
        }
    }
};

//Function prototypes
void inputCourse(Course* c);
void displayCourse(Course* c);

int main() {

    int numClasses;
    cout << "Enter number of classes: ";
    cin >> numClasses;
    cin.ignore(); //Clear lefotver newline

    //Dynamic array of Course struct.
    Course* courses = new Course[numClasses];

    //Input data for each class.
    for(int i = 0; i < numClasses; i++) {
        cout << "\nEnter info for class #" << (i + 1) << ":\n";
        inputCourse(&courses[i]); //pass the pointer to each struct.
    }

    //Display all classes.
    cout <<"\n===== Class Iformation =====\n";

    for(int i = 0; i < numClasses; i++) {
        displayCourse(&courses[i]);
    }

    delete[] courses;

    return 0;
}

//Function to inout a single course.
void inputCourse(Course* c) {
    cout << "Enter class name: ";
    getline(cin, c->courseName);

    cout << "Enter class number: ";
    cin >> c->courseNum;

    cout << "Enter number of assignments: ";
    cin >> c->assignNum;
    cin.ignore(); //Clear new line.

    c->assignments = new string[c->assignNum];

    //Input assignment names.
    for(int i = 0; i < c->assignNum; i++) {
        cout << "Enter name of assignment " << (i + 1) << ": ";
        getline(cin, c->assignments[i]);
    }
}

//Function to displau a single course.
void displayCourse(Course* c){
    cout << "\nClass: " << c->courseName << " (" << c->courseNum << ")\n";
    cout <<"Assignments (" << c->assignNum << "):\n";

    for(int i = 0; i < c->assignNum; i++) {
        cout << "  - " << c->assignments[i] << "\n";
    }
}