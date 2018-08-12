//
// Created by JannisB98 on 12.08.2018.
//

#include "Position.h"
#include <iostream>
using namespace std;

Position::Position(int x, int y) {
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
