//
// Created by JannisB98 on 09.08.2018.
//

#ifndef LABYRINTH_LABYRINTH_H
#define LABYRINTH_LABYRINTH_H

#include <iostream>
#include <vector>
#include "Field.h"

using namespace std;

class Labyrinth {
public:

	explicit Labyrinth(string filename);
	~Labyrinth();
	void print();

	Field* getFieldAt(Position* p);
	Field* getFieldAt(int x, int y);

	int getMaxWidth() const;

	int getHeight() const;

	const vector<Field *> &getFieldAt(int y) const;

	Field * getStart();

	//Memory
	static long getMemory();

	static void printMemory();


private:
	static long Memory;
	vector<vector < Field*> > field;
	int maxWidth;
	int height;
};


#endif //LABYRINTH_LABYRINTH_H
