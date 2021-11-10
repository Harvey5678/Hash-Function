#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int hashFun(string s);
void saveToFile(const char* name, int index);
string loadFromFile(const char* fileName);

int main() {
	int index = 0;
	string str;
	str = loadFromFile("input.txt");
	index= hashFun(str);
	saveToFile("output.txt", index);
	return 0;
}

int hashFun(string s) {
	int len;
	int temIndex = 1;
	int num = 0;
	int index = 0;
	len = s.length();
	for (int i = 0; i < len; i++) {
		num = (int)s[i];
		if (i % 2 == 0) {
			temIndex = (temIndex * num) / 10;
		}
		else {
			temIndex = pow(temIndex, 2) / num * log(num);
		}
		index = index + temIndex;
	}
	return index;
}

void saveToFile(const char* name, int index)
{
	ofstream 	out;
	out.open(name);
	if (!out)
	{
		cerr << "Failed to open " << name << " for writing!" << endl;
		exit(1);
	}
	out << index << ";"<<endl;

	out.close();
}

string loadFromFile(const char* fileName)
{
	string str;
	ifstream	in;


	in.open(fileName);
	if (!in)
	{
		cerr << "Failed to open " << fileName << " for reading!" << endl;
		exit(1);
	}

	in >> str;
	in.get();

	in.close();
	return str;
}