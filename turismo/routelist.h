#pragma once
#ifndef ROUTELIST_H
#define ROUTELIST_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "route.h"
#define BACKGROUND "sources/img/CostaRica.jpg"
#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 649
#define NAME_WINDOW	 "Programa de rutas turisticas"
using namespace std;


class RouteList
{
private:
	Route* head;
	vector<sf::Vertex> lines;
	vector<sf::CircleShape> circles;
	



public:///Esto es lo unico publico 
	RouteList();
	~RouteList();
	void initialize();
	void menu(sf::RenderWindow&);
	void header();
	void ressetVectors();
	bool routeExist(string);
	Route& getRoute(string);
	void createRoute(sf::RenderWindow&);
	void addRoute(Route*);
	void showRoutes(sf::RenderWindow&);
	void displayRoutes();
	void delRoute();///no le vamos a pasar window a ver que
	void renameRoute();
};
#endif
