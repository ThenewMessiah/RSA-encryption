#include "fileIO.h"

string getMessageFromFile(string fileName)
{
	ifstream file;
	file.open(fileName.c_str(), fstream::in);

	if (file.is_open())
	{
		char tempChar;
		string messageStr = "";

		while(file >> noskipws >> tempChar)
		{
			messageStr += tempChar;
		}
		file.close();
		return messageStr;
	}
	else throw Exception("Input file could not be opened!");
}

void writeMessageToFile(string message, string fileName)
{
	ofstream file;
	file.open(fileName.c_str(), fstream::out);

	if (file.is_open())
	{
		char tempChar;
		const int size = message.length() * 2;
		char* arr = new char[size];
		std::strcpy(arr, message.c_str());
		file.write(arr, message.size());
		delete[] arr;
		return;
	}
	else throw Exception("Output file could not be opened!");
}