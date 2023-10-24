#ifndef CellularAutomaton_H
#define CellularAutomaton_H

#include <iostream>
#include <array>
#include "math.h"

class CellularAutomaton{

private:
	const size_t m_height{21};
	const size_t m_width{21};
	const size_t m_margin{1};
	unsigned int m_ruletype{0};
	bool m_allowRules = false;
	int* m_grid = new int[m_width*m_height]{};
	int* m_tempGrid = m_grid;

public:
	int m_rules[8] = {0, 1, 1, 1, 1, 1, 1, 0};
	CellularAutomaton();
	friend std::ostream& operator<<(std::ostream& out, const CellularAutomaton& operand);
	CellularAutomaton(const size_t width, const size_t height, const size_t margin, int ruletype);

	int  get_width() const;
	int  get_height() const;
	void set_grid();
	int  get_grid() const;

	int set_aliveCell() const;
	int set_deadCell() const;

	void prepare_grid();
	void update_grid();
	void draw_grid();

	void set_rules(int* rules, bool allow);


	~CellularAutomaton();

};

#endif
