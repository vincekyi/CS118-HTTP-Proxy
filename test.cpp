#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
void error(string msg)
{
    cout<<msg<<endl;
    exit(1);
}
int main()
{
	string a="hello there";
	error("hello there!");
	cout<<a<<endl;
	exit(1);
	cout<<a<<endl;
}
