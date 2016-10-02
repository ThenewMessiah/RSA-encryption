#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include "exception.h"

using namespace std;

string getMessageFromFile(string fileName);
void writeMessageToFile(string message, string fileName);

#endif