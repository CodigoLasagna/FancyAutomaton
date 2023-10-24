#include "cellGrid.h"
#include <unistd.h>

void m_clean();
void m_pause();
void sleep(int r);

int main(){
	CellularAutomaton* cell_automata = new CellularAutomaton();
	int type{};
	int width{}; int height{};
	size_t margin{1};
	bool quickstart{};

	int* rules = new int[]{1, 0, 1, 1, 0, 1, 1, 0};

	std::cout << "type 1 to choose a simulation, type 0 to quickstart Conway's Game of life \n";
	std::cin >> quickstart;
	m_clean();
	if (quickstart == true){
		std::cout << "Type which simulation you would like to start\n";
		std::cout << "____________________________________________________________________________________\n\n";
		std::cout << "Conway's Game of life[0] | Wolfram setrules[1-3] R(30, 94, 90) | Wolfram custom[4]| \n";
		std::cin >> type;
		m_clean();
		std::cout << "Set your width and height, like this -> 21 21 \n";
		std::cin >> width >> height;
		m_clean();
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
	m_clean();
	while(true){
		m_clean();
		cell_automata->draw_grid();
		cell_automata->update_grid();
		std::cout << *cell_automata << "\n";
		sleep(1);
		
	}

	delete cell_automata;

	return 0;
}

#ifdef __unix__
void m_clean()
{
	system("clear");
}
void m_pause()
{
	char opt;
	printf("\nPresione enter para continuar...");
	while(getc(stdin) != '\n');
}
#endif
#ifdef _WIN32
void m_clean()
{
	system("cls");
}
void m_pause()
{
	printf("\nPresione enter para continuar...");
	system("pause");
	printf("Saliendo...\n");
}
#endif

void sleep(int r){
	int trash;
	int i, j;
	for (i = 0; i < 10000; i++)
		for (j = 0; j < r*10000; j++)
				trash = 1;
}
