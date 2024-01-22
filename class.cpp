#include "class.hpp"

std::string Student::getFirstName() const {
    return firstName;
}

void Student::setFirstName(const std::string& name) {
    firstName = name;
}

std::string Student::getLastName() const {
    return lastName;
}

void Student::setLastName(const std::string& name) {
    lastName = name;
}

std::string Student::getMiddleName() const {
    return middleName;
}

void Student::setMiddleName(const std::string& name) {
    middleName = name;
}

int Student::getAge() const {
    return age;
}

void Student::setAge(int studentAge) {
    age = studentAge;
}

int Student::getDiplomaGrade() const {
    return diplomaGrade;
}

void Student::setDiplomaGrade(int grade) {
    diplomaGrade = grade;
}

Student::Student(const std::string& fName, const std::string& lName, const std::string& mName, int studentAge, int grade)
    : firstName(fName), lastName(lName), middleName(mName), age(studentAge), diplomaGrade(grade) {}


void Student::initializeVectorFromFile(const std::string& filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Ошибка при открытии файла!" << std::endl;
        return;
    }

    students.clear(); 

    std::string firstName, lastName, middleName;
    int age, diplomaGrade;

    while (file >> firstName >> lastName >> middleName >> age >> diplomaGrade) {
        students.push_back(Student(firstName, lastName, middleName, age, diplomaGrade));
    }

    file.close();
}
void Student::writeVectorToFile(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);
        if (!file) {
            std::cout << "Ошибка при открытии файла!" << std::endl;
            return;
        }

        for (const auto& student : students) {
            file << student.getFirstName() << " " << student.getLastName() << " "
                << student.getMiddleName() << " " << student.getAge() << " " << student.getDiplomaGrade() << std::endl;
        }

        file.close();
}

void Student::sortByFirstName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getFirstName() < b.getFirstName();
        });
}

void Student::sortByLastName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),[](const Student& a, const Student& b) {
            return a.getLastName() < b.getLastName();
        });
}

void Student::sortByMiddleName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getMiddleName() < b.getMiddleName();
        });
}

void Student::sortByAge(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getAge() < b.getAge();
        });
}

void Student::sortByDiplomaGrade(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getDiplomaGrade() > b.getDiplomaGrade();
        });
}

void Student::printInfo() const {
    std::cout << "Имя: " << firstName << "\nФамилия: " << lastName
              << "\nОтчество: " << middleName << "\nВозраст: " << age
              << "\nОценка за диплом: " << diplomaGrade << std::endl;
}
