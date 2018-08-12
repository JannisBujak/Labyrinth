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
	void print();

	Field* getFieldAt(int x, int y);

	int getWidth() const;

	int getHeight() const;

	Field * getStart();

private:
	vector<vector < Field*> > field;
	int width;
	int height;
};


#endif //LABYRINTH_LABYRINTH_H
