#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <windows.h> 
using namespace std;

#include "user.h"
#include "computer.h"
#include "shop.h"

class game {

public:

	game()
	{
		um = 0; cm = 0;
	};

	void playgame(int num, bool ed);

	int inputtotal();

	void gameclean();

	void gameover();

	void winmsg(int player);

	int getum()
	{
		return um;
	};

	void markadd()
	{
		userplayer.settrick(1); userplayer.setmoney(5);
	};

	void shopclean();

	void getuserinfo();

	bool geted();

private:

	string setstring(int num);

	int um;

	int cm;

	user userplayer;

	computer computerplayer;

	shop gameshop;

};
