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
		vector<char > line;
		for(char c : s){
			line.push_back(c);
		}
		field.push_back(line);
	}
	print();
}

void Labyrinth::print() {
	for(vector<char> line : field){
		for (char c : line) {
			cout << c;
		}
		cout << endl;
	}
}

int Labyrinth::findWayLength() {
	return 0;
}
