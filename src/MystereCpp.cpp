//============================================================================
// Name        : MystereCpp.cpp
// Author      : Joris Mancini
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "outils.h"

using namespace std;

int main() {

	srand(time(0));

	string motMystere(""), motMelange(""), motPropose("");
	char choixPartie(0);
	bool continuer(false);
	int coups;
	ifstream flux;

	cout << "****** JEU DU MOT MYSTERE ******\n" << endl;
	cout << "Vous devrez retrouver le mot mélanger\n\n" << endl;

	do{

		// Initialisation du mot mystère
		flux.open("dico.txt");

		if (!flux)
				return 0;

		motMystere = choixMotDictionnaire(flux);
		flux.close();

		// Initialisation du nombre de coup
		coups = 5;

		motMelange = melangerMot(motMystere);

		while (motPropose != motMystere && coups > 0){
			cout << "------> " << motMelange << " <------" << endl;
			cout << "Il vous reste " << coups << " coups" << endl;
			cout << "Quel est ce mot ? " << endl;
			cin >> motPropose;
			coups--;
		}

		if (motPropose == motMystere){
			cout << "\nBravo, vous avez gagné !\n" << endl;
		}
		else{
			cout << "\nDésolé vous avez perdu...\n" << endl;
		}


		cout << "Voulez vous rejouer une partie ? (o/n) : ";
		cin >> choixPartie;

		if (choixPartie == 'o'){
			continuer = true;
		}
		else{
			continuer = false;
		}

	} while (continuer);


	return 0;
}
