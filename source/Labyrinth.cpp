//
// Created by JannisB98 on 09.08.2018.
//

#include "Labyrinth.h"
#include <fstream>
#include <vector>

Labyrinth::Labyrinth(string filename) {

	string file = "../text/" + filename;
	//Most important values
	ifstream reader;    reader.open(file);  vector<string> text;    string line;
	if(reader.is_open())
	{
		while(reader.good())
		{
			getline(reader, line);
			text.push_back(line);
		}
		reader.close();
	}else{
		cout << "Unable to open file " + file << endl;
	}

	for(string s : text){
		vector<Field* > line;
		for(char c : s){
			line.push_back(new Field(c));
		}
		field.push_back(line);
	}
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
