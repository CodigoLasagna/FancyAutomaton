#ifndef RULES_H
#define RULES_H

#include <iostream>
#include "rules.h"
int select_type(int ruletype, int* grid, size_t x, size_t y, size_t height){
	bool live{};
	switch(ruletype){
		case(0):
			live = GameOfLife(grid, x, y, height);
		break;

		case(1):
			live = Rule30(grid, x, y, height);
		break;

		case(2):
			live = Rule94(grid, x, y, height);
		break;

		case(3):
			live = Rule90(grid, x, y, height);
		break;
		case 5:
			live = snowflake(grid, x, y, height);
		break;
	}
	return live;
}

int select_type(int ruletype, int* grid, size_t x, size_t y, size_t height, int* rules){
	bool live{};
		live = selfImpl(grid, x, y, height, rules);
	return live;
}

int snowflake(int* grid, size_t x, size_t y, size_t height){
	bool live{};
	int cellNumber{};

	cellNumber = (grid[(x+1)*height+y] 	   + grid[x*height+(y+1)]+
				  grid[(x-1)*height+y] 	   + grid[x*height+(y-1)]+
				  grid[(x+1)*height+(y+1)] + grid[(x+1)*height+(y-1)]+
				  grid[(x-1)*height+(y-1)] + grid[(x-1)*height+(y+1)]);
	if (grid[x*height+y] == 0){
		if(cellNumber == 1){
			live = true;
		}else{
			live = false;
		}
	}else if (grid[x*height+y] == 1){
		live = true;
	}
	return live;
}

int wolfram(int* grid, size_t x, size_t y, size_t height, int* rules){
	bool live{};
	int cellNumber{};

	if (grid[x*height+y] == 1){
		if((grid[(x-1)*height+y]+grid[(x+1)*height+y]) == 2){
			live = rules[0];
		}else if((grid[(x-1)*height+y]) == 1){
			live = rules[1];
		}else if((grid[(x+1)*height+y]) == 1){
			live = rules[4];
		}
		else if((grid[(x-1)*height+y]+grid[(x+1)*height+y]) == 0){
			live = rules[5];
		}
	}else{
		if((grid[(x-1)*height+y]+grid[(x+1)*height+y]) == 2){
			live = rules[2];
		}else if((grid[(x-1)*height+y]) == 1){
			live = rules[3];
		}else if((grid[(x+1)*height+y]) == 1){
			live = rules[6];
		}
		else if((grid[(x-1)*height+y]+grid[(x+1)*height+y]) == 0){
			live = rules[7];
		}
	}
	//std::cout << live;

	return live;
}

int GameOfLife(int* grid, size_t x, size_t y, size_t height){
	bool live{};
	int cellNumber{};

	cellNumber = (grid[(x+1)*height+y] 	   + grid[x*height+(y+1)]+
				  grid[(x-1)*height+y] 	   + grid[x*height+(y-1)]+
				  grid[(x+1)*height+(y+1)] + grid[(x+1)*height+(y-1)]+
				  grid[(x-1)*height+(y-1)] + grid[(x-1)*height+(y+1)]);
	//std::cout << cellNumber;
	if (grid[x*height+y] == 1){
		if (cellNumber == 3 || cellNumber == 2){
			live = true;
		}else{
			live = false;
		}
	}else{
		if (cellNumber == 3){
			live = true;
		}
	}
	//std::cout << live;

	return live;
}

int Rule30(int* grid, size_t x, size_t y, size_t height){
	bool live{};
	int* rule30 = new int[]{0, 0, 0, 1, 1, 1, 1, 0};
	
	live = wolfram(grid, x, y, height, rule30);
	return live;
}

int Rule94(int* grid, size_t x, size_t y, size_t height){
	bool live{};
	int* rule94 = new int[]{0, 1, 0, 1, 1, 1, 1, 0};
	
	live = wolfram(grid, x, y, height, rule94);
	return live;
}
int Rule90(int* grid, size_t x, size_t y, size_t height){
	bool live{};
	int* rule90 = new int[]{0, 1, 0, 1, 1, 0, 1, 0};
	
	live = wolfram(grid, x, y, height, rule90);
	return live;
}


int selfImpl(int* grid, size_t x, size_t y, size_t height, int* rules){
	bool live{};
	
	live = wolfram(grid, x, y, height, rules);
	return live;
}

#endif