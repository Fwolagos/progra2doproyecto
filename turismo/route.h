#pragma once
#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
#include "pointlist.h"
using namespace std;

class Route
{
private:
	string name;
	PointList pointList;
	Route* next;
	Route* prev;
public:
	Route();
	Route(string);
	~Route();

	void setName(string);
	void setPointList(PointList);
	void setNext(Route*);
	void setPrev(Route*);

	string getName();
	PointList& getPointList();
	Route* getNext();
	Route* getPrev();
};
#endif

