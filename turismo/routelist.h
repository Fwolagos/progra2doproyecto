#pragma once
#ifndef ROUTELIST_H
#define ROUTELIST_H
#include <iostream>
#include <string>
#include "route.h"
using namespace std;


class RouteList
{
private:
	Route* head;

	



public:///Esto es lo unico publico 
	RouteList();
	~RouteList();
	void menu(sf::RenderWindow&);
	bool routeExist(string);
	Route& getRoute(string);
	void createRoute(sf::RenderWindow&);
	void showRoutes(sf::RenderWindow&);
	void delRoute();///no le vamos a pasar window a ver que
	void renameRoute();
};
#endif
