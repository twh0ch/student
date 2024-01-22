#include "class.hpp"

void runMain() {
    std::vector<Student> students;
    Student::initializeVectorFromFile("students.txt", students);

    bool exitProgram = false;

    do {
        std::cout << "Выберите опцию сортировки:" << std::endl;
        std::cout << "1. Сортировка по имени\n";
        std::cout << "2. Сортировка по фамилии\n";
        std::cout << "3. Сортировка по отчеству\n";
        std::cout << "4. Сортировка по оценке\n";
        std::cout << "5. Сортировка по возрасту\n";
        std::cout << "0. Выйти из программы\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                Student::sortByFirstName(students);
                break;
            case 2:
                Student::sortByLastName(students);
                break;
            case 3:
                Student::sortByMiddleName(students);
                break;
            case 4:
                Student::sortByDiplomaGrade(students);
                break;
            case 5:
                Student::sortByAge(students);
                break;
            case 0:
                exitProgram = true;
                break;
            default:
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }

        if (!exitProgram) {
            std::cout << "==================================" << std::endl;
            std::cout << "Список студентов после сортировки:" << std::endl;
            for (const auto& student : students) {
                student.printInfo();
                std::cout << "-------------------------\n";
            }
        }
    } while (!exitProgram);

    Student::writeVectorToFile("sorted_students.txt", students);
}
