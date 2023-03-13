#include <iostream>

bool assertion_exception_handler(const char* file, unsigned int line, const char* func)
{
	std::cout << "Assertion error at " << file << ":" << line << " in " << func << std::endl;
	return true;
}
