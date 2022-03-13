#include "math.h"

void startRand(){
	srand((unsigned) time(0));
}

int randomNumber(){
	int rNumber{rand() % 2};
	return rNumber;
}