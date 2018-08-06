#include "stdafx.h"
#include "shop.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

#include "shop.h"

#define COST 1
#define LOTTERY 2 
#define RECHARGE 3
#define EXIT 4 

int shop::shoptrick(int money) {

	int a = 0;
	int num = 0;

	cout << "                              **********NIM**********" << endl;
	cout << endl;
	cout << "          Shop" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;

	do {

		cout << "How many tricks do you want? (Input \'0\' to exit) " << endl;
		cin >> a;

		if (a * 20 > money) {

			cout << "Lack of money." << endl;

			continue;

		}

		if (a < 0) {

			cout << "Error" << endl;

			continue;

		}

		num = num + a;

	} while (a != 0);

	system("PAUSE");

	system("CLS");

	return num;

}

int shop::lottery(int money) {

	int n1 = 0, n2 = 0;
	int getmo = 0;

	cout << "                              **********NIM**********" << endl;
	cout << endl;
	cout << "          Shop" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;

	if (money < 20) {

		cout << "Lack of money." << endl;

		system("PAUSE");

		system("CLS");

		return 0;

	}

	for (int i = 1; i <= 100; i++) {   //抽奖过程 

		n1 = rad(5);
		n2 = rad(5);

		cout << "                              **********NIM**********" << endl;
		cout << endl;
		cout << "          Shop" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;

		cout << "Lotter >>>    " << n1 << "     |     " << n2 << endl;

		system("CLS");

	}

	cout << "                              **********NIM**********" << endl;
	cout << endl;
	cout << "          Shop" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Lottery >>>    " << n1 << "     |     " << n2 << endl;

	if (n1 == n2) {

		cout << "You get $500!!!" << endl;

		getmo += 500;

	}
	else {

		cout << "You don't get $500!!!" << endl;
	}

	system("PAUSE");

	system("CLS");

	return getmo;

}

int shop::recargar() {

	int money = 0;

	cout << "                              **********NIM**********" << endl;
	cout << endl;
	cout << "          Shop" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Please input the recharge amount." << endl;

	cin >> money;

	cout << "Please enter the activation code." << endl;

	string code1, code2 = "GI8NF-NEF08";

	cin >> code1;

	if (code1 == code2) {

		cout << "Activate the success." << endl;

		system("PAUSE");
		system("CLS");

		return money;

	}
	else {

		cout << "Activation failed. Add QQ 1246186412 to get the activation code." << endl;

		system("PAUSE");
		system("CLS");

		return 0;
	}

}

int shop::clean() {

	int index = 0;

	cout << "                              **********NIM**********" << endl;
	cout << endl;
	cout << "          Shop" << endl;
	cout << "-------------------------------------------------------------------------------------";
	cout << "       Menu" << endl;
	cout << "     1.Cost tricks ( 1 trick = $20 )" << endl;
	cout << "     2.Lottery ( 1 trick = $20 )" << endl;
	cout << "     3.Recharge" << endl;
	cout << "     4.Exit" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Please input the index." << endl;

	do {

		cin >> index;

		if (index < COST || index > EXIT) {

			cout << "Error" << endl;

		}

	} while (index < COST || index > EXIT);

	for (int i = 0; i <= 9000000; i++) {}  //空循环，延时 

	system("CLS");

	return index;

}