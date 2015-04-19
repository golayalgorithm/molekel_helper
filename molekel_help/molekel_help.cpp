//============================================================================
// Name        : molekel_help.cpp
// Author      : Bao Vuong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "atom.h"

using namespace std;

/**
 * syntax: ./molekel_help <input file> <multiplying number>
 */
int main(int argc, char** argv) {

	// check if the syntax is good
	if (argc != 3) {
		cout << "syntax: " << argv[0] << " <input file> <multiplying number>" << endl;
		return 0;
	}

	stringstream tempInput(argv[2]);

	int multiplyer;
	tempInput >> multiplyer;

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
        string line;
        
        stringstream lineInput;
		while (!inputFile.eof()) {
			size = 0;
            getline(inputFile,line); // get size
            lineInput.str(line);
            lineInput >> size;
            if (size > 0)
            	cout << size << endl;
            getline(inputFile,line); // header. skipped
            if (size > 0)
            	cout << line << endl;
            vector<atom> molecule(size);
            for (int i=0; i<size; i++) {
                getline(inputFile,line); // atom data
                stringstream atomInput(line);
                atom a;
                atomInput >> a.name >> a.x >> a.y >> a.z;
                a.x *=multiplyer;
                a.y *=multiplyer;
                a.z *=multiplyer;
                cout << atomOutput(a) << endl;
            }
            //molecules.push_back(molecule);
		}
	}
	inputFile.close();
    
    // recall data
	return 0;
}


