// proiectxpoo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning (disable:4996)
#include <iostream>
#include "Eveniment.h"
#include "Bilet.h"
#include "Locatie.h"

using namespace std;
int main()
{
	Bilet b1;
	Bilet b2;
	Locatie l1;
	Locatie l2;
	Eveniment e1;
	Eveniment e2;

	char* a;
	a = new char[30];
	strcpy(a, "tipeveniment");

	//cin >> b1;
	cout << endl;
	//cout << b1;
	cout << endl;
	//cout << e1.getData();
	cout << endl;
	//cout << e1.getNume();
	cout << endl;
	//cout << e1.getOra();
	cout << endl;
	//cout << e1.getTip();
	cout << endl;

	//e2.SetData("20.03.2022");
	//e2.setOra("18");
	//e2.setNume("Numeeveniment");
	//e2.setTip(a);

	//cout << e1.operator*(e2);
	cout << endl;
	//cout << e1.operator/(e2);
	cout << endl;
	//cout << e1.operator=(e2);
	cout << endl;

	//b2.setLoc(2);
	cout << endl;
	//b2.setRand(3);
	cout << endl;
	//cout << b1.getId();
	//cout << b1.getPret();
	//cout << b1.operator+(b2);
	cout << endl;
	//cout << b1.operator++();
	cout << endl;
	//cout << b1.operator=(b2);
	cout << endl;

	//cout << l1.getCategorie();
	cout << endl;
	//cout << l1.getNrColoane();
	cout << endl;
	//cout << l1.getNrlinii();
	cout << endl;
	//cout << l1.getTiplocatie();
	cout << endl;
	//l2.setCategorie("loje");
	//l2.setNrcoloane(12);
	//l2.setNrlinii(10);
	//l2.setTipLocatie("teatru");
	//cout << l2.getNrlinii();
	cout << endl;
	//cout << l2.getTiplocatie();
	cout << endl;
	//cout << l2.getNrColoane();
	cout << endl;
	//cout << l2.getCategorie();
	cout << endl;
	//cout << l1.operator!();
	cout << endl;
	//l1.operator--();
	//l1.operator--(3);
	cout << endl;
	cin >> b1;
	cout << endl;
	cout << b1;

	
	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
