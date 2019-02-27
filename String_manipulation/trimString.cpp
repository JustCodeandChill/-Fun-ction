#include <iostream>
#include <cstring>
using namespace std;

void trimLeft(string &);
void trimRight(string &);
void trimMiddle(string &);
void print(string &);

int main(){
	string name = "   Lucrea    tia     ";
	bool condition;
	print(name);
	
	//Trim left
	trimLeft(name);
	print(name);
	
	//trim right
	trimRight(name);
	print(name);
	
	//Trim middle
	trimMiddle(name);
	print(name);
	
	
	return 0;
}
void print(string &name){
	cout << name << "." <<name.length() << endl;
}

void trimLeft(string &name)
{
		for (int i=0; i < name.length();++i)
	{
		if (isalpha(name[i]))
			break;
			
		while (isspace(name[i]))
			name.erase(i,1);
	}
}

void trimRight(string &name)
{
	for (int i= name.length(); i > 0;--i){
		if (isalpha(name[i]))
			break;
			
			while (isspace(name[i]))
			name.erase(i,1);
	}
}

void trimMiddle(string &name)
{
	for (int i=0; i < name.length();++i)
	{
		while (isspace(name[i]) && isspace(name[i+1]))
			name.erase(i,1);
	}
}
