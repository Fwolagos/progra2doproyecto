#pragma once
#ifndef ROUTEMANAGER_H
#define ROUTEMANGER_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "route.h"
#define BACKGROUND "sources/img/CostaRica.jpg"
#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 649
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
	void menu(sf::RenderWindow&);
	void header();
	void ressetVectors();
	bool ruouteexist(string);
	Route& getRoute(string);
	void drawRoute();
};
#endif
