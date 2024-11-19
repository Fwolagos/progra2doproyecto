#pragma once
#ifndef POINTLIST_H
#define POINTLIST_H
#include "pointnode.h"
#include <iostream>

class PointList
{
private:
	PointNode* head;
public:
	PointList();
	~PointList();

	void addPoint(string, int, int);
	PointNode* searchPoint(int[2]);
	void delPoint(PointNode*);
	void editPointName(PointNode*, string);
	void editPointPosition(PointNode*, int[2]);
	PointNode& getList();


};
#endif
