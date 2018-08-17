//
// Created by JannisB98 on 12.08.2018.
//

#ifndef LABYRINTH_POSITION_H
#define LABYRINTH_POSITION_H


class Position {
private:
	int x, y;
	static long Memory;
public:
	Position(int x, int y);
	~Position();
	void print();

	int getX() const;

	int getY() const;

	//Memory
	static void printMemory();

};


#endif //LABYRINTH_POSITION_H
