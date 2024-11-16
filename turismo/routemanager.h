#pragma once
#ifndef ROUTEMANAGER_H
#define ROUTEMANGER_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "route.h"
using namespace std;


class RouteManager
{
private:
	Route* head;
	vector<sf::Vertex> lines;
	vector<sf::CircleShape> circles;
	



public:///Esto es lo unico publico 
	RouteManager();
	void initialize();

};
#endif
