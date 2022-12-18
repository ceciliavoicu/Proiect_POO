#pragma once
#include"eveniment.h";
string creareCodBilet() {
	const int valoareMaximaLitere = 36;
	int nrCaractereCod = 20;
	const char vectCaractere[valoareMaximaLitere] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
						  'h', 'i', 'j', 'k', 'l', 'm', 'n',
						  'o', 'p', 'q', 'r', 's', 't', 'u',
						  'v', 'w', 'x', 'y', 'z' ,'0','1','2','3','4','5','6','7','8','9' };
	string rezultat = "";
	for (int i = 0; i < 20; i++) {
		rezultat = rezultat + vectCaractere[rand() % valoareMaximaLitere];
	}
	return rezultat;
}

class Bilet {
	const string idBilet;
	int nrLoc;
	int nrRand;
	float pretTotalBilet;
	Eveniment* event;
	static int TVA_Bilet_Procent;
	bool platitCuCardul;

};
static int TVA_Bilet_Procent = 15;