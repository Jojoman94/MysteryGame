/*
 * outils.h
 *
 *  Created on: 2 févr. 2019
 *      Author: joris
 */

#ifndef OUTILS_H_
#define OUTILS_H_

#include <iostream>
#include <string>

using namespace std;

string melangerMot(string mot);
void melangerMotDirect(string& mot);
string choixMotDictionnaire(ifstream& flux);

#endif /* OUTILS_H_ */
