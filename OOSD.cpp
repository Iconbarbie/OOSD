#include <iostream>
#include <string>

using namespace std;

/*
   ABSTRACT CLASS: Person
*/
class Person {
protected:
    string name;

public:
    // Constructor
    Person(string name) {
        this->name = name;
    }

    // Getter
    string getName() const {
        return name;
    }

    // Setter
    void setName(string name) {
        this->name = name;
    }

    // Pure virtual function (Abstraction)
    virtual void displayDetails() const = 0;
};

/*
   ABSTRACT CLASS: Grading
*/
class Grading {
public:
    // Pure virtual function
    virtual string calculateGrade() const = 0;
};

/*
   Course Class
   Demonstrates Encapsulation
*/
class Course {
private:
    string courseCode;
    string courseName;

public:
    // Constructor
    Course(string code, string name) {
        courseCode = code;
        courseName = name;
    }

    // Getters
    string getCourseCode() const {
        return courseCode;
    }

    string getCourseName() const {
        return courseName;
    }

    // Setters
    void setCourseCode(string code) {
        courseCode = code;
    }

    void setCourseName(string name) {
        courseName = name;
    }
};

/*
   Student Class
   Demonstrates:
   - Inheritance (Person)
   - Multiple Inheritance (Grading)
   - Polymorphism (Method Overriding)
   - Encapsulation
*/
class Student : public Person, public Grading {
private:
    int studentId;
    int marks;
    Course course;

public:
    // Constructor
    Student(int id, string name, int marks, Course course)
        : Person(name), course(course) {
        this->studentId = id;
        this->marks = marks;
    }

    // Getters
    int getStudentId() const {
        return studentId;
    }

    int getMarks() const {
        return marks;
    }

    Course getCourse() const {
        return course;
    }

    // Setters
    void setStudentId(int id) {
        studentId = id;
    }

    void setMarks(int m) {
        marks = m;
    }

    void setCourse(Course c) {
        course = c;
    }

    // Implement calculateGrade() from Grading (Polymorphism)
     virtual string calculateGrade() const {
        if (marks >= 70) return "A";
        else if (marks >= 60) return "B";
        else if (marks >= 50) return "C";
        else return "Fail";
    }

    // Override displayDetails() from Person (Polymorphism)
    void displayDetails() const {
        cout << "\n------ Student Details ------" << endl;
        cout << "Student ID: " << studentId << endl;
        cout << "Name: " << name << endl;
        cout << "Course Code: " << course.getCourseCode() << endl;
        cout << "Course Name: " << course.getCourseName() << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << calculateGrade() << endl;
        cout << "-" << endl;
    }
};

/*
   MAIN FUNCTION
   Application Entry Point
*/
int main() {

    int id, marks;
    string name, courseCode, courseName;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();  // Clear input buffer

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Course Code: ";
    getline(cin, courseCode);

    cout << "Enter Course Name: ";
    getline(cin, courseName);

    cout << "Enter Marks: ";
    cin >> marks;

    // Create Course object
    Course course(courseCode, courseName);

    // Create Student object
    Student student(id, name, marks, course);

    // Display student details
    student.displayDetails();

    return 0;
}
