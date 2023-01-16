#pragma once
#pragma warning (disable:4996)
#include <iostream>
#include "Eveniment.h"
#include "Locatie.h"
using namespace std;

//tip bilet:0-meci, 1-film, 2-teatru

//categorie loc: 
//fotbal: tribuna1 -0, tribuna2-1, peluza-2
//film: normal-0, vip-1
//teatru:cat1-0, cat2-1, loja-2
class Bilet {
private:
	static int id;
	float pret;
	Locatie locatie;
	Eveniment eveniment;
	const int varsta_minima=5;
	int rand;
	int loc;
	int varsta;


public:
	
	Bilet():varsta_minima(5) {
		pret = 40;
		id = id * 5 + 35;
		varsta = 0;
		rand = 0;
		loc = 0;
	}


	Bilet( float pret, int rand, int loc, int varsta):varsta_minima(5) {
		this->pret = pret;
		this->id = id * 5 + 35;
		this->rand = rand;
		this->loc = loc;
		this->varsta = varsta;
	}


	static int getId() {
		return Bilet::id;
	}


	int getPret() {
		return this->pret;
	}
	
	void setLoc(int loc) {
		if(loc>0)
		this->loc = loc;
		else {
			cout << "locul este invalid" << endl;
		}
	}

	void setRand(int rand) {
		if (rand > 0) {
			this->rand = rand;
		}
		else {
			cout << "randul este invalid" << endl;
		}
	}

	
	
	Bilet(Bilet& b) {
		this->pret = b.pret;
		this->locatie = b.locatie;
		this->rand = b.rand;
		this->loc = b.loc;
		this->varsta = b.varsta;
		this->eveniment = b.eveniment;

	}

	~Bilet() {

	}

	Bilet &operator =( const Bilet& b) {
		if (this == &b) {
			return *this;
		}
		else{
			this->pret = b.pret;
			this->locatie = b.locatie;
			this->eveniment = b.eveniment;
			this->varsta = b.varsta;
			this->loc = b.loc;
			this->rand = b.rand;
		}
		return *this;
	}

	Bilet operator++() {
		pret = pret + 10;
		return *this;
	}
	Bilet operator++(int p) {
		Bilet copie = *this;
		this->pret = pret + 10;
		return copie;
	}

	Bilet operator+( const Bilet &b) {
		Bilet copie = *this;
		copie.pret = copie.pret + b.pret;
		return copie;
	}

	void reducere() {
		if (varsta <= varsta_minima) {
			pret = 0;
		}
	}


	friend ostream& operator<<(ostream &os, const Bilet&b) {
		os << b.eveniment << endl;
		os << "varsta:" << b.varsta << endl;
		os << "pret:" << b.pret << endl;
		os << "id:" << b.id << endl;
		os << "rand:" << b.rand << endl;
		os << "loc:" << b.loc << endl;
		os << b.locatie << endl;
		return os;
	}

	friend istream& operator>>(istream &is, Bilet& b) {
		is >> b.eveniment;
		cout << "varsta:"; is >> b.varsta;
		while (b.varsta < 0) {
			cout << "Introduceti din nou varsta:"; is >> b.varsta;
		}
		while (b.loc < 0) {
			cout << "Introduceti din nou locul:"; is >> b.loc;
		}
		b.reducere();
		b.locatie.locuri_libere();
		is >> b.locatie;
		cout << "rand:"; is >> b.rand;
		while (b.rand < 0|| !b.locatie.verifica_rand(b.rand)) {
			cout << "Introduceti din nou randul:"; is >> b.rand;
		}
		
		cout << "loc:"; is >> b.loc;
		while (b.loc < 0||!b.locatie.verifica_loc(b.loc)) {
			cout << "Introduceti din nou locul:"; is >> b.loc;
		}
		bool a = true;
		while (a) {
			if (b.locatie.ocupare_loc(b.rand, b.loc)) {
				cout << "Bilet rezervat!"<<endl;
				a = false;
			}
			else {
				cout << "Introduceti din nou" << endl;
				cout << "rand:";
				is >> b.rand;
				while (b.rand < 0) {
					cout << "rand:"; is >> b.rand;
				}
				cout << "loc:";
				is >> b.loc;
				while (b.loc < 0) {
					cout << "loc:"; is >> b.rand;
				}
			}
		}
		return is;
	}

};
int Bilet::id = 0;