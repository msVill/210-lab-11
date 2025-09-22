/* Comsc-210 | Lab #11 | Martha Villalta
I want to create a program that will keep track of how many assignments I have due
in each class for that week.
*/
#include <iostream>
using namespace std;

int numClasses;

struct Course {
    string courseName;
    int courseNum;
    int* assignments;

    ~Course() {
        if (assignments){
            delete [] assignments;
            assignments = nullptr;
        }
    }
};

void inputCourse(Course *);
void displayCourse(Course *);

int main() {
    cout << "Enter the number of classes you want to track: ";
    cin >> numClasses;

    Course* courses = new Course[numClasses];

    for(int i = 0; i < numClasses; i++) {
        inputCourse(&courses[i]);
    }

    for(int j = 0; j < numClasses; j++) {
        displayCourse(&courses[j]);
    }

    delete[] courses;

    return 0;
}

void inputCourse(Course* classPTR) {
}