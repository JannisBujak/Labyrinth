//
// Created by JannisB98 on 09.08.2018.
//

#include "Labyrinth.h"
#include <fstream>
#include <vector>
using namespace std;

long Labyrinth::Memory = 0;

Labyrinth::Labyrinth(string filename) {

	Labyrinth::Memory++;
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

Field * Labyrinth::getStart() {
	for(vector<Field*> row : field){
		for(Field* f : row){
			if(f->getSymbol() == 'S')
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
	Labyrinth::Memory--;
	for(vector<Field*> row : field) {
		for(Field* field1 : row){
			delete(field1);
		}
	}
}

void Labyrinth::printMemory() {
	cout << Labyrinth::Memory << " Labyrinth freed and not deleted." << endl;
}

long Labyrinth::getMemory() {
	return Memory;
}
