#pragma once
#include "Cell.h"
#include <vector>

class Table {
	std::vector<std::vector<Cell>> cells;
public:
	void addRow(const std::vector<Cell>& row);
	void print() const;
	Cell& getCell(int row, int col);
};