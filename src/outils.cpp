/*
 * outils.cpp
 *
 *  Created on: 2 févr. 2019
 *      Author: joris
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

#include "outils.h"

using namespace std;

string melangerMot(string mot){

	string motMelange(mot);
	int nombreAleatoire(0);

	for (int i(0); i < motMelange.size(); i++){
		nombreAleatoire = rand() % mot.size();
		motMelange[i] = mot[nombreAleatoire];
		mot.erase(nombreAleatoire, 1);
	}

	return motMelange;
}

void melangerMotDirect(string& mot){

	string motCopie(mot);
	int nombreAleatoire(0);

	for (int i(0); i < mot.size(); i++){
		nombreAleatoire = rand() % motCopie.size();
		mot[i] = motCopie[nombreAleatoire];
		motCopie.erase(nombreAleatoire, 1);
	}
}

string choixMotDictionnaire(ifstream& flux){

	int compteur(0), nombreAleatoire;
	string ligne("");

	while (getline(flux, ligne)){
		compteur++;
	}

	nombreAleatoire = rand() % (compteur - 1);
	flux.clear();
	flux.seekg(0, ios::beg);

	for (int i(0); i <= nombreAleatoire; i++){
		getline(flux, ligne);
	}

	ligne.erase(ligne.size() -1);

	return ligne;
}


