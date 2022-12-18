#pragma once
#include"zona.h";

class Locatie {
	char* nume;
	string adresa;
	int nrScene;
	float suprafata;
	int nrZone;
	Zona** zone;

public:
	Locatie() {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->adresa = "Necunoscut";
		this->nrScene = 0;
		this->suprafata = 0;
		this->nrZone = 0;
		this->zone = NULL;
	}
	Locatie(const char* nume, string adresa, int nrScene, float suprafata, int nrZone, Zona** zone) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->adresa = adresa;
		this->nrScene = nrScene;
		this->suprafata = suprafata;
		this->nrZone = nrZone;
		this->zone = new Zona * [this->nrZone];
		for (int i = 0; i < this->nrZone; i++) {
			this->zone[i] = new Zona(*zone[i]);
		}
	}

	~Locatie() {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
		if (this->zone != NULL) {
			for (int i = 0; i < nrZone; i++) {
				delete this->zone[i];
			}
		}
		delete[]this->zone;
	}


	char* getNume() {
		char* aux = new char[strlen(nume) + 1];
		strcpy(aux, nume);
		return aux;
	}

	string getAdresa() {
		return this->adresa;
	}

	int getNrScene() {
		return this->nrScene;
	}

	float getSuprafata() {
		return this->suprafata;
	}

	int getNrZone() {
		return this->nrZone;
	}

	Zona** getZone() {
		return this->zone;
	}

	void setNume(const char* nume) {
		if (strlen(nume) > 3) {
			if (this->nume != NULL) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
	}


	void setAdresa(string adresa) {
		if (adresa.size() >= 3) {
			this->adresa = adresa;
		}
	}

	void setNrScene(int nrScene) {
		if (nrScene > 0) {
			this->nrScene = nrScene;
		}
	}

	void setSuprafata(float suprafata) {
		if (suprafata > 0) {
			this->suprafata = suprafata;
		}
	}


	void setZone(int nrZone, Zona** zone) {
		if (nrZone > 0 && zone != NULL) {
			if (this->zone != NULL) {
				for (int i = 0; i < this->nrZone; i++) {
					delete this->zone[i];
				}
				delete[]this->zone;
			}
			this->nrZone = nrZone;
			this->zone = new Zona * [this->nrZone];
			for (int i = 0; i < this->nrZone; i++) {
				this->zone[i] = new Zona(*zone[i]);
			}
		}
	}

	Locatie(const Locatie& l) {
		this->nume = new char[strlen(l.nume) + 1];
		strcpy(this->nume, l.nume);
		this->adresa = l.adresa;
		this->nrScene = l.nrScene;
		this->suprafata = l.suprafata;
		this->nrZone = l.nrZone;
		this->zone = new Zona * [this->nrZone];
		for (int i = 0; i < this->nrZone; i++) {
			this->zone[i] = new Zona(*l.zone[i]);
		}
	}

	Locatie& operator=(const Locatie& l) {
		if (this != &l) {
			if (this->nume != NULL) {
				delete[]this->nume;
			}
			if (this->zone != NULL) {
				for (int i = 0; i < nrZone; i++) {
					delete this->zone[i];
				}
			}
			delete[]this->zone;
			this->nume = new char[strlen(l.nume) + 1];
			strcpy(this->nume, l.nume);
			this->adresa = l.adresa;
			this->nrScene = l.nrScene;
			this->suprafata = l.suprafata;
			this->nrZone = l.nrZone;
			this->zone = new Zona * [this->nrZone];
			for (int i = 0; i < this->nrZone; i++) {
				this->zone[i] = new Zona(*l.zone[i]);
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Locatie& l) {
		out << "Denumire locatie: " << l.nume << endl;
		out << "Adresa locatie: " << l.adresa << endl;
		out << "Numar Scene locatie: " << l.nrScene << endl;
		out << "Suprafata locatie: " << l.suprafata << endl;
		out << "Numar Zone: " << l.nrZone << endl;
		out << "||||||||||||||||||||||||||||||ZONE||||||||||||||||||||||||||||" << endl;
		for (int i = 0; i < l.nrZone; i++) {
			out << *l.zone[i] << endl;
		}
		out << "||||||||||||||||||||||||||||||ZONE||||||||||||||||||||||||||||" << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Locatie& l) {
		if (l.nume != NULL) {
			delete[]l.nume;
		}
		if (l.zone != NULL) {
			for (int i = 0; i < l.nrZone; i++) {
				delete l.zone[i];
			}
		}
		cout << "Denumire locatie: ";
		char aux[200];
		in >> ws;
		in.getline(aux, 199);
		l.nume = new char[strlen(aux) + 1];
		strcpy(l.nume, aux);

		cout << "Adresa locatie: ";
		in >> ws;
		getline(in, l.adresa);

		cout << "Numar Scene locatie: ";
		in >> l.nrScene;
		cout << "Suprafata locatie: ";
		in >> l.suprafata;
		cout << "Numar Zone locatie: ";
		in >> l.nrZone;
		cout << "Zonele din locatie: ";
		l.zone = new Zona * [l.nrZone];
		for (int i = 0; i < l.nrZone; i++) {
			Zona aux1;
			in >> aux1;
			l.zone[i] = new Zona(aux1);
		}
		return in;

	}

	float costInchiriereSala(int pretMpLei) {
		return this->suprafata * pretMpLei;
	}

	bool areSceneMultiple() {
		return this->nrScene > 1;
	}

	Locatie operator++(int) {
		Locatie aux = *this;
		this->suprafata++;
		return aux;
	}

	Locatie& operator++() {
		this->nrScene++;
		return *this;
	}

	Locatie operator *(float valSuprafata) {
		Locatie copie = *this;
		copie.suprafata *= valSuprafata;
		return copie;
	}
};