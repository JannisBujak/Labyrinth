//
// Created by JannisB98 on 10.08.2018.
//

#ifndef LABYRINTH_FIELD_H
#define LABYRINTH_FIELD_H


#include "Position.h"

class Field {
public:
	Field(char symbol, int x, int y);
	~Field();

	char getSymbol() const;
	int getX() const;
	int getY() const;
	Position* getPosition();

	void printPosition();

	//Memory
	static void printMemory();

private:
	static long Memory;
	char symbol;
	int x;
	int y;
};


#endif //LABYRINTH_FIELD_H
