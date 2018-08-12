//
// Created by JannisB98 on 12.08.2018.
//

#include "Way.h"

Way::Way(Field *field) {
	this->field = field;
	this->nextWay = nullptr;
}

void Way::addField(Field *field) {
	if(getNextWay() == nullptr) {
		setNextWay(new Way(field));
		return;
	}
	nextWay->addField(field);
}

Field *Way::getField() const {
	return field;
}

void Way::setField(Field *field) {
	Way::field = field;
}

Way *Way::getNextWay() const {
	return nextWay;
}

void Way::setNextWay(Way *nextWay) {
	Way::nextWay = nextWay;
}

bool Way::isInside(Field* field) {
	if(this == nullptr)
		return false;
	if(this->field == field)
		return true;
	return nextWay->isInside(field);
}
