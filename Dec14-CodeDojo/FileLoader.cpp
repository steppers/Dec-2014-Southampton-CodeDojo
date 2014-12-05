#include "FileLoader.h"
#include <fstream>

FileLoader::FileLoader(string fileName)
{
	ifstream file(fileName);

	bool foundFamily;
	string name;
	string surname;
	while(true)
	{
		if (file.eof())
			break;
		foundFamily = false;
		file >> name >> surname;
		for (int i = 0; i < families.size(); i++)
		{
			if (surname == families[i].surname)
			{
				families[i].names.push_back(name + " " + surname);
				foundFamily = true;
				break;
			}
		}
		if (!foundFamily)
		{
			family f;
			f.names.push_back(name + " " + surname);
			f.surname = surname;
			families.push_back(f);
		}
	}
}

vector<family> *FileLoader::getData(){
	return &families;
}

