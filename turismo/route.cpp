#include "route.h"


Route::Route() {
	this->name = " ";
	///this->pointList = nullptr;
	this->next = nullptr;
	this->prev = nullptr;
}
Route::Route(string name) {
	this->name = name;
	this->next = nullptr;
	this->prev = nullptr;
}
Route::~Route(){}

void Route::setName(string name) {
	this->name = name;
}
void Route::setPointList(PointList pointList) {
	this->pointList = pointList;
}
void Route::setNext(Route* next) {
	this->next = next;
}
void Route::setPrev(Route* prev) {
	this->prev = prev;
}

string Route::getName() {
	return name;
}
PointList& Route::getPointList() {
	return pointList;
}
Route* Route::getNext() {
	return next;
}
Route* Route::getPrev() {
	return prev;
}





