#pragma once
#ifndef POINTLIST_H
#define POINTLIST_H
#define	RADIUS 5
#include "pointnode.h"
#include <SFML/Graphics.hpp>
#define COLOR_Point sf::Color::Red
#define COLOR_LINE	sf::Color::Red
#define COLOR_OUTLINE sf::Color::Blue
#include <iostream>
#include <vector>

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

	void loadPoints(vector<sf::CircleShape>&, vector<sf::Vertex>&);


};
#endif
