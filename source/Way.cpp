//
// Created by JannisB98 on 12.08.2018.
//

#include <iostream>
#include "Way.h"
using namespace std;

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

int Way::getLengthFromHere() {
	if(this == nullptr){
		return 0;
	}
	return nextWay->getLengthFromHere() + 1;
}

Way *Way::findShortestWay(Position* p, Labyrinth* l, vector<Field*> forbiddenFields) {
	vector<Way*> way;
	for(int y = p->getY() - 1; y <= p->getY() + 1; y++){
		for(int x = p->getX() - 1; x <= p->getX() + 1; x++){

			if((x == p->getX() && y == p->getY()) || (x != p->getX() && y != p->getY()) || x < 0 || y < 0 || l->getWidth() <= x || l->getHeight() <= y){
				continue;
			}
			(new Position(x, y))->print();

			Field* potentialField = l->getFieldAt(x, y);
			for(Field* f : forbiddenFields){
				if(potentialField->getX() == f->getX() && potentialField->getY() == f->getY())
					continue;
			}


			Way* w = new Way(potentialField);
			vector<Field*> forbiddenFieldsCopy;
			for(Field* f : forbiddenFields){
				forbiddenFieldsCopy.push_back(f);
			}
			forbiddenFieldsCopy.push_back(this->getField());

			Way* recursiveWay = w->findShortestWay(w->getField()->getPosition(), l, forbiddenFieldsCopy);
			way.push_back(recursiveWay);
		}
	}
	return nullptr;
}
