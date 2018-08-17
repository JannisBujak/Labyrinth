//
// Created by JannisB98 on 12.08.2018.
//

#include <iostream>
#include "Way.h"
#include "Field.h"
using namespace std;

long Way::Memory = 0;

Way::Way(Field* field){
	Way::Memory++;
	this->field = field;
	nextWay = nullptr;
}

Way::~Way() {
	Way::Memory--;
	field = nullptr;
	if(nextWay != nullptr) {
		nextWay->~Way();
	}
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

	Field* fieldAtP = l->getFieldAt(p);
	Way* thisWay = new Way(l->getFieldAt(p));
	if(fieldAtP->getSymbol() == '#'){
		return nullptr;
	}
	if(fieldAtP->getSymbol() == 'O'){
		return new Way(fieldAtP);
	}
	vector<Field*> forbiddenFieldsCopy = Way::copyFieldVector(forbiddenFields);
	forbiddenFieldsCopy.push_back(l->getFieldAt(p));

	vector<Position*> testedPositions = { new Position(p->getX() - 1, p->getY()),
									   new Position(p->getX() + 1, p->getY()),
									   new Position(p->getX(), p->getY() - 1),
									   new Position(p->getX(), p->getY() + 1) };

	vector<Way*> possibleWays;

	for(Position* pos : testedPositions){

		int sizeOfTheActualLine = l->getFieldAt(pos->getY()).size();

		if(pos->getX() < 0 || pos->getX() >= sizeOfTheActualLine || pos->getY() < 0 || pos->getY() >= l->getHeight()){
			delete(pos);
			continue;
		}
		if(Way::isInFieldVector(l->getFieldAt(pos), forbiddenFields)){
			continue;
		}

		Way* potentialWay = findShortestWay(pos, l, forbiddenFieldsCopy);
		if(potentialWay == nullptr){
			delete(potentialWay);
			delete(pos);
			continue;
		}
		possibleWays.push_back(potentialWay);
		delete(pos);
	}
	int length = - 1;
	Way* returnWay = nullptr;
	for(Way* way : possibleWays){
		if(way->getLengthFromHere() < length || length == -1){
			length = way->getLengthFromHere();
			returnWay = way;
		}else{
			delete(way);
		}
	}
	if(length == -1 || returnWay == nullptr){
		return nullptr;
	}
	thisWay->appendWay(returnWay);
	return thisWay;
}

void Way::print() {
	if(this == nullptr || this->field == nullptr){
		return;
	}
	this->getField()->printPosition();
	if(nextWay != nullptr) {
		cout << "   ->  ";
		nextWay->print();
	}
}

bool Way::touchedThisField(int x, int y, Labyrinth* l) {
	if(this == nullptr)
		return false;
	if(field->getX() == x && field->getY() == y)
		return true;
	nextWay->touchedThisField(x, y, l);
}

void Way::printField(Labyrinth* l) {
	for(int y = 0; y < l->getHeight(); y++){
		for(int x = 0; x < l->getFieldAt(y).size(); x++){
			if(touchedThisField(x, y, l)){
				cout << l->getFieldAt(x, y)->getSymbol();
			}else{
				cout << ' ';
			}
		}
		cout << endl;
	}
}

void Way::appendWay(Way *way) {
	if(this == nullptr)
		exit(2);
	if(nextWay == nullptr){
		nextWay = way;
		return;
	}
	nextWay->appendWay(way);
}

vector<Field *> Way::copyFieldVector(vector<Field*> fields) {
	vector<Field *> vector1;
	for(Field* f : fields){
		vector1.push_back(f);
	}
	return vector1;
}

bool Way::isInFieldVector(Field* f, vector<Field *> fields) {
	for(Field* field: fields){
		if(field == f){
			return true;
		}
	}
	return false;
}

void Way::printMemory() {
	cout << Way::Memory << endl;
}
