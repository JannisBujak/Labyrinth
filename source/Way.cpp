//
// Created by JannisB98 on 12.08.2018.
//

#include <iostream>
#include "Way.h"
using namespace std;

/*Way::Way() {
	//this->field = field;
	//this->nextWay = nullptr;
	//this->nextWay = new Way(nullptr);
	cout << "K" << endl;
}*/
Way::Way() = default;

void Way::addField(Field *field) {
	if(getNextWay() == nullptr) {
		setNextWay(new Way());
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
	Field *fieldAtPosition = l->getFieldAt(p);
	p->print();
	if (fieldAtPosition->getSymbol() == 'D') {
		this->field = fieldAtPosition;
		return this;
	}
	if (fieldAtPosition->getSymbol() != '-' && fieldAtPosition->getSymbol() != 'O'){
		return nullptr;
	}
	vector<Way*> way;
	for(int y = p->getY() - 1; y <= p->getY() + 1; y++){
		for(int x = p->getX() - 1; x <= p->getX() + 1; x++){

			if((x == p->getX() && y == p->getY()) || (x != p->getX() && y != p->getY())
			|| x < 0 || y < 0 || l->getWidth() <= x){
				continue;
			}


			bool isForbidden;
			for(Field* f : forbiddenFields){
				if(fieldAtPosition->getX() == f->getX() && fieldAtPosition->getY() == f->getY()) {
					isForbidden = true;
					break;
				}
			}
			if(isForbidden)
				continue;

			Way* w = new Way();
			vector<Field*> forbiddenFieldsCopy;
			for(Field* f : forbiddenFields){
				forbiddenFieldsCopy.push_back(f);
			}
			forbiddenFieldsCopy.push_back(fieldAtPosition);
			nextWay = w->findShortestWay(new Position(x, y), l, forbiddenFieldsCopy);

			if(nextWay == nullptr)
				continue;
			way.push_back(nextWay);

		}
	}
	int length = 0;
	Way* returnWay;
	for(Way* w : way){
		if(w->getLengthFromHere() > length){
			length = w->getLengthFromHere();
			returnWay = w;
		}
	}
	this->nextWay = returnWay;
	return this;
}

void Way::print() {
	this->getField()->printPosition();
	nextWay->print();
}
