#include "cellGrid.h"
#include <unistd.h>

//If u run windows
#include "clrScreenW.h"

void erase(int lines);

int main(){
	CellularAutomaton* cell_automata = new CellularAutomaton();
	int type{};
	int width{}; int height{};
	size_t margin{1};
	bool quickstart{};

	int* rules = new int[]{1, 0, 1, 1, 0, 1, 1, 0};

	std::cout << "type 1 to choose a simulation, type 0 to quickstart Conway's Game of life \n";
	std::cin >> quickstart;
	erase(1);
	if (quickstart == true){
		std::cout << "Type which simulation you would like to start\n";
		std::cout << "____________________________________________________________________________________\n\n";
		std::cout << "Conway's Game of life[0] | Wolfram setrules[1-3] R(30, 94, 90) | Wolfram custom[4]| \n";
		std::cin >> type;
		erase(5);
		std::cout << "Set your width and height, like this -> 21 21 \n";
		std::cin >> width >> height;
		erase(2);
		std::cout << "Set the margin [it has to be avobe 1] \n";
		std::cin >> margin;


		if (type == 4){
			std::cout << "Enter 8 bits like this -> 0 0 1 1 1 1 0 0\n";
			for (size_t i{}; i < 8; ++i){
				std::cin >> rules[i];
			}
		}
		delete cell_automata;
		CellularAutomaton* cell_automata = new CellularAutomaton(width, height, margin, type);
	}

	
	cell_automata->set_rules(rules, true);
	erase(1);
	while(true){
		//usleep(10/60);
		ClearScreen();
		cell_automata->draw_grid();
		cell_automata->update_grid();
		std::cout << *cell_automata << "\n";
		
	}

	// delete[] rules;
	delete cell_automata;

	return 0;
}

void erase(int lines){
	ClearScreen();
	for (size_t i{}; i < lines; ++i){
		std::cout << "                                                                                       \n";
	}
	ClearScreen();
}