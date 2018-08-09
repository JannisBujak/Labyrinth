#include <iostream>
#include <vector>
#include "source/Labyrinth.h"

using namespace std;

int main() {

	Labyrinth* l = new Labyrinth("labyrinth.txt");
	int length = (l->findWayLength());

	cout << length;

	return 0;
}