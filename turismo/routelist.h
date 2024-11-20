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
	bool routeExist(string);
	Route& getRoute(string);
	void delRoute(string&);///no le vamos a pasar window a ver que
	void renameRoute();
	void addRoute(Route*);
	void displayRoutes();
	Route& getHead();
};
#endif
