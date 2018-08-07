#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

class computer {

public:

	computer()
	{
		srand(time(NULL));
	};

	int computergame(int total, bool ed);

private:

	int select(int num, bool ed);

	int rad(int n)
	{
		return rand() % n;
	};

};
