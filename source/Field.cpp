//
// Created by JannisB98 on 10.08.2018.
//

#include "Field.h"
#include <iostream>
using namespace std;

long Field::Memory = 0;

Field::Field(char symbol, int x, int y) {
	Memory++;
	position = new Position(x, y);
	this->symbol = symbol;
	this->x = x;
	this->y = y;
}

Field::~Field() {
	delete(position);
	Field::Memory--;
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
	return position;
}

void Field::printMemory() {
	cout << Field::Memory << " fields freed and not deleted." << endl;
}

long Field::getMemory() {
	return Memory;
}
