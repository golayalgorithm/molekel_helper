//============================================================================
// Name        : molekel_help.cpp
// Author      : Bao Vuong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
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

string atomOutput(atom a);

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
        string line;
        
        stringstream lineInput;
		while (!inputFile.eof()) {
            getline(inputFile,line); // get size
            lineInput.str(line);
            lineInput >> size;
            getline(inputFile,line); // header. skipped
            
            vector<atom> molecule(77);
            for (int i=0; i<size; i++) {
                getline(inputFile,line); // atom data
                lineInput.str(line);
                atom a;
                lineInput >> a.name;
                lineInput >> a.x;
                lineInput >> a.y;
                lineInput >> a.z;
                cout << atomOutput(a) << endl;
                molecule[i] = a;
            }
            molecules.push_back(molecule);
		}
	}
	inputFile.close();
    
    // recall data

	return 0;
}


string atomOutput(atom a) {
    stringstream output;
    
    if (a.name.size() == 1)
        output << " ";
    output << a.name;
    
    if (a.x >= 0)
        output << " ";
    output << "     ";
    output << a.x;
    
    if (a.y >= 0)
        output << " ";
    output << "     ";
    output << a.y;
    
    if (a.z >= 0)
        output << " ";
    output << "     ";
    output << a.z;
    
    return output.str();
}
