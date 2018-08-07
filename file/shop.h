#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class shop {

public:

	int shoptrick(int money);

	int lottery(int money);

	int recargar();

	int clean();

private:

	int rad(int n)
	{
		return rand() % n;
	};

};