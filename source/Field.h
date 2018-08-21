//
// Created by JannisB98 on 10.08.2018.
//

#ifndef LABYRINTH_FIELD_H
#define LABYRINTH_FIELD_H


#include "Position.h"

class Field : public Position{
public:
	Field(char symbol, int x, int y);
	~Field();

	char getSymbol() const;

	void printPosition();

	//Memory
	static long getNumberOfObjects();

	static long getMemory();
	static void printMemory();

private:
	static long Memory;
	char symbol{};
};


#endif //LABYRINTH_FIELD_H
