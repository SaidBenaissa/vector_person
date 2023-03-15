#include <iostream>
#include <string>
#include <vector>

class Student;

class Person {
private:
    std::string name;
    int age;

public:
    friend class Student;
    friend void printPerson(Person person);

    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

};

class Student : public Person {
private:
    int studentId;
public:
    Student(std::string name, int age, int studentId) : Person(name, age) {
        this->studentId = studentId;
    }

    int getStudentId() {
        return studentId;
    }

    void printStudent() {
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Age: " << getAge() << std::endl;
        std::cout << "Student ID: " << getStudentId() << std::endl;
    }
};

void printPerson(Person person) {
    std::cout << "Name: " << person.getName();
    std::cout << "Age: " << person.getAge();
}

int main() {
    std::vector<Person> people;
    people.push_back(Person("John", 20));
    people.push_back(Person("Mary", 30));
    people.push_back(Person("Bob", 40));

    for (int i = 0; i < people.size(); i++) {
        printPerson(people[i]);
    }

    std::cout << " ---  " <<std::endl;
    std::vector <Student> students =
    {
        Student("John", 20, 123),
        Student("Mary", 30, 456),
        Student("Bob", 40, 789)
    };

    for( auto student : students)
    {
        student.printStudent();
    }
    return 0;
}
