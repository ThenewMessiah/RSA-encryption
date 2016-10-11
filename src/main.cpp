#include <iostream>
#include <time.h>
#include "exception.h"
#include "fileIO.h"
#include "rsa.h"

using namespace std;

int main(int argc, char* argv[])
{
	srand (time(NULL));

	if(argc < 3)
	{
		cout << endl << "RSA -e/-d [input.txt] [output.txt] [key.txt]" << endl << endl;
		return -1;
	}

	string cryptChoice = argv[1];
	string inputFile = argv[2];
	string outputFile = argv[3];
	string keyFile = argv[4];

/*	if(!cryptChoice.compare("-e") || !cryptChoice.compare("-d"))
	{
		cout << endl << "Choose a flag: -e for encrypt, -d for decrypt. "
								"ex: ./RSA -e/-d [input.txt] [output.txt]" << endl << endl;
		return -1;
	}*/

	try
	{
		if(cryptChoice == "-e")
			encryptRSA(inputFile, outputFile);
		else
			decryptRSA(inputFile, outputFile, keyFile);
	}
	catch (Exception& caught)
	{
		cout << caught.message() << endl;
		return -1;
	}
	return 0;
}