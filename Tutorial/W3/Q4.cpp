#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// 4(a) Class course
class course
{
private:
    string courseName, courseCode;

public:
    // Constructor
    course(string cName = "", string cCode = "")
    {
        courseName = cName;
        courseCode = cCode;
    }

    // Accessor functions
    string getCourseName() const
    {
        return courseName;
    }

    string getCourseCode() const
    {
        return courseCode;
    }

    // Mutator functions
    void setCourseName(string cName)
    {
        courseName = cName;
    }

    void setCourseCode(string cCode)
    {
        courseCode = cCode;
    }

    // Friend function to display course information
    friend void displayCourse(const course& c);
};

// Display course information
void displayCourse(const course& c)
{
    cout << "Gradebook for " << c.courseCode
         << ": " << c.courseName << endl;
}

// 4(b) Class lecturer
class lecturer
{
private:
    string name;
    string position;

public:
    // Constructor
    lecturer(string lecturerName = "", string pos = "")
    {
        name = lecturerName;
        position = pos;
    }

    // Accessor functions
    string getName() const
    {
        return name;
    }

    string getPosition() const
    {
        return position;
    }

    // Mutator functions
    void setName(string lecturerName)
    {
        name = lecturerName;
    }

    void setPosition(string pos)
    {
        position = pos;
    }

    // Display function
    void displayLecturer() const
    {
        cout << "Lecturer: " << name
             << " (Position: " << position << ")"
             << endl;
    }
};

// 4(c) Class student
class student
{
private:
    string name;
    int ID;
    int mark;
    string grade;

    // Calculate grade
    void calculateGrade()
    {
        if (mark >= 90)
            grade = "A+";
        else if (mark >= 80)
            grade = "A";
        else if (mark >= 70)
            grade = "B";
        else if (mark >= 60)
            grade = "C";
        else if (mark >= 50)
            grade = "D";
        else if (mark >= 40)
            grade = "E";
        else
            grade = "F";
    }

public:
    // Constructor
    student(string studentName = "", int id = 0, int Mark = 0)
    {
        name = studentName;
        ID = id;
        mark = Mark;
        calculateGrade();
    }

    // Accessor functions
    string getName() const
    {
        return name;
    }

    int getID() const
    {
        return ID;
    }

    int getMark() const
    {
        return mark;
    }

    string getGrade() const
    {
        return grade;
    }

    // Mutator functions
    void setName(string studentName)
    {
        name = studentName;
    }

    void setID(int id)
    {
        ID = id;
    }

    void setMark(int Mark)
    {
        mark = Mark;
        calculateGrade();
    }

    void setGrade(string Grade)
    {
        grade = Grade;
    }

    // Display function
    void displayStudent() const
    {
        cout << left << setw(25) << name
             << "(" << ID << ")"
             << right << setw(5) << mark
             << " (" << grade << ")" << endl;
    }
};

// 4(d) Class core
class core
{
private:
    course courseInfo;
    lecturer lecturerInfo;
    student students[10];
    int nStudents;

public:
    // Constructor
    core(course c, lecturer l)
    {
        courseInfo = c;
        lecturerInfo = l;
        nStudents = 0;
    }

    // Accessor functions
    course getCourse() const
    {
        return courseInfo;
    }

    lecturer getLecturer() const
    {
        return lecturerInfo;
    }

    int getStudent() const
    {
        return nStudents;
    }

    // Mutator functions
    void setCourse(course c)
    {
        courseInfo = c;
    }

    void setLecturer(lecturer l)
    {
        lecturerInfo = l;
    }

    // Add students into array
    void addStudent(string name, int id)
    {
        if (nStudents < 10)
        {
            int randomMark = rand() % 101;

            students[nStudents] =
                student(name, id, randomMark);

            nStudents++;
        }
        else
        {
            cout << "Maximum of 10 students is reached."
                 << endl;
        }
    }

    // Display the gradebook
    void displayGradebook() const
    {
        displayCourse(courseInfo);
        lecturerInfo.displayLecturer();

        for (int i = 0; i < nStudents; i++)
        {
            cout << i + 1 << ". ";
            students[i].displayStudent();
        }
    }
};

// 4(e) Main function
int main()
{
    srand(time(0)); // Seed the random number generator

    // Create course and lecturer objects
    course cexp("Programming II", "KIE1008");
    lecturer lecp("XXX", "Professor");

    // Create core object
    core gradebook(cexp, lecp);

    // Input student information
    int nStudents;

    cout << "Enter number of students (0-10): ";
    cin >> nStudents;

    if (nStudents < 0 || nStudents > 10)
    {
        cout << "Invalid number of students."
             << endl;
        return 1;
    }

    for (int i = 0; i < nStudents; i++)
    {
        string name;
        int id;

        cout << "\nEnter student " << i + 1
             << " name: ";
        getline(cin >> ws, name);

        cout << "Enter student ID: ";
        cin >> id;

        gradebook.addStudent(name, id);
    }

    // Display final gradebook
    cout << endl;
    gradebook.displayGradebook();

    return 0;
}
