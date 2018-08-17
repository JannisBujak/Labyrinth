//
// Created by JannisB98 on 12.08.2018.
//

#include "Position.h"
#include <iostream>
using namespace std;

long Position::Memory = 0;

Position::~Position(){
	Position::Memory--;
}

Position::Position(int x, int y) {
	Position::Memory++;
	this->x = x;
	this->y = y;
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

void Position::printMemory() {
	cout << Position::Memory << " Position freed and not deleted." << endl;
}
