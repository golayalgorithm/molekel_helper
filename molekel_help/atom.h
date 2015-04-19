/*
 * atom.h
 *
 *  Created on: Apr 19, 2015
 *      Author: bvuong
 */

#ifndef ATOM_H_
#define ATOM_H_

#include <string>

struct atom {
	std::string name;
	double x;
	double y;
	double z;
};

std::string atomOutput(atom);



#endif /* ATOM_H_ */
