#pragma once
#include <string>
#include <algorithm>

class Mystring : public std::string {
public:
	Mystring(const std::string& str) : std::string(str) {};
	Mystring() : std::string() {};
	void tolower();
	void removePunctuation();
	operator unsigned();

};