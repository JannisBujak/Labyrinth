#include <iostream>
#include <vector>
#include "source/Labyrinth.h"
#include "source/Way.h"
using namespace std;

int main() {

	Labyrinth* l = new Labyrinth("labyrinth.txt");
	l->print();
	cout << endl;

	Field* start = l->getStart();

	vector<Field*> forbiddenFields;

	Way* shortestWay = Way::findShortestWay(start->getPosition(), l, forbiddenFields);

	cout << "start: ";
	shortestWay->print();
	cout << shortestWay->getLengthFromHere() << endl;

	//system("pause");

	return 0;
}