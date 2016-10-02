#include <iostream>
#include <time.h>
#include "exception.h"
#include "fileIO.h"
#include "rsa.h"

using namespace std;

int main(int argc, char* argv[])
{
	srand (time(NULL));
	try
	{
		// TODO: Implement client features
	}
	catch (Exception& caught)
	{
		cout << caught.message() << endl;
		return -1;
	}
	return 0;
}