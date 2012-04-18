#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <wait.h>

#define BUFFERSIZE 256

void StrToChar(std::string str, char arr[BUFFERSIZE]);
void error(std::string msg); 

//kills zombie processes
static void child_terminated(int i)
{
	int status = 0;
	while(waitpid(0,&status,WNOHANG|WUNTRACED) > 0)
	{
	}

}
#endif
