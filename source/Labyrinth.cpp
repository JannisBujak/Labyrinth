//
// Created by JannisB98 on 09.08.2018.
//

#include "Labyrinth.h"
#include <fstream>
#include <vector>
using namespace std;

long Labyrinth::Memory = 0;

Labyrinth::Labyrinth(string filename) {

	Labyrinth::Memory += sizeof(Labyrinth);

	this->maxWidth = 0;
	string file = "../text/" + filename;
	//Most important values
	ifstream reader;    reader.open(file);  string textLine;
	if(reader.is_open())
	{
		int y = 0;
		while(reader.good())
		{
			getline(reader, textLine);
			if(textLine == "") break;
			vector<Field* > line;
			for(int x = 0; x < textLine.length(); x++){
				char c = textLine[x];
				if(c == ' ')    continue;
				line.push_back(new Field(c, x, y));
			}
			if(line.size() > maxWidth){
				maxWidth = line.size();
			}/*else if(width != line.size()){
				exit(3);
			}*/


			field.push_back(line);
			y++;
		}
		reader.close();
	}else{
		cout << "Unable to open file " + file << endl;
	}
	height = field.size();

	//print();
}

void Labyrinth::print() {
	for(vector<Field* > line : field){
		for (Field* f : line) {
			cout << f->getSymbol();
		}
		cout << endl;
	}
}

Field *Labyrinth::getFieldAt(int x, int y) {
	return field[y][x];
}

Field *Labyrinth::getFieldAt(Position *p) {
	return field[p->getY()][p->getX()];
}

int Labyrinth::getMaxWidth() const {
	return maxWidth;
}

int Labyrinth::getHeight() const {
	return height;
}

Field *Labyrinth::getUniqueField(char c) {
	for(vector<Field*> row : field){
		for(Field* f : row){
			if(f->getSymbol() == c)
				return f;
		}
	}
	cout << "Not found" << endl;
	exit(-1);
}

const vector<Field *> &Labyrinth::getFieldAt(int y) const {
	return field[y];
}

Labyrinth::~Labyrinth() {
	Labyrinth::Memory -= sizeof(Labyrinth);
	for(vector<Field*> row : field) {
		for(Field* field1 : row){
			delete(field1);
		}
	}
}

long Labyrinth::getNumberOfObjects() {
	return Labyrinth::Memory / sizeof(Labyrinth);
}

long Labyrinth::getMemory() {
	return Memory;
}

void Labyrinth::printMemory() {
	cout << Labyrinth::Memory << " bytes of class [Labyrinth] freed and not deleted." << endl;
}

vector<Position *> Labyrinth::getOptimumFollowingPoints(Position *position, Position *end) {

	vector<Position*> array;

	int xDiff = end->getX() - position->getX();     int yDiff = end->getY() - position->getY();
	int absXDiff = abs(xDiff);                      int absYDiff = abs(yDiff);

	int xDivide, yDivide;

	if(xDiff == 0 || absXDiff == 0)         xDivide = 1;
	else                                    xDivide = xDiff/absXDiff;

	if(yDiff == 0 || absYDiff == 0)         yDivide = 1;
	else                                    yDivide = yDiff/absYDiff;


	if(absXDiff > absYDiff){

		array.push_back(new Position((position->getX() + xDivide), position->getY()));
		array.push_back(new Position(position->getX(), (position->getY()) + yDivide));
		array.push_back(new Position(position->getX(), (position->getY()) - yDivide));
		array.push_back(new Position((position->getX() - xDivide), position->getY()));

	}else{

		array.push_back(new Position(position->getX(), (position->getY() + yDivide)));
		array.push_back(new Position((position->getX() + xDivide), position->getY()));
		array.push_back(new Position((position->getX() - xDivide), position->getY()));
		array.push_back(new Position(position->getX(), (position->getY() - yDivide)));

	}

	return array;
}
