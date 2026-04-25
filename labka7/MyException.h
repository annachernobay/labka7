#pragma once
#include <string>
#include<exception>


class MyException : public std::exception
{
private:
	std::string message;
public:
	MyException();
	MyException(const std::string& msg);
	const char* what() const noexcept override;
};

