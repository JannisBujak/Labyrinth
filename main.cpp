#include <iostream>
#include <vector>
#include "source/Labyrinth.h"

using namespace std;

int main() {

	Labyrinth* l = new Labyrinth("labyrinth.txt");

	Position* start = l->getStartPosition();

	start->print();

	return 0;
}