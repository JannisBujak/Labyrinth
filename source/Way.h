//
// Created by JannisB98 on 12.08.2018.
//

#ifndef LABYRINTH_WAY_H
#define LABYRINTH_WAY_H

#include "Field.h"
#include "Labyrinth.h"

class Way {
private:
	static long Memory;
	static long callsOf_FindShortestWay;

	Field* field;
	Way* nextWay;
public:
	Way(Field* field);
	~Way();
	void addField(Field* field);
	void appendWay(Way* way);

	static Way* findShortestWay(Position* p,Labyrinth* l, vector<Field*> forbiddenFields);
	static vector<Field*> copyFieldVector(vector<Field*> fields);
	static bool isInFieldVector(Field* f, vector<Field*> fields);

	bool isInside(Field* field);
	bool touchedThisField(int x, int y, Labyrinth* l);
	//print
	void print();
	void printField(Labyrinth* l);

	static long getCallsOf_FindShortestWay();

	static long getNumberOfObjects();
	static long getMemory();
	static void printMemory();

	//getter
	Field *getField() const;
	Way *getNextWay() const;
	int getLengthFromHere();

	void setNextWay(Way *nextWay);
};


#endif //LABYRINTH_WAY_H
