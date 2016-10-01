#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>

using namespace std;

struct Exception : public std::exception
{
	std::string s;
	Exception(string ss) : s(ss) {}
	~Exception() throw () {} // Updated
	const char* message() const throw() { return s.c_str(); }
};

string getMessageFromFile(string fileName);
void writeMessageToFile(string message, string fileName);

#endif