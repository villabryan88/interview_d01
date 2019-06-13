#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	tankPush(tank, 50);
	tankPop(tank);
	tankPush(tank, 940);
	for (int i = 0; i <= 10; i++)
		tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 10);
	tankPop(tank);
	tankPush(tank, 10);
	tankPush(tank, 50);
	tankPop(tank);
	for (int i = 0; i <= 10; i++)
		tankPush(tank, 100);;
	tankPush(tank, 100);
	tankPush(tank, 10);
	tankPush(tank, 10);
	tankPush(tank, 50);
	tankPop(tank);
	for (int i = 0; i <= 10; i++)
		tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 10);	
	for (int i = 0; i < 45; i++)
		tankPop(tank);

	tankPush(tank, 0);
	tankPush(tank, 0);
	tankPush(tank, 10);
	tankPop(tank);
	tankPush(tank, 10);
	tankPop(tank);
	tankPop(tank);
	return (0);
}



// Function used for the test
// Don't go further :)
