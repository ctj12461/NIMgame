// NIMgame.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//Files-------------------------------------------
#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>

#include "game.h"

using namespace std;

//Predefined_Constant-------------------------------------------

#define START 1
#define SHOP 2
#define KNAPSACK 3
#define ABOUT 4
#define EXIT 5

//Public_Data-------------------------------------------

//run this program using the console pauser or add your own getch, system("pause") or input loop 

game nimgame;

//Functions_Prototype-------------------------------------------

void appstart();

int gamestart();

void playinggame();

void shopsth();

void knapsack();

void gameabout();

//Main_Function-------------------------------------------

int main(int argc, char** argv) {

	system("mode con cols=85 lines=25");  //改变宽高

	system("COLOR 06");

	srand(time(NULL));    //随机化 

	int in = 0; //菜单索引 

	appstart();

	while (true) {

		in = gamestart();

		if (in == START) {

			playinggame();

		}
		else if (in == SHOP) {

			shopsth();

		}
		else if (in == KNAPSACK) {

			knapsack();

		}
		else if (in == ABOUT) {

			gameabout();

		}
		else if (in == EXIT) {

			break;

		}

	}

	system("COLOR 09");

	cout << "Thank you for you play 'NIM'" << endl;
	system("PAUSE");
	return 0;
}

//Functions-------------------------------------------

void appstart() {

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                      ##    #     #####     ##         ##                 " << endl;
	cout << "                      # #   #       #       # #       # #                 " << endl;
	cout << "                      #  #  #       #       #  #     #  #                 " << endl;
	cout << "                      #   # #       #       #   #   #   #                 " << endl;
	cout << "                      #    ##       #       #    ###    #                 " << endl;
	cout << "                      #     #     #####     #     #     #                 " << endl;
	cout << endl;
	cout << endl;
	cout << "                             Version 5.2.0.0" << endl;
	cout << endl;
	cout << "                             ";

	system("pause");

	system("cls");

}

int gamestart() {

	int index = 0;

	cout << "                              **********NIM**********" << endl;
	cout << endl;
	cout << "          Main Interface" << endl;
	cout << "-------------------------------------------------------------------------------------";
	cout << "       Menu" << endl;
	cout << "     1.Start" << endl;
	cout << "     2.Shop" << endl;
	cout << "     3.Knapsack" << endl;
	cout << "     4.About" << endl;
	cout << "     5.Exit" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Please input the index." << endl;

	do {

		cin >> index;

		if (index < START || index > EXIT) {

			cout << "Error" << endl;

		}

	} while (index < START || index > EXIT);


	for (int i = 0; i <= 9000000; i++) {}  //空循环，延时 

	system("CLS");

	return index;
}

void playinggame() {

	int total = 0;

	while (true) {

		nimgame.gameclean();

		bool ed = nimgame.geted();

		while (true) {

			nimgame.gameclean();

			total = nimgame.inputtotal();

			if (total == -1) {

				system("CLS");

				return;

			}
			else if (total == -2) {

				system("CLS");

				break;

			}

			nimgame.playgame(total, ed);

		}

	}

}

void shopsth() {

	nimgame.shopclean();

}

void knapsack() {

	cout << "                              **********NIM**********" << endl;
	cout << endl;
	cout << "          Knapsack" << endl;
	cout << "-------------------------------------------------------------------------------------";
	nimgame.getuserinfo();

}

void gameabout() {

	cout << "                              **********NIM**********" << endl;
	cout << endl;
	cout << "          About" << endl;
	cout << "-------------------------------------------------------------------------------------";
	cout << "                                        NIM" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                           Ver 5.2.0.0 Release Version " << endl;
	cout << endl;
	cout << "                               By Ctj #2018-06-08#" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	system("PAUSE");
	system("CLS");

}

