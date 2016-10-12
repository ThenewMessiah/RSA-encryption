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
		file.close();
		return;
	}
	else throw Exception("Output file could not be opened!");
}

Key readKey(string fileName)
{
	string buffer = "";
	int privateKey, exp, base, factor1, factor2;
	ifstream file;
	file.open(fileName.c_str(), fstream::in);

	if (file.is_open())
	{
		getline (file, buffer);
		privateKey = stoi(buffer);
		buffer.clear();
		getline (file, buffer);
		exp = stoi(buffer);
		buffer.clear();
		getline (file, buffer);
		base = stoi(buffer);
		buffer.clear();
		getline (file, buffer);
		factor1 = stoi(buffer);
		buffer.clear();
		getline (file, buffer);
		factor2 = stoi(buffer);
		buffer.clear();

		file.close();
		Key k(privateKey, base, factor1, factor2, exp);
		return k;
	}
	else throw Exception("Could not open key file for reading!");
}

string writeKey(Key key)
{
	string str = "";
	str.append(to_string(key.getPrivateKey()));
	str.append("\n");
	str.append(to_string(key.getPublicExp()));
	str.append("\n");
	str.append(to_string(key.getPublicBase()));
	str.append("\n");
	str.append(to_string(key.getFactor1()));
	str.append("\n");
	str.append(to_string(key.getFactor2()));
	str.append("\n");
	str.append("PUBLIC KEY: ");
	string pubKey = "(" + to_string(key.getPublicBase()) + ", " + to_string(key.getPublicExp()) + ")" + "\n";
	str.append(pubKey);
	str.append("PRIVATE KEY: ");
	string priKey = "(" + to_string(key.getPrivateKey()) + ")" + "\n";
	str.append(priKey);

	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );

	string keyFile = "key_";
	keyFile.append(to_string(now->tm_year + 1900));
	keyFile.append(to_string(now->tm_mon + 1));
	keyFile.append(to_string(now->tm_mday));
	keyFile.append("_");
	keyFile.append(to_string(now->tm_hour));
	keyFile.append(to_string(now->tm_min));
	keyFile.append(to_string(now->tm_sec));
	keyFile.append(".txt");

	// Check if a file of this name already exists
	ifstream ifile(keyFile);
	if (ifile)
	{
		ifile.close();
		keyFile.append("_1");
	}

	writeMessageToFile(str, keyFile);
	return keyFile;
}