#include "utilities.h"

using namespace std;

void error(string msg)
{
    cout<<msg<<endl;
    exit(1);
}

void StrToChar(string str, char arr[BUFFERSIZE])
{
	for(unsigned int i=0; i< str.size(); i++)
		arr[i]=str[i];
	arr[str.size()]='\0';
}


