#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include <tuple>
#include <string>
#include <iostream>
#include <regex>
#include <sstream>

class Students
{
public:

	Students() = default;

	Students(const std::tuple<size_t, std::string, std::string, std::string>&);

	Students(std::tuple<size_t, std::string, std::string, std::string>&&);

	std::string to_string() const; 

    bool validate() const;

	std::tuple<size_t, std::string, std::string, std::string>& get_info();

	const std::tuple<size_t, std::string, std::string, std::string>& get_info() const;

	bool operator < (const Students&) const;

	bool operator == (const Students&) const;

	bool operator != (const Students&) const;
private:
	std::tuple<size_t, std::string, std::string, std::string> information_;

};

#endif