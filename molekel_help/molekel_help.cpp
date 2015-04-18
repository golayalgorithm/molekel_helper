//============================================================================
// Name        : molekel_help.cpp
// Author      : Bao Vuong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


struct atom {
	string name;
	double x;
	double y;
	double z;
};

struct frame {
	vector<atom> molecule;
};



/**
 * syntax: ./molekel_help <input file> <output file>
 */
int main(int argc, char** argv) {

	// get file name
	char* inputFileName = argv[1];

	// now we got the name, get the actual file contents to read
	ifstream inputFile;
	inputFile.open(inputFileName);

	// alright, let's read the contents

	vector<vector<atom> > molecules;

	string input;
	if (inputFile.is_open()) {
		int tempInt;
		string tempString;
		double tempDouble;
		string::size_type sz;
		while (!inputFile.eof()) {

			inputFile >> tempString;
			int size = stoi(tempString,&sz);//tempInt; // should be 77
			inputFile >> tempString;
			inputFile >> tempString;
			inputFile >> tempString;
			vector<atom> molecule(size);
			cout << "scanning atoms" << endl;
			for (int i=0; i<size; i++) {
				atom a;
				inputFile >> a.name;
				inputFile >> tempString; a.x = stod(tempString,&sz);
				inputFile >> tempString; a.y = stod(tempString,&sz);
				inputFile >> tempString; a.z = stod(tempString,&sz);
				molecule[i] = a;
				cout << a.name << endl;
			}
			cout << "add molecule" << endl;
			molecules.push_back(molecule);
			cout << "size: " << molecules.size() << endl;
		}
		cout << "ok" << endl;
	}
	inputFile.close();
	atom a = molecules[0][0];
	cout << "name: " << a.name << endl;
	cout << "x: " << a.x << endl;
	cout << "y: " << a.y << endl;
	cout << "z: " << a.z << endl;


	return 0;
}
