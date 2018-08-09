//
// Created by JannisB98 on 10.08.2018.
//

#include "Field.h"

Field::Field(char symbol) {
	this->symbol = symbol;
}

char Field::getSymbol() const {
	return symbol;
}
