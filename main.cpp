#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>


struct Student// Структура для представления студента 
{
    int id;
    std::string name;
    int age;
};

class StudentDatabase 
{
private:
    std::vector<std::shared_ptr<Student>> students; // Вектор для хранения студентов

public:
    void addStudent(int id, const std::string& name, int age)// Метод для добавления нового студента в базу данных 
    {
        auto newStudent = std::make_shared<Student>(Student{id, name, age});
        students.push_back(newStudent);
        std::cout << "Студент добавлен в базу данных." << std::endl;
    }

    void removeStudent(int id)// Метод для удаления студента по идентификатору 
    {
        auto it = std::find_if(students.begin(), students.end(),
                               [id](const std::shared_ptr<Student>& s) {
                                   return s->id == id;
                               });
        if (it != students.end()) {
            students.erase(it);
            std::cout << "Студент удален из базы данных." << std::endl;
        } else {
            std::cout << "Студент с данным идентификатором не найден." << std::endl;
        }
    }

    void getStudentInfo(int id) // Метод для получения информации о студенте по идентификатору 
    {
        auto it = std::find_if(students.begin(), students.end(),
                               [id](const std::shared_ptr<Student>& s) {
                                   return s->id == id;
                               });
        if (it != students.end()) {
            std::cout << "Информация о студенте:" << std::endl;
            std::cout << "ID: " << (*it)->id << std::endl;
            std::cout << "Имя: " << (*it)->name << std::endl;
            std::cout << "Возраст: " << (*it)->age << std::endl;
        } else {
            std::cout << "Студент с данным идентификатором не найден." << std::endl;
        }
    }
};

int main() {
    StudentDatabase database;

    return 0;
}
