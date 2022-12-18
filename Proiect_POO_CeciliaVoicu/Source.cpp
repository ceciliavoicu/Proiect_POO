#include"bilet.h"

int main() {
	cout << "--------------------------------- LOC ---------------------------------" << endl;
	cout << "--------------------------------- LOC ---------------------------------" << endl;
	cout << "--------------------------------- LOC ---------------------------------" << endl;
	cout << "--------------------------------- LOC ---------------------------------" << endl;
	Loc l;
	cout << l.getNrLoc() << endl;
	cout << l.getNrRand() << endl;
	cout << l.getEsteOcupat() << endl;
	l.setNrLoc(10);
	l.setNrLoc(10002);
	l.setNrRand(2);
	l.setNrRand(23213);
	l.setEsteOcupat(1);
	cout << l.getNrLoc() << endl;
	cout << l.getNrRand() << endl;
	cout << l.getEsteOcupat() << endl;
	cout << endl << endl;
	Loc l1(1, 32, 1);
	cout << l1 << endl;

	Loc l2 = l;
	cout << endl << l2 << endl;
	l2 = l1;
	cout << endl << l2 << endl;

	if (l2.biletulEsteInUltimulRand()) {
		cout << "Biletul este in ultimul rand!" << endl;
	}
	else {
		cout << "Biletul nu  este in ultimul rand!" << endl;

	}
	Loc l3(99, 1, 1);
	if (l3.biletulEsteInUltimulRand()) {
		cout << "Biletul este in ultimul rand!" << endl;
	}
	else {
		cout << "Biletul nu  este in ultimul rand!" << endl;

	}

	if (l3.biletulEstePeMargine()) {
		cout << "Biletul este pe margine!" << endl;
	}
	else {
		cout << "Biletul nu este pe margine!" << endl;

	}
	if (l2.biletulEstePeMargine()) {
		cout << "Biletul este pe margine!" << endl;
	}
	else {
		cout << "Biletul nu este pe margine!" << endl;

	}


	if (l2 > l3) {
		cout << "Primul loc comparat este dupa ce de al doilea!" << endl;
	}
	else {
		cout << "Primul loc comparat este inainte de al doilea!" << endl;

	}

	if (l2 == l3) {
		cout << "Este vorba de acelasi loc!" << endl;
	}
	else {
		cout << "Este vorba de locuri diferite!" << endl;
	}

	//Loc l4;
	//cout << l4 << endl;
	//cin >> l4;
	//cout << endl<< l4 << endl << endl;
	Loc l5(43, 21, 1);
	cout << "--------------------------------- SFARSIT LOC ---------------------------------" << endl;
	cout << "--------------------------------- SFARSIT LOC ---------------------------------" << endl;
	cout << "--------------------------------- SFARSIT LOC ---------------------------------" << endl;
	cout << "--------------------------------- SFARSIT LOC ---------------------------------" << endl;

	cout << endl << endl << endl << endl;

	cout << "--------------------------------- ZONA ---------------------------------" << endl;
	cout << "--------------------------------- ZONA ---------------------------------" << endl;
	cout << "--------------------------------- ZONA ---------------------------------" << endl;
	cout << "--------------------------------- ZONA ---------------------------------" << endl;
	Zona z;
	cout << z.getNumeZona() << endl;
	cout << z.getNrLocuri() << endl;
	for (int i = 0; i < z.getNrLocuri(); i++) {
		cout << *z.getLocuri()[i] << endl;

	}

	z.setNumeZona("Tribuna 1 est");

	Loc* vectLocuri[3] = { &l1,&l3,&l5 };
	z.setLocuri(3, vectLocuri);
	cout << endl << endl;
	cout << z.getNumeZona() << endl;
	cout << z.getNrLocuri() << endl;
	for (int i = 0; i < z.getNrLocuri(); i++) {
		cout << *z.getLocuri()[i] << endl;
	}

	Zona z1("Tribuna centrala", 2, vectLocuri);
	cout << z1 << endl;

	Zona z2 = z;
	cout << endl << z2 << endl;
	z2 = z1;
	cout << endl << z1 << endl;

	Zona z3("VIP", 1, vectLocuri);
	cout << endl << z3 << endl;

	Zona z4("Tribuna a2a", 2, vectLocuri);
	cout << endl << z4 << endl;

	cout << endl << "Numar locuri ocupate: " << z1.nrLocuriOcupate() << endl;
	cout << endl << "Numar locuri ramase libere: " << z1.nrLocuriRamaseLibere() << endl;

	Zona z5;
	cout << z5 << endl;
	/*cin >> z5;
	cout << endl << z5 << endl;*/

	cout << z[2] << endl;
	cout << z[21] << endl;

	if (!z1) {
		cout << "Zona are cel putin un loc ocupat!" << endl;
	}
	else {
		cout << "Zona nu are niciun loc ocupat!" << endl;

	}

	if (!z5) {
		cout << "Zona are cel putin un loc ocupat!" << endl;
	}
	else {
		cout << "Zona nu are niciun loc ocupat!" << endl;

	}
	cout << "--------------------------------- SFARSIT ZONA ---------------------------------" << endl;
	cout << "--------------------------------- SFARSIT ZONA ---------------------------------" << endl;
	cout << "--------------------------------- SFARSIT ZONA ---------------------------------" << endl;
	cout << "--------------------------------- SFARSIT ZONA ---------------------------------" << endl;

	cout << "--------------------------------- LOCATIE ---------------------------------" << endl;
	cout << "--------------------------------- LOCATIE ---------------------------------" << endl;
	cout << "--------------------------------- LOCATIE ---------------------------------" << endl;
	cout << "--------------------------------- LOCATIE ---------------------------------" << endl;
	Locatie locat;
	cout << locat.getNume() << endl;
	cout << locat.getAdresa() << endl;
	cout << locat.getNrScene() << endl;
	cout << locat.getSuprafata() << endl;
	cout << locat.getNrZone() << endl;
	for (int i = 0; i < locat.getNrZone(); i++) {
		cout << *locat.getZone()[i] << endl;
	}

	cout << endl << endl;

	locat.setNume("Sala Trandafirului");
	locat.setNume("as");
	locat.setAdresa("Strada Trapezului, nr.12");
	locat.setSuprafata(3213.12);
	locat.setSuprafata(-543);
	locat.setNrScene(6);
	locat.setNrScene(-24);
	Zona* vectZone[4] = { &z,&z1,&z3,&z4 };
	locat.setZone(3, vectZone);


	cout << locat.getNume() << endl;
	cout << locat.getAdresa() << endl;
	cout << locat.getNrScene() << endl;
	cout << locat.getSuprafata() << endl;
	cout << locat.getNrZone() << endl;
	for (int i = 0; i < locat.getNrZone(); i++) {
		cout << *locat.getZone()[i] << endl;
	}

	cout << endl << endl << endl;
	Locatie locat1("Sala Sporturilor", "Bulevardul Unirii", 4, 5005.12, 4, vectZone);
	cout << locat1;
	cout << endl << endl << endl;
	Locatie locat2 = locat;
	cout << locat2;
	cout << endl << endl << endl;
	locat2 = locat1;
	cout << locat2;
	cout << endl << endl << endl;
	Locatie locat3("Razoare", "Strada Iernii, nr.12", 1, 434.2, 1, vectZone);
	cout << endl << locat3 << endl << endl;
	//cin >> locat3;
	//cout << endl << endl;
	//cout << locat3;
	cout << endl << endl << endl;

	cout << locat1.areSceneMultiple() << endl;
	if (locat1.areSceneMultiple()) {
		cout << "Locatia are mai multe scene!" << endl;
	}
	else {
		cout << "Locatia are doar o scena!" << endl;
	}
	if (locat3.areSceneMultiple()) {
		cout << "Locatia are mai multe scene!" << endl;
	}
	else {
		cout << "Locatia are doar o scena!" << endl;
	}

	cout << "Costul de inchiriere a salii " << locat1.getNume() << " : " << locat1.costInchiriereSala(30) << " lei" << endl;
	cout << "Costul de inchiriere a salii " << locat3.getNume() << " : " << locat3.costInchiriereSala(20) << " lei" << endl;

	Locatie locat4 = locat1++;
	cout << endl << endl << endl;

	cout << locat4 << endl << endl;
	cout << locat1 << endl << endl;


	Locatie locat5 = ++locat1;
	cout << endl << endl << endl;

	cout << locat5 << endl << endl;
	cout << locat1 << endl << endl;


	Locatie locat6 = locat5 * 1.5;
	cout << endl << endl << endl;

	cout << locat5 << endl << endl;
	cout << locat6 << endl << endl;


	cout << "--------------------------------- SFARSIT LOCATIE ---------------------------------" << endl;
	cout << "--------------------------------- SFARSIT LOCATIE ---------------------------------" << endl;
	cout << "--------------------------------- SFARSIT LOCATIE ---------------------------------" << endl;
	cout << "--------------------------------- SFARSIT LOCATIE ---------------------------------" << endl;
}

