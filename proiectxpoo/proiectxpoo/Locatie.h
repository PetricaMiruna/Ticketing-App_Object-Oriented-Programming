#pragma once
#pragma warning (disable:4996)
#include <iostream>
using namespace std;



//categorie loc: 
//fotbal: tribuna1 -0, tribuna2-1, peluza-2
//film: normal-0, vip-1
//teatru:cat1-0, cat2-1, loja-2

class Locatie {
private:
	int nrlocuri;
	int** locuri;
	int nr_linii;
	int nr_coloane;
	bool sala_disponibila;//1-e disponibila daca mai are locuri libere, 0-nu e disp
	string tip_locatie;//meci,film, teatru
	string categorie_loc;//tribune, sali, loje

public:
	Locatie() {
		nrlocuri = 100;
		locuri = nullptr;
		sala_disponibila =true;
		tip_locatie = "Necunoscuta";
		categorie_loc = "Necunoscuta";
		nr_linii=20;
		nr_coloane=20;
	}

	Locatie(int nrlocuri, int nr_linii, int nr_coloane, bool sala_disponibila) {
		this->nrlocuri = nrlocuri;
		this->nr_linii = nr_linii;
		this->nr_coloane = nr_coloane;
		locuri_libere();
		this->sala_disponibila = sala_disponibila;

	}


	Locatie(Locatie& l) {
		this->nrlocuri = l.nrlocuri;
		this->sala_disponibila = l.sala_disponibila;
		this->tip_locatie = l.tip_locatie;
		this->categorie_loc = l.categorie_loc;
		this->nr_linii = l.nr_linii;
		this->nr_coloane = l.nr_coloane;
	}

	Locatie& operator=(const Locatie& l) {
		if (this == &l) {
			return *this;
		}
		else{
			this->nrlocuri = l.nrlocuri;
			this->sala_disponibila = l.sala_disponibila;
			this->tip_locatie = l.tip_locatie;
			this->categorie_loc = l.categorie_loc;
			this->nr_linii = l.nr_linii;
			this->nr_coloane = l.nr_coloane;
		}
		return *this;
	}

	void setTipLocatie(string tip_locatie) {
		this->tip_locatie = tip_locatie;
	}
	void setCategorie(string categorie_loc) {
		this->categorie_loc = categorie_loc;
	}

	void setNrlinii(int nr_linii) {
		if (nr_linii > 0) {
			this->nr_linii = nr_linii;
		}
		else {
			cout << "numarul de linii introdus este invalid" << endl;
		}

	}

	void setNrcoloane(int nr_coloane) {
		if (nr_coloane > 0) {
			this->nr_coloane = nr_coloane;
		}
		else {
			cout << "numarul de coloane introdus este invalid" << endl;
		}
	}
	int getNrColoane() {
		return this->nr_coloane;
	}
	int getNrlinii() {
		return this->nr_linii;
	}
	string getTiplocatie() {

		return this->tip_locatie;
	}
	string getCategorie() {

		return this->categorie_loc;
	}

	void afiseaza_nrlocuri() {
		cout << this->nrlocuri;
	}

	/*int getTip_Locatie() {
		cout << endl;
		if (this->tip_locatie == 0)
			cout << "bilet la meci:";
		if (this->tip_locatie == 1)
			cout << "bilet la film:";
		if (this->tip_locatie == 2)
			cout << "bilet la teatru:";
		return this->tip_locatie;
	}
	*/

	/*int getCategorie() {

		if (this->tip_locatie == 0) {
			cout << endl;
			if (this->categorie_loc == 0) {
				cout << " tribuna1, ";
			}
			if (this->categorie_loc == 1) {
				cout << "tribuna2, ";
			}
			if (this->categorie_loc == 2) {
				cout << " peluza, ";
			}
		}
		if (this->tip_locatie == 1) {
			if (this->categorie_loc == 0) {
				cout << " bilet normal, ";
			}
			if (this->categorie_loc == 1) {
				cout << " VIP, ";
			}
		}
		if (this->tip_locatie == 2) {
			if (this->categorie_loc == 0) {
				cout << "categoria1, ";
			}
			if (this->categorie_loc == 1) {
				cout << " categoria2, ";
			}
			if (this->categorie_loc == 2) {
				cout << " loja, ";
			}
		}
		return this->categorie_loc;
	}
	*/


	/*void setTipLocatie(int tip_locatie) {
		this->tip_locatie = tip_locatie;
		if (tip_locatie != 0 && tip_locatie != 1 && tip_locatie != 2) {
			cout << "numar invalid" << endl;
			cout << "Alegeti 1, 2 sau 3" << endl;
		}
	}

	void setCategorie(int categorie) {

		if (categorie != 0 && categorie != 1 && categorie != 2) {
			cout << "numar invalid" << endl;
			cout << "Alegeti 1, 2 sau 3" << endl;

		}
		this->categorie_loc = categorie;
	}
	*/

	bool operator!() {
		return sala_disponibila;
	}

	Locatie operator--() {
		nrlocuri--;
		return *this;
	}
	Locatie operator--(int n) {
		Locatie copie = *this;
		this->nrlocuri--;
		return copie;
	}
	
	
	friend istream& operator>>(istream& is, Locatie& l) {
		cout << "tip locatie:"; is >> l.tip_locatie;
		cout << endl;
		cout << "categorie locatie:"; is >> l.categorie_loc;
		cout << endl;
		/*cout << "numar de linii:"; is >> l.nr_linii;
		cout << endl;
		cout << "numar coloane:"; is >> l.nr_coloane;
		cout << endl;
		*/
		
		return is;
		
	}

	friend ostream& operator << (ostream& os, const Locatie& l) {
		os << "numarul de locuri ramase in sala:" << l.nrlocuri << endl;
		os << "sala_disponibila:";
		if (l.sala_disponibila) cout << "da";
		else cout << "nu";
		cout << endl;
		os << "tip locatie:";
		os<< l.tip_locatie << endl;
		os << "categorie locatie:";
		os<< l.categorie_loc << endl;
		return os;
	}

	void locuri_libere() {
		locuri = new int* [nr_linii];
		for (int i = 0; i < nr_linii; i++) {
			locuri[i] = new int[nr_coloane];
		}
		for (int i = 0; i < nr_linii; i++) {
			for (int j = 0; j < nr_coloane; j++) {
				locuri[i][j] = 0;
			}
		}
	
	}

	bool ocupare_loc(int rand, int coloana) {
		
		if (locuri[rand - 1][coloana - 1] == 0) {
			locuri[rand - 1][coloana - 1] = 1;
			return true;
		}
		else return false;
	}

	bool verifica_rand(int rand) {
		if (rand > (nr_linii))
			return false;
		else return true;
	}

	bool verifica_loc(int loc) {
		if (loc > (nr_coloane))
			return false;
		else return true;
	}


	~Locatie() {

	}

};