#pragma once
#include <string>

enum CellType {
	Int,
	Double,
	String,
	Formula,
	Empty,
	Error
};

class Cell {
	std::string text;
	double numValue;
	CellType type; 
public:
	Cell();

	void setValue(const std::string& val);
	double getValue() const;
	std::string getText() const;
	CellType getType() const;
};
