#include <iostream>
#include "fileIO.h"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		string str = getMessageFromFile("input.txt");
		writeMessageToFile(str, "output.txt");
	}
	catch (Exception& caught)
	{
		cout << caught.message() << endl;
		return -1;
	}

	return 0;
}