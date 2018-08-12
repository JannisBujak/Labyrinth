//
// Created by JannisB98 on 09.08.2018.
//

#include "Labyrinth.h"
#include <fstream>
#include <vector>

Labyrinth::Labyrinth(string filename) {

	this->width = 0;
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
			if(line.size() > width)
				width = line.size();


			field.push_back(line);
			y++;
		}
		reader.close();
	}else{
		cout << "Unable to open file " + file << endl;
	}
	height = field.size();

	print();
}

void Labyrinth::print() {
	for(vector<Field* > line : field){
		for (Field* f : line) {
			cout << f->getSymbol();
		}
		cout << endl;
	}
}

int Labyrinth::findWayLength() {
	return 0;
}

Field *Labyrinth::getFieldAt(int x, int y) {
	return field[y][x];
}

int Labyrinth::getWidth() const {
	return width;
}

int Labyrinth::getHeight() const {
	return height;
}

Position *Labyrinth::getStartPosition() {
	for(vector<Field*> row : field){
		for(Field* f : row){
			if(f->getSymbol() == 'O')
				return f->getPosition();
		}
	}
}
