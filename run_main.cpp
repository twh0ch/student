#include "class.hpp"

void runMain() {
    std::vector<Student> students;
    Student::initializeVectorFromFile("students.txt", students);
    
    std::cout << "Список студентов до сортировки:" << std::endl;
    for (const auto& student : students) {
        student.printInfo();
        std::cout << "-------------------------\n";
    }

    Student::sortByFirstName(students);
    // Student::sortByMiddleName(students);
    // Student::sortByMiddleName(students);
    // Student::sortByDiplomaGrade(students);

    // Student::sortByAge(students);

    std::cout << "Список студентов после сортировки:" << std::endl;
    for (const auto& student : students) {
        student.printInfo();
        std::cout << "-------------------------\n";
    }
    Student::writeVectorToFile("sorted_students.txt", students);
}
