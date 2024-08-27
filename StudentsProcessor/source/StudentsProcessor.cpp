#include "StudentsProcessor/StudentsProcessor.hpp"

void StudentsProcessor::read_students_from_file(const std::string& filename, std::set<Students>& students)
{
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "We can't open this file: " << filename << '\n';
        return;
    }
    std::string line;
    while (std::getline(file, line)) 
    {
        std::lock_guard<std::mutex> lock(mutex_);
        Students student;
        std::istringstream iss(line);
        iss >> std::get<0>(student.get_info()) >> std::get<1>(student.get_info()) >> std::get<2>(student.get_info())
            >> std::get<3>(student.get_info());

        if (student.validate()) 
            students.emplace(std::move(student));
    }
    file.close();
}

std::set<Students> StudentsProcessor::process_students(const std::string& file1, const std::string& file2)
{
    std::set<Students> students;
    std::thread thread1(&StudentsProcessor::read_students_from_file, this, file1, std::ref(students));
    std::thread thread2(&StudentsProcessor::read_students_from_file, this, file2, std::ref(students));

    thread1.join();
    thread2.join();

    return students;
}