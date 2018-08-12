//
// Created by JannisB98 on 12.08.2018.
//

#ifndef LABYRINTH_WAY_H
#define LABYRINTH_WAY_H

#include "Field.h"

class Way {
private:
	Field* field;
	Way* nextWay;
public:
	Way(Field* field);
	void addField(Field* field);

	bool isInside(Field* field);
	//getter
	Field *getField() const;
	Way *getNextWay() const;

	//setter
	void setField(Field *field);
	void setNextWay(Way *nextWay);
};


#endif //LABYRINTH_WAY_H
