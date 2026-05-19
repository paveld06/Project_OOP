#include "Cell.h"

Cell::Cell() : text(""), numValue(0), type(CellType::Empty) {}

bool isInt(const std::string& s) {
	if (s.empty()) return false;

	int i = 0;
	if (s[0] == '-' || s[0] == '+') i++;

	for (; i < s.size(); i++) {
		if (!isdigit(s[i])) return false;
	}
}

bool isDouble(const std::string& s) {
	if (s.empty()) return false;

	int i = 0;
	if (s[0] == '-' || s[0] == '+') i++;

	bool isDot = false;
	for (; i < s.size(); i++) {
		if (s[i] == '.') {
			if (isDot) return false;
			isDot = true;
		}
		else if (!isdigit(s[i])) {
			return false;
		}
	}
	return isDot;
}

void Cell::setValue(const std::string& s) {
	text = s;

	if (s.empty()) {
		type = Empty;
		numValue = 0;
	}

	else if (isInt(s)) {
		type = Int;
		numValue = std::stoi(s);
	}

	else if (isDouble(s)) {
		type = Double;
		numValue = std::stod(s);
	}

	else if (s[0] == '=') {
		type = Formula;
	}
	
	else {
		type = String;
	}
}

double Cell::getValue() const {
	return numValue;
}

std::string Cell::getText() const {
	return text;
}

CellType Cell::getType() const {
	return type;
}