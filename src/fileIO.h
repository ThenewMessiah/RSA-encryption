#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>
#include "exception.h"
#include "rsa.h"

using namespace std;

string getMessageFromFile(string fileName);
void writeMessageToFile(string message, string fileName);
Key readKey(string keyFile);
string writeKey(Key key);

#endif