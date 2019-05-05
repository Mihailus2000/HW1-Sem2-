#pragma once

#include <exception>
#include <string>


class Exception : virtual public std::exception{

private:

	std::string errorText = "";
public:
	explicit Exception(std::string text) : errorText(std::move(text)){
	
	}

	const char* what() const noexcept override

	{

		return errorText.c_str();

	}

};