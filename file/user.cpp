#include "stdafx.h"
#include "user.h"

#include <iostream>

#define tricknum 3  // 道具兑换的数量，1道具=3分数 

using namespace std;

bool user::istrick() {   //确定道具是否被用过 

	if (trick == 0) {
		cout << "Trick can't use again" << endl;
		return false;
	}
	else {
		cout << "Trick used." << endl;
		trick -= 1;
		return true;
	}

}

int user::userinput(bool ed) {   //用户输入检查函数 

	int a;

	int high;

	if (ed) {

		high = 7;

	}
	else {

		high = 2;

	}

	do {

		cin >> a;

		if (a < 0) {

			cout << "------Don't input a number LESS THAN 0!" << endl;

		}
		else if (a > high) {

			cout << "------Don't input a number MORE THAN " << high << "!" << endl;

		}
		else if (a == 0) {

			if (trick) {

				trick--;

				cout << "Tricks : " << trick << endl;

				return 0;

			}

		}
		else {

			return a;

		}
	} while (a != 1 || a != high);

}

int user::usergame(int total, bool ed) {   //用户游戏过程 

	int a = 0;

	cout << "user >>>";

	a = userinput(ed);

	total -= a;

	cout << "------total :" << total << endl;

	return total;

}