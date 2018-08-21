//
// Created by JannisB98 on 10.08.2018.
//

#include "Field.h"
#include <iostream>
using namespace std;

long Field::Memory = 0;

Field::Field(char symbol, int x, int y)
:Position(x, y){

	Memory += sizeof(Field);
	this->symbol = symbol;
}

Field::~Field() {
	Field::Memory -= sizeof(Field);
}

char Field::getSymbol() const {
	return symbol;
}

void Field::printPosition() {
	cout << "(" << this->getX() << "|" << this->getY() << "): " << getSymbol() << endl;
}

long Field::getNumberOfObjects() {
	return Field::Memory / sizeof(Field);
}

long Field::getMemory() {
	return Memory;
}

void Field::printMemory() {
	cout << Field::Memory << " bytes for class [Field] freed and not deleted." << endl;
}
