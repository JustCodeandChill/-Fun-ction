#include <iostream>
#include <cstring>
using namespace std;

void trimLeft(string &);
void trimRight(string &);
void trimMiddle(string &);
void capitalizeName(string &);

void print(string &);

int main(){
	string name = "   lucrea    tia  na   ";
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
	
	
	capitalizeName(name);
	print(name);
	
	return 0;
}

void capitalizeName(string &name){
	bool flag = false;
	name[0] = toupper(name[0]);
	for (int i=0; i < name.length();++i){
		if (isspace(name[i]) && flag == false)
			flag = true;
		if (isalpha(name[i]) && flag)
		{
			name[i] = toupper(name[i]);
			flag = false;
		}
	}
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
