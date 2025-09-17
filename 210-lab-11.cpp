/* Comsc-210 | Lab #11 | Martha Villalta
I want to create a program that will keep track of how many assignments I have due
in each class for that week. It will have a const # of assignments & a const # for quizzes
*/
#include <iostream>
using namespace std;

const int NUM_PROJECTS = 5, NUM_QUIZZES = 3;

struct Course {
    string courseName;
    int courseNum;
    int* weekNum;

    ~Course() {
        if (weekNum){
            delete [] weekNum;
            weekNum = nullptr;
        }
    }
};

void inputCourse(Course *);
void displayCourse(Course *);

int main() {
    
}