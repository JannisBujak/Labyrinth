#include <iostream>
#include <vector>
#include "source/Labyrinth.h"
#include "source/Way.h"
using namespace std;

int main() {

	Labyrinth* l = new Labyrinth("labyrinthS.txt");

	Field* start = l->getStart();

	start->getPosition()->print();
	cout << endl;

	vector<Field*> forbiddenFields;

	Way* w = new Way();
	Way* theWay = w->findShortestWay(start->getPosition(), l, forbiddenFields);

	return 0;
}