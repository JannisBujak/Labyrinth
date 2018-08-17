#ifndef MAIN
#define MAIN

#include <iostream>
#include <vector>
#include "source/Labyrinth.h"
#include "source/Way.h"


using namespace std;

int main(){

	Labyrinth* l = new Labyrinth("labyrinth.txt");
	l->print();
	cout << endl;
	Field* start = l->getUniqueField('S');

	vector<Field*> forbiddenFields;

	Way* shortestWay = Way::findShortestWay(start->getPosition(), l, forbiddenFields);

	cout << "start: ";
	shortestWay->print();
	cout << shortestWay->getLengthFromHere() << endl;


	shortestWay->printField(l);
	system("pause");

	delete(shortestWay);
	delete(l);

	if(Way::getMemory() != 0){
		Way::printMemory();
	}
	if(Labyrinth::getMemory() != 0){
		Labyrinth::printMemory();
	}
	if(Position::getMemory() != 0){
		Position::printMemory();
	}
	if(Field::getMemory() != 0){
		Field::printMemory();
	}
	return 0;
}
#endif