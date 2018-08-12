//
// Created by JannisB98 on 10.08.2018.
//

#include "Field.h"
#include <iostream>
using namespace std;

Field::Field(char symbol, int x, int y) {
	this->symbol = symbol;
	this->x = x;
	this->y = y;
}

char Field::getSymbol() const {
	return symbol;
}

int Field::getX() const {
	return x;
}

int Field::getY() const {
	return y;
}

void Field::printPosition() {
	cout << "(" << x << "|" << y << "): " << symbol << endl;
}

Position *Field::getPosition() {
	return new Position(x, y);
}
