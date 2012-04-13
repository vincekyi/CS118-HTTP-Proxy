#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <stdlib.h>

#define BUFFERSIZE 256

void StrToChar(std::string str, char arr[BUFFERSIZE]);
void error(std::string msg); 
#endif
