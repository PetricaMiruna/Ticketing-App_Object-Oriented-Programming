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
	Eveniment e1{(char*)"tipuuul", "numeee", "data23", "ora12"};
	Eveniment e2;
	cin >> e2;
	e1=e1* e2;
	cout << e1;
	cout << endl;
	cout<< e1 / e2;
	//e2 = e1;
	//cout << e2;
	Locatie l2{ 300,30,6,1 };
	//Locatie l2; cin >> l2;
	Locatie l3;
	l3 = --l2;
	//cout << l3;
	cout << endl;
	l3--;
	//cout << l3 << endl;
	Locatie l4 = l3;
	//cout << l4;
	Bilet b1{30};
	Bilet b2{50};
	Bilet b3;
	b3 = b1 + b2;
	//cout << b3;
	//l2.setNrlinii(-9);
	//cout << l2;
	//cin >> e2;
	//cin >> e2;
	//e2.setTip((char*)"da");
	//cout << e2.getTip();
	//cout << endl;
	/*Locatie l1{300,6,7,false};
	cout << endl;
	cout<<l1.operator!();
	cout << endl;
	cout << l1;
	cout << endl;
	cin >> l1;*/
	
	
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
