#pragma once

// All STL includes in alphabetical order
#include <fstream>
#include <string>


class WorkWithFile
{
public:
	WorkWithFile() = delete;
	~WorkWithFile() = delete;

	WorkWithFile(const WorkWithFile&) = delete;
	WorkWithFile(const WorkWithFile&&) = delete;

	WorkWithFile& operator = (const WorkWithFile&) = delete;
	WorkWithFile& operator = (WorkWithFile&&) = delete;

	static bool readFile(std::string name, std::ostream* response_body, std::ostream* log = nullptr);

};

