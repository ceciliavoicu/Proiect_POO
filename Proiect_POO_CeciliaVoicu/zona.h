#pragma once
#include"loc.h"
class Zona {
	const int idZona;
	static int numarator;
	string numeZona;
	int nrLocuri;
	Loc** locuri;
public:
	Zona() :idZona(numarator++) {
		this->numeZona = "Anonim";
		this->nrLocuri = 0;
		this->locuri = NULL;
	}
	Zona(string numeZona, int nrLocuri, Loc** locuri) :idZona(numarator++) {
		if (numeZona.size() >= 3)
		{
			this->numeZona = numeZona;
		}
		else {
			this->numeZona = "Peluza";
		}

		if (nrLocuri > 0 && locuri != NULL) {
			this->nrLocuri = nrLocuri;
			this->locuri = new Loc * [this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++) {
				this->locuri[i] = new Loc(*locuri[i]);
			}
		}
		else
		{
			this->nrLocuri = 0;
			this->locuri = NULL;
		}

	}

	string getNumeZona() {
		return this->numeZona;
	}

	int getNrLocuri() {
		return this->nrLocuri;
	}

	Loc** getLocuri() {
		return this->locuri;
	}

	void setNumeZona(string numeZona) {
		if (numeZona.size() >= 3)
		{
			this->numeZona = numeZona;
		}
	}

	~Zona() {
		if (this->locuri != NULL) {
			for (int i = 0; i < this->nrLocuri; i++) {
				delete this->locuri[i];
			}
			delete[]this->locuri;
		}
	}

	void setLocuri(int nrLocuri, Loc** locuri) {
		if (nrLocuri > 0 && locuri != NULL) {
			if (this->locuri != NULL) {
				for (int i = 0; i < this->nrLocuri; i++) {
					delete this->locuri[i];
				}
				delete[]this->locuri;
			}
			this->nrLocuri = nrLocuri;
			this->locuri = new Loc * [this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++) {
				this->locuri[i] = new Loc(*locuri[i]);
			}
		}
	}

	Zona(const Zona& z) :idZona(z.idZona) {
		if (z.numeZona.size() >= 3)
		{
			this->numeZona = z.numeZona;
		}
		else {
			this->numeZona = "Peluza";
		}

		if (z.nrLocuri > 0 && z.locuri != NULL) {
			this->nrLocuri = z.nrLocuri;
			this->locuri = new Loc * [this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++) {
				this->locuri[i] = new Loc(*z.locuri[i]);
			}
		}
		else
		{
			this->nrLocuri = 0;
			this->locuri = NULL;
		}
	}

	Zona& operator= (const Zona& z) {
		if (this != &z) {
			if (this->locuri != NULL) {
				for (int i = 0; i < this->nrLocuri; i++) {
					delete this->locuri[i];
				}
				delete[]this->locuri;
			}
			if (z.numeZona.size() >= 3)
			{
				this->numeZona = z.numeZona;
			}
			else {
				this->numeZona = "Peluza";
			}

			if (z.nrLocuri > 0 && z.locuri != NULL) {
				this->nrLocuri = z.nrLocuri;
				this->locuri = new Loc * [this->nrLocuri];
				for (int i = 0; i < this->nrLocuri; i++) {
					this->locuri[i] = new Loc(*z.locuri[i]);
				}
			}
			else
			{
				this->nrLocuri = 0;
				this->locuri = NULL;
			}
		}
		return *this;
	}

	int nrLocuriOcupate() {
		int nr = 0;
		for (int i = 0; i < this->nrLocuri; i++) {
			if (this->locuri[i]->getEsteOcupat() == 1) {
				nr++;
			}
		}
		return nr;
	}

	int nrLocuriRamaseLibere() {
		return nrLocMaxim * nrRandMaxim - nrLocuriOcupate();
	}

	friend ostream& operator<<(ostream& out, const Zona& z) {
		cout << "Id zona: " << z.idZona << endl;
		out << "Denumire Zona: " << z.numeZona << endl;
		out << "Numar Locuri: " << z.nrLocuri << endl;
		out << "---------------------LOCURI---------------------" << endl;
		for (int i = 0; i < z.nrLocuri; i++) {
			out << *z.locuri[i] << endl;
		}
		cout << "---------------------LOCURI---------------------" << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Zona& z) {
		cout << "Denumire Zona: ";
		in >> ws;
		getline(in, z.numeZona);
		cout << "Numar Locuri: ";
		in >> z.nrLocuri;
		if (z.nrLocuri > 0) {
			if (z.locuri != NULL) {
				for (int i = 0; i < z.nrLocuri; i++) {
					delete z.locuri[i];
				}
				delete[]z.locuri;
			}
			cout << "---------------------LOCURI---------------------" << endl;
			z.locuri = new Loc * [z.nrLocuri];
			for (int i = 0; i < z.nrLocuri; i++) {
				Loc aux;
				in >> aux;
				z.locuri[i] = new Loc(aux);
			}
			cout << "---------------------LOCURI---------------------" << endl;
		}
		return in;
	}

	Loc& operator[](int poz) {
		if (poz >= 0 && poz < this->nrLocuri) {
			return *this->locuri[poz];
		}
		else {
			Loc l;
			return l;
		}
	}

	bool operator !() {
		return this->nrLocuri > 0;
	}
};
int Zona::numarator = 1;
