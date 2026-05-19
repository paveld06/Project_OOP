#include "Table.h"
#include <iostream>
void Table::addRow(const std::vector<Cell>& row) {
	cells.push_back(row);
}

void Table::print() const {
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[i].size(); j++)
		{
			std::cout << cells[i][j].getText();
			if (j != cells[i].size() - 1) std::cout << " | ";
		}
		std::cout << std::endl;
	}
}

Cell& Table::getCell(int row, int col) {
	return cells[row][col];
}
