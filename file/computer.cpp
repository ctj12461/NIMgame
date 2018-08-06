#include "stdafx.h"
#include "computer.h"

#include <iostream>
using namespace std;

#include "computer.h"

int computer::select(int num, bool ed) {   //µçÄÔÑ¡Ôñº¯Êı 

	int i = 0;
	int high = 0;
	int temp = 0;

	if (!ed) {

		high = 2;
		temp = 3;

	}
	else {

		high = 7;
		temp = 8;

	}

	temp = num % temp;

	if (temp != 0) {

		return temp;

	}
	else if (temp == 0) {

		return 1 + rad(high);

	}



}

int computer::computergame(int total, bool ed) {

	int radnum = 0;

	radnum = computer::select(total, ed);

	cout << "computer >>>" << radnum << endl;

	total -= radnum;

	cout << "------total :" << total << endl;

	return total;

}
