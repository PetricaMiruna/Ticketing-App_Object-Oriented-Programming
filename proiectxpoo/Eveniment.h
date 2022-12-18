#pragma once
#pragma warning (disable:4996)
#include <iostream>
using namespace std;

class Eveniment
{
private:
	char* tip_eveniment;
	string nume;//numele filmului, meciul[]
	string data_eveniment;
	string ora;

public:
	
	Eveniment() {
		nume = "Necunoscut";
		data_eveniment="Necunoscuta";
		ora = "Necunoscuta";
		tip_eveniment = new char[1];
		tip_eveniment[0] = '\0';
		
	}

	Eveniment( char* tip_eveniment, string nume, string data_eveniment, string ora) {
		this->nume = nume;
		this->data_eveniment = data_eveniment;
		this->ora = ora; 
		this->tip_eveniment = new char[strlen(tip_eveniment) + 1];
		strcpy(this->tip_eveniment, tip_eveniment);
		
	}
	Eveniment(Eveniment& e) {
		this->nume = e.nume;
		this->data_eveniment = e.data_eveniment;
		this->ora = e.ora;
		this->tip_eveniment = new char[strlen(e.tip_eveniment) + 1];
		strcpy(this->tip_eveniment, e.tip_eveniment);
	}

	Eveniment& operator = (const Eveniment & e){
		if (this != &e) {
			this->nume = e.nume;
			this->data_eveniment = e.data_eveniment;
			this->ora = e.ora;
			this->tip_eveniment = new char[strlen(e.tip_eveniment) + 1];
			strcpy(this->tip_eveniment, e.tip_eveniment);
		}
		return *this;
	}

	bool modifica_data() {
		string a;
		cout << "ati introdus data evenimentului corect?";
		cin >> a;
		if (a == "da"||a=="DA"||a=="Da")
			return true;
		else return false;
	}

	bool modifica_ora() {
		string a;
		cout << "ati introdus ora evenimentului corect?";
		cin >> a;
		if (a == "da" || a == "DA" || a == "Da")
			return true;
		else return false;
	}

	Eveniment operator*(const Eveniment &e) {
		Eveniment copie = *this;
		copie.data_eveniment = copie.data_eveniment + ", " + e.data_eveniment;
		return copie;
	}
	Eveniment operator/(const Eveniment& e) {
		Eveniment copie = *this;
		copie.ora = copie.ora + ", " + e.ora;
		return copie;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	void setOra(string ora) {
		this->ora = ora;
	}
	void SetData(string data_eveniment) {
		this->data_eveniment = data_eveniment;
	}
	
	void setTip(char* tip_eveniment) {
		if (tip_eveniment != nullptr) {
				this->tip_eveniment = new char[strlen(tip_eveniment) + 1];
				strcpy(this->tip_eveniment, tip_eveniment);
		}
		
	}

	string getNume() {
		return this->nume;
	}
	string getData() {
		return this->data_eveniment;
	}
	string getOra() {
		return this->ora;
	}
	char* getTip() {
		return this->tip_eveniment;
	}

	friend ostream& operator<<(ostream &os, const Eveniment &e) {
		os << "nume eveniment " << e.nume << endl;
		os << "data evenimentului " << e.data_eveniment << endl;
		os << "ora evenimentului " << e.ora << endl;
		os << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Eveniment& e) {
		cout << "numele evenimentului:"; is >> e.nume;
		cout << "data evenimentului:"; is >> e.data_eveniment;
		while (!e.modifica_data()) {
			cout << "data evenimentului:";
			is >> e.data_eveniment;
		}
		cout << "ora evenimentului:"; is >> e.ora;
		while (!e.modifica_ora()) {
			cout << "ora evenimentului:";
			is >> e.ora;
		}
		return is;
	}

	~Eveniment() {
			delete[]this-> tip_eveniment;
	}
};
