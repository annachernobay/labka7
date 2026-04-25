#include "MyException.h"
#include <string>
#include <iostream>
#include <exception>

MyException::MyException() :message("Unknown") {
	std::cout << "MyException default constructor" << std::endl;
}

MyException::MyException(const std::string& msg) :message(msg)
{
	std::cout << "MyException overloaded constructor" << std::endl;
}
const char* MyException::what() const noexcept
{
	return message.c_str();
}

