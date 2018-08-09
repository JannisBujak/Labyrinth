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
	int findWayLength();

private:
	vector<vector < Field*> > field;
};


#endif //LABYRINTH_LABYRINTH_H
