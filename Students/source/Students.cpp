#include "Students/Students.hpp"

Students::Students(const std::tuple<size_t, std::string, std::string, std::string>& tuple)
{
	information_ = tuple;
}

Students::Students(std::tuple<size_t, std::string, std::string, std::string>&& tuple)
{
	information_ = std::move(tuple);
}

std::string Students::to_string() const 
{
	std::ostringstream oss;
	oss << std::get<0>(information_) << ' ' << std::get<1>(information_) << ' ' << std::get<2>(information_) 
		<< ' ' << std::get<3>(information_);
	return oss.str();
}

bool Students::validate() const
{
    std::regex date_pattern(R"(\d{2}\.\d{2}\.\d{4})");
    if (!std::regex_match(std::get<3>(information_), date_pattern))
        return false;

    if (std::get<1>(information_).empty() || std::get<2>(information_).empty())
        return false;

    return true;
}

std::tuple<size_t, std::string, std::string, std::string>& Students::get_info()
{
	return information_;
}

const std::tuple<size_t, std::string, std::string, std::string>& Students::get_info() const
{
	return information_;
}

bool Students::operator < (const Students& st) const
{
	return std::tie(std::get<1>(information_), std::get<2>(information_), std::get<3>(information_)) <
		std::tie(std::get<1>(st.information_), std::get<2>(st.information_), std::get<3>(st.information_));
}

bool Students::operator == (const Students& st) const
{
	return std::tie(std::get<1>(information_), std::get<2>(information_), std::get<3>(information_)) ==
		std::tie(std::get<1>(st.information_), std::get<2>(st.information_), std::get<3>(st.information_));
}

bool Students::operator != (const Students& st) const
{
	return !(*this == st);
}