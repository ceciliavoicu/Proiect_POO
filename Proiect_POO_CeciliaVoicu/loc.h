#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
const int nrRandMaxim = 100;
const int nrLocMaxim = 100;

class Loc {
	int nrRand;
	int nrLoc;
	bool esteOcupat;
public:
	Loc() {
		this->nrRand = 0;
		this->nrLoc = 0;
		this->esteOcupat = 0;
	}
	Loc(int nrRand, int nrLoc) {
		if (nrRand >= 0 && nrRand < nrRandMaxim) {
			this->nrRand = nrRand;
		}
		else {
			this->nrRand = 0;
		}
		if (nrLoc >= 0 && nrLoc < nrLocMaxim) {
			this->nrLoc = nrLoc;
		}
		else {
			this->nrLoc = 0;
		}
		this->esteOcupat = 0;
	}
	Loc(int nrRand, int nrLoc, bool esteOcupat) {
		if (nrRand >= 0 && nrRand < nrRandMaxim) {
			this->nrRand = nrRand;
		}
		else {
			this->nrRand = 0;
		}
		if (nrLoc >= 0 && nrLoc < nrLocMaxim) {
			this->nrLoc = nrLoc;
		}
		else {
			this->nrLoc = 0;
		}
		this->esteOcupat = esteOcupat;
	}

	int getNrRand() {
		return this->nrRand;
	}

	int getNrLoc() {
		return this->nrLoc;
	}

	bool getEsteOcupat() {
		return this->esteOcupat;
	}

	void setNrRand(int nrRand) {
		if (nrRand >= 0 && nrRand < nrRandMaxim) {
			this->nrRand = nrRand;
		}
	}

	void setNrLoc(int nrLoc) {
		if (nrLoc >= 0 && nrLoc < nrLocMaxim) {
			this->nrLoc = nrLoc;
		}
	}

	void setEsteOcupat(bool esteOcupat) {
		this->esteOcupat = esteOcupat;
	}

	~Loc() {

	}

	Loc(const Loc& l) {
		this->nrRand = l.nrRand;
		this->nrLoc = l.nrLoc;
		this->esteOcupat = l.esteOcupat;
	}

	Loc& operator=(const Loc& l) {
		this->nrRand = l.nrRand;
		this->nrLoc = l.nrLoc;
		this->esteOcupat = l.esteOcupat;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Loc& l) {
		out << "Nr Rand: " << (l.nrRand + 1) << endl;
		out << "Nr Loc: " << (l.nrLoc + 1) << endl;
		out << "Este Ocupat: ";
		if (l.esteOcupat == true) {
			out << "Da" << endl;
		}
		else {
			out << "Nu" << endl;
		}
		return out;
	}

	friend istream& operator>>(istream& in, Loc& l) {
		cout << "Nr Rand: ";
		int auxNrRand;
		in >> auxNrRand;
		if (auxNrRand >= 0 && auxNrRand < nrRandMaxim) {
			l.nrRand = auxNrRand;
		}

		cout << "Nr Loc: ";
		int auxNrLoc;
		in >> auxNrLoc;
		if (auxNrLoc >= 0 && auxNrLoc < nrLocMaxim) {
			l.nrLoc = auxNrLoc;
		}

		cout << "Este ocupat?(1-Da sau 0-Nu) -- Introduceti cifra: ";
		in >> l.esteOcupat;
		return in;
	}

	bool biletulEsteInUltimulRand() {
		return (this->nrRand == nrRandMaxim - 1);
	}

	bool biletulEstePeMargine() {
		return (this->nrLoc == 1 || this->nrLoc == nrLocMaxim - 1);
	}

	bool operator >(Loc l) {
		return this->nrLoc > l.nrLoc;
	}

	bool operator == (Loc l) {
		return this->nrLoc == l.nrLoc && this->nrRand == l.nrRand;
	}
};
