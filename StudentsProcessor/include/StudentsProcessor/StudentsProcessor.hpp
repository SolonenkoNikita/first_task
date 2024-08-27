#ifndef _STUDENTS_PROCESSOR_HPP_
#define _STUDENTS_PROCESSOR_HPP_

#include "Students/Students.hpp"

#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>

class StudentsProcessor 
{
public:
    void read_students_from_file(const std::string&, std::set<Students>&);

    std::set<Students> process_students(const std::string&, const std::string&);
private:
    std::mutex mutex_;
};

#endif
