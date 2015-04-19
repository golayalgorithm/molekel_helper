/*
 * atom.cpp
 *
 *  Created on: Apr 19, 2015
 *      Author: bvuong
 */
#include "atom.h"

#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string atomOutput(atom a) {
    stringstream output;

    if (a.name.size() == 1)
        output << " ";
    output << a.name;

    if (a.x >= 0)
        output << " ";
    output << "     ";
    output << fixed << setprecision(5-(abs(a.x) < 1 ? 0 : log10(abs(a.x))-1));
    output << a.x;

    if (a.y >= 0)
        output << " ";
    output << "     ";
    output << fixed << setprecision(5-(abs(a.y) < 1 ? 0 : log10(abs(a.y))-1));
    output << a.y;

    if (a.z >= 0)
        output << " ";
    output << "     ";
    output << fixed << setprecision(5-(abs(a.z) < 1 ? 0 : log10(abs(a.z))-1));
    output << a.z;

    return output.str();
}


