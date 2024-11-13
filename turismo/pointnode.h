#pragma once
#ifndef POINTNODE_H
#define POINTNODE_H

#include <iostream>
using namespace std;


class PointNode{
private:
	string name;
	int x;
	int y;
	PointNode* next;
	PointNode* prev;
public:
	PointNode(string, int, int);
	~PointNode();

	void setName(string);
	void setX(int);
	void setY(int);
	void setNext(PointNode*);
	void setPrev(PointNode*);

	string getName();
	int getX();
	int getY();
	PointNode* getNext();
	PointNode* getPrev();

};
#endif

