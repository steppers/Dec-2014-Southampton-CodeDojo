#include "FileLoader.h"
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

// returns the new list of names of the people minus the removed person
void removePerson(string person, family personsFamily) {
	vector<string> familyNames = personsFamily.names;
	for (int q = 0; q<familyNames.size(); q++)
	{
		string theCurrentPerson = familyNames[q];
		if (theCurrentPerson == person)
		{
		//	familyNames.erase(person, familyNames[q]);
		}
	}
}

void pick(string forWhom, family fam, vector<family> families) {
	int i;
	family f;
	while (true){
		i = rand() % families.size();
		f = families[i];
		if ((f.surname != fam.surname) && f.names.size() > 0)
			break;
	}
	i = rand() % f.names.size();
	cout << forWhom << " : " << f.names[i] << endl;
	removePerson(f.names[i], f);
}

void iterateThroughNames(vector<family> families){
	for (int i = 0; i < families.size(); i++){
		for (int j = 0; j < families[i].names.size(); j++){
			pick(families[i].names[j], families[i], families);
		}
	}
}

int main() {
	FileLoader fileLoader("test.txt");
	vector<family> families = *fileLoader.getData();
	iterateThroughNames(families);
	getchar();
}

