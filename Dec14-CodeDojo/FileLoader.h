#pragma once

#include <string>
#include <vector>

using namespace std;

struct family{
	vector<string> names;
	string surname;
};

class FileLoader
{
public:
	FileLoader(string fileName);

	vector<family> *getData();
	
private:
	vector<family> families;
};

