#pragma once

#include <stdexcept>
#include <iostream>
#include <string>

template<typename T>

class DuplicateError : public std::logic_error {

public:
	DuplicateError(const T& message);

}; 

template<typename T>
inline DuplicateError<T>::DuplicateError(const T& message) : std::logic_error(std::string("Duplicate Mystring: ") + message)
{

}
