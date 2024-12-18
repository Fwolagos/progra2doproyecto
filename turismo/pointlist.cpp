#include "pointlist.h"

PointList::PointList() {
	this->head = nullptr;
}
PointList::~PointList() {}

void PointList::addPoint(string name, int x, int y) {
	PointNode* newNode = new PointNode(name, x, y);
	if (head == nullptr) {
		head = newNode;
	}
	else {
		PointNode* current = head;
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		current->setNext(newNode);
		newNode->setPrev(current);
	}
}
PointNode* PointList::searchPoint(int position[2]) {
	PointNode* temp = head;
	while (temp->getNext() != nullptr && temp->getX() != position[0] && temp->getY() != position[1]) {
		temp = temp->getNext();
	}
	if (temp->getNext() != nullptr && temp->getX() != position[0] && temp->getY() != position[1]) {
		return nullptr;
	}
	else {
		return temp;
	}
}
void PointList::delPoint(PointNode* point) {
	PointNode* next = new PointNode();
	PointNode* prev = new PointNode();
	prev = point->getPrev();
	next = point->getNext();
	prev->setNext(next);
	next->setPrev(prev);
	delete point;
}
void PointList::editPointName(PointNode* point, string name) {
	point->setName(name);
}
void PointList::editPointPosition(PointNode* point, int position[2]) {
	point->setX(position[0]);
	point->setY(position[1]);
}
PointNode& PointList::getHead() {
	return*head;
}




