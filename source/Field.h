//
// Created by JannisB98 on 10.08.2018.
//

#ifndef LABYRINTH_FIELD_H
#define LABYRINTH_FIELD_H


class Field {
public:
	Field(char symbol);

	char getSymbol() const;

private:
	char symbol;
};


#endif //LABYRINTH_FIELD_H
