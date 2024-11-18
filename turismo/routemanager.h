#pragma once
#ifndef ROUTEMANAGER_H
#define ROUTEMANGER_h
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


class RouteManager
{
private:
	Route* head;
	vector<sf::Vertex> lines;
	vector<sf::CircleShape> circles;
	



public:///Esto es lo unico publico 
	RouteManager();
	~RouteManager();
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
