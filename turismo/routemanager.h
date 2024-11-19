#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "routelist.h"
#define PATH_FONT "sources/font/arial.ttf"
#define BACKGROUND "sources/img/CostaRica.jpg"
#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 649
#define NAME_WINDOW	 "Programa de rutas turisticas"
#define COLOR_POINT sf::Color::Red
#define COLOR_LINE	sf::Color::Red
#define COLOR_OUTLINE sf::Color::Blue
#define RADIUS 5
#define CHARACTER_SIZE 12
using namespace std;

class RouteManager
{
private:
	RouteList routeList;
	vector<sf::Vertex> lines;
	vector<sf::CircleShape> circles;
	vector<sf::Text> labels;
	sf::CircleShape circle;
	sf::Text label;
	sf::Font font;
	sf::Text routeName;
	int state;
public:
	RouteManager();
	~RouteManager();

	void initialize();
	void header();
	void menu();
	void ressetVectors();
	void drawRoute(sf::RenderWindow&);
	/*void saveRoute();*/
};

