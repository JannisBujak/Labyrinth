//
// Created by JannisB98 on 12.08.2018.
//

#include "Position.h"
#include <iostream>
using namespace std;

long Position::Memory = 0;

Position::Position(int x, int y) {
	Position::Memory += sizeof(Position);
	this->x = x;
	this->y = y;
}

Position::~Position(){
	Position::Memory -= sizeof(Position);
}

void Position::print() {
	cout << "(" << x << "|" << y << ")" << endl;
}

int Position::getX() const {
	return x;
}

int Position::getY() const {
	return y;
}

long Position::getNumberOfObjects() {
	return Position::Memory / sizeof(Position);

}

long Position::getMemory() {
	return Memory;
}

void Position::printMemory() {
	cout << Position::Memory << " bytes for class [Position] freed and not deleted." << endl;
}
