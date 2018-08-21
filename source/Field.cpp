//
// Created by JannisB98 on 10.08.2018.
//

#include "Field.h"
#include <iostream>
using namespace std;

long Field::Memory = 0;

Field::Field(char symbol, int x, int y)
:Position(x, y){

	Memory++;
	this->symbol = symbol;
}

Field::~Field() {
	Field::Memory--;
}

char Field::getSymbol() const {
	return symbol;
}

void Field::printPosition() {
	cout << "(" << this->getX() << "|" << this->getY() << "): " << getSymbol() << endl;
}

void Field::printMemory() {
	cout << Field::Memory << " fields freed and not deleted." << endl;
}

long Field::getMemory() {
	return Memory;
}
