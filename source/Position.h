//
// Created by JannisB98 on 12.08.2018.
//

#ifndef LABYRINTH_POSITION_H
#define LABYRINTH_POSITION_H


class Position {
private:
	int x, y;
public:
	Position(int x, int y);
	void print();

	int getX() const;

	int getY() const;
};


#endif //LABYRINTH_POSITION_H
