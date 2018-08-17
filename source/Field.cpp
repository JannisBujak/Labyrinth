//
// Created by JannisB98 on 10.08.2018.
//

#include "Field.h"
#include <iostream>
using namespace std;

long Field::Memory = 0;

Field::Field(char symbol, int x, int y) {
	Memory++;
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
	cout << "(" << this->getX() << "|" << this->getY() << "): " << getSymbol() << endl;
}

Position *Field::getPosition() {
	return new Position(x, y);
}

void Field::printMemory() {
	cout << Field::Memory << " fields freed and not deleted." << endl;
}

Field::~Field() {
	Field::Memory--;
}
