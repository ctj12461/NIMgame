#include "stdafx.h"
#include "game.h"


#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <windows.h> 
using namespace std;

#include "game.h"
#include "user.h"
#include "computer.h"

#define UP 0   //用户 
#define CP 1   //电脑 

#define COST 1
#define LOTTERY 2 
#define RECHARGE 3
#define EXIT 4 

void game::playgame(int num, bool ed) {

	while (true) {

		num = userplayer.usergame(num, ed);

		if (num <= 0) {

			game::winmsg(UP);
			um++;

			markadd();

			system("PAUSE");

			return;
		}

		num = computerplayer.computergame(num, ed);

		if (num <= 0) {

			game::winmsg(CP);
			cm++;

			system("PAUSE");

			return;
		}

	}

}

int game::inputtotal() {   //总数输入检查函数 

	int a;

	cout << "Press the total( Or input '-1' to exit , input '-2' to back):" << endl;

	do {

		cin >> a;

		if (a < -2) {

			cout << "Please input the total LESS THAN 0!" << endl;

		}
		else if (a > 1000) {

			cout << "Plaese don't input the total MORE THAN 1000!" << endl;

		}
		else {

			return a;

		}

	} while (a < -2 || a > 1000);

}

void game::gameclean() {    //每局游戏后的清屏操作 

	system("CLS");

	cout << "                              **********NIM**********" << endl;
	cout << endl;
	cout << "          Start" << endl;
	cout << "-------------------------------------------------------------------------------------";
	cout << "PLease input a number to begin game.            -------------------------------" << endl;         //记分牌 
	cout << "Only can input 1 - 2 or 1 - 7 once.             -  User's mark: " << "    " << um << setstring(um) << endl;
	cout << "You can use the trick on the game.              -  Computer's mark: " << cm << setstring(cm) << endl;
	cout << "e: easy d: difficult                            -------------------------------" << endl;
	cout << "-------------------------------------------------------------------------------------";
	cout << endl;

}

void game::gameover() {   //游戏结束时的函数 

	MessageBox(NULL, TEXT("Thank you for you play 'NIM'"), TEXT("NIM"), MB_ICONINFORMATION + MB_OK);

	system("PAUSE");
	exit(0);
}

string game::setstring(int num) {    //确定记分牌边缘与分数的间隔的字符串的函数 

	if (num <= 9) {
		return "         -";
	}
	else if (num <= 99 && num >= 10) {
		return "        -";
	}
	else if (num <= 999 && num >= 100) {
		return "       -";
	}
	else if (num <= 9999 && num >= 1000) {
		return "      -";
	}
}

void game::winmsg(int player) {

	if (player == UP) {

		if (MessageBox(NULL, TEXT("user is WINNER"), TEXT("NIM"), MB_ICONINFORMATION + MB_OKCANCEL) == IDCANCEL) {

			gameover();

		}

	}
	else if (player == CP) {

		if (MessageBox(NULL, TEXT("computer is WINNER"),TEXT("NIM"), MB_ICONINFORMATION + MB_OKCANCEL) == IDCANCEL) {

			gameover();

		}

	}

}

void game::shopclean() {

	int in = 0;  //索引 
	int tr = 0;  //用户之后要加的道具 
	int mo = 0;  //用户之后要加的钱 

	int usmo = userplayer.getmoney();    //用户之前的钱 

	do {

		in = gameshop.clean();

		if (in == COST) {

			tr = gameshop.shoptrick(usmo);

			usmo = tr * 20;

			userplayer.setmoney(-usmo);

			userplayer.settrick(userplayer.gettrick() + tr);

		}
		else if (in == LOTTERY) {

			mo = gameshop.lottery(usmo);

			mo = mo - 20;

			userplayer.setmoney(mo);

		}
		else if (in == RECHARGE) {

			mo = gameshop.recargar();

			userplayer.setmoney(mo);

		}

	} while (in != EXIT);

}

void game::getuserinfo() {

	cout << "     Tricks : " << userplayer.gettrick() << endl;
	cout << "     Money :  " << userplayer.getmoney() << endl;
	cout << endl;

	system("PAUSE");
	system("CLS");

}

bool game::geted() {

	string ed;

	cout << "Please input difficulty." << endl;
	cin >> ed;

	do {

		if (ed[0] == 'e' || ed[0] == 'E') {

			return false;

		}
		else if (ed[0] == 'd' || ed[0] == 'D') {

			return true;

		}
		else {

			cout << "Error." << endl;

		}

	} while (true);

}