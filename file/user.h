#pragma once
#include <iostream> 
using namespace std;

class user {

public:

	user()
	{
		trick = 3; money = 150;
	};

	int userinput(bool ed);

	int usergame(int total, bool ed);

	void settrick(int num)
	{
		trick += num;
	};

	int gettrick()
	{
		return trick;
	};

	void setmoney(int num)
	{
		money += num;
	};

	int getmoney()
	{
		return money;
	};

private:

	bool istrick();

private:

	int trick;

	int money;

};


