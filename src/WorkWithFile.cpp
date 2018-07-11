#include "WorkWithFile.h"


bool WorkWithFile::readFile(std::string name, std::ostream* response_body, std::ostream* log)
{
	std::ifstream fread(name, std::ios::binary);
	if (fread.fail()) {
		if (log != nullptr)
			*log << "failed open file: " << name << '\n';
		return false;
	}
	std::string line = "";
	while (std::getline(fread, line)) {
		*response_body << line;
	}
	// if (log != nullptr)
		// *log << "read file: " << name << '\n';
	fread.close();
	return true;
}