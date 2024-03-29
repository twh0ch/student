#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "run_main.hpp"

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int age;
    int diplomaGrade;

public:
    std::string getFirstName() const;
    void setFirstName(const std::string& name);
    std::string getLastName() const;
    void setLastName(const std::string& name);
    std::string getMiddleName() const;
    void setMiddleName(const std::string& name);
    int getAge() const;
    void setAge(int studentAge);
    int getDiplomaGrade() const;
    void setDiplomaGrade(int grade);

    Student(const std::string& fName, const std::string& lName, const std::string& mName, int studentAge, int grade);

    static void initializeVectorFromFile(const std::string& filename, std::vector<Student>& students);
    static void writeVectorToFile(const std::string& filename, const std::vector<Student>& students);

    static void sortByFirstName(std::vector<Student>& students);
    static void sortByLastName(std::vector<Student>& students);
    static void sortByMiddleName(std::vector<Student>& students);
    static void sortByAge(std::vector<Student>& students);
    static void sortByDiplomaGrade(std::vector<Student>& students);

    void printInfo() const;
};
#endif // CLASS_H
