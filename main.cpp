#include <iostream>
#include <vector>
#include "source/Labyrinth.h"
#include "source/Way.h"
using namespace std;

int main() {

	Labyrinth* l = new Labyrinth("labyrinth.txt");

	Field* start = l->getStart();

	start->getPosition()->print();

	vector<Field*> forbiddenFields;
	Way* w = new Way(start);

	w->findShortestWay(start->getPosition(), l, forbiddenFields);

	return 0;
}