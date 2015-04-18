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
		int size;
		string header;
		string name;
		double x;
		double y;
		double z;
		for (int i=0; i<8; i++) {
			inputFile >> size;
			inputFile >> header;
			inputFile >> header;
			inputFile >> header;
			cout << size << endl;
			for (int j=0; j<size; j++) {
				inputFile >> name;
				inputFile >> x;
				inputFile >> y;
				inputFile >> z;
				cout << name << " ";
				cout << 5*x << "," << 5*y << "," << 5*z << endl;
			}
		}
		string::size_type sz;
		/*
		while (!inputFile.eof()) {
			string line;
			getline(inputFile,line); // reading the size
			getline(inputFile,line); // reading the header
			getline(inputFile,line); //
			stringstream lineInput(line);
		}
		*/
		cout << "ok" << endl;
	}
	inputFile.close();
	//atom a = molecules[0][0];
	//cout << "name: " << a.name << endl;
	//cout << "x: " << a.x << endl;
	//cout << "y: " << a.y << endl;
	//cout << "z: " << a.z << endl;


	return 0;
}
