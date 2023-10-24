#include "cellGrid.h"
#include "rules.h"


CellularAutomaton::CellularAutomaton(){
	set_grid();
	prepare_grid();
}

CellularAutomaton::CellularAutomaton(const size_t width, const size_t height, const size_t margin, int ruletype)
	: m_width(width), m_height(height), m_margin(margin), m_ruletype(ruletype){
	set_grid();
	prepare_grid();
}

int CellularAutomaton::get_width() const{
	return m_width;
}
int CellularAutomaton::get_height() const{
	return m_height;
}

void CellularAutomaton::set_grid(){
	m_grid = new int[m_width*m_height]{};
	m_tempGrid = new int[m_width*m_height]{};
}

int CellularAutomaton::get_grid() const{
	return m_width*m_height;
}

void CellularAutomaton::draw_grid(){
	for (size_t y{0}; y < m_height; y++){
		for (size_t x{0}; x < m_width; x++){
			if (m_grid[x*m_height+y] == 0){
				std::cout << "." << " ";
			}else{
				std::cout << "#" << " ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void CellularAutomaton::set_rules(int *rules, bool allow){
	if (allow == true){
			for (int i{}; i <= 8; i++){
			m_rules[i] = rules[i];
		}
	}
}

void CellularAutomaton::update_grid(){
	for (size_t y{m_margin}; y < (m_height-m_margin); y++){
		for (size_t x{m_margin}; x < (m_width-m_margin); x++){
			switch(m_ruletype){
				case 1:
				case 2:
				case 3:
					m_tempGrid[x*m_height+(y-1)] = m_tempGrid[x*m_height+y];
					m_tempGrid[x*m_height+y] = select_type(m_ruletype, m_grid, x, y, m_height);
				break;
				case 4:
					m_tempGrid[x*m_height+(y-1)] = m_tempGrid[x*m_height+y];
					m_tempGrid[x*m_height+y] = select_type(m_ruletype, m_grid, x, y, m_height, m_rules);
				break;
				default:
					m_tempGrid[x*m_height+y] = select_type(m_ruletype, m_grid, x, y, m_height);
				break;
				case 5:
					m_tempGrid[x*m_height+y] = select_type(m_ruletype, m_grid, x, y, m_height);
				break;
			}
		}
	}
	for (size_t y{m_margin}; y < (m_height-m_margin); y++){
		for (size_t x{m_margin}; x < (m_width-m_margin); x++){
			m_grid[x*m_height+y] = m_tempGrid[x*m_height+y];
		}
	}
}

void CellularAutomaton::prepare_grid(){
	switch(m_ruletype){
		case 0:
			startRand();
			for (size_t y{m_margin}; y < (m_height-m_margin); y++){
				for (size_t x{m_margin}; x < (m_width-m_margin); x++){
					m_grid[x*m_height+y] = randomNumber();
					m_tempGrid[x*m_height+y] = m_grid[x*m_height+y];
				}
			}
		break;
		case 1:
		case 2:
		case 3:
		case 4:
			m_grid[(m_width/2)*m_height+(m_height-(m_margin+1))] = 1;
			m_tempGrid[(m_width/2)*m_height+(m_height-(m_margin+1))] = 1;
		break;
		case 5:
			m_grid[(m_width/2)*m_height+(m_height/2)] = 1;
			m_tempGrid[(m_width/2)*m_height+(m_height/2)] = 1;
		break;
	}
}

std::ostream& operator<<(std::ostream& out, const CellularAutomaton& operand){
   out << "Width : [" << operand.get_width() << "] Height : [" << operand.get_height() <<"] CellularAutomaton size :"
   << operand.get_grid() << "\n             Press ctrl+c to exit... \n";
  return out;
}

CellularAutomaton::~CellularAutomaton(){
	delete[] m_grid;
	delete [] m_tempGrid;
	std::cout << "CellularAutomaton deleted \n";
}
