#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "routelist.h"
#define BACKGROUND "sources/img/CostaRica.jpg"
#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 649
#define NAME_WINDOW	 "Programa de rutas turisticas"
using namespace std;

class RouteManager
{
private:
	vector<sf::Vertex> lines;
	vector<sf::CircleShape> circles;
public:

	void initialize();
	void header();
	void ressetVectors();
	void displayRoutes();
	void addRoute(Route*);
};

