#include "routelist.h"


RouteList::RouteList() {
	this->head = nullptr;
}

RouteList::~RouteList() {}

bool RouteList::routeExist(string name) {
	Route* temp = head;
	while (temp->getNext() != nullptr && temp->getName() != name) {
		temp = temp->getNext();
	}
	if (temp->getNext() == nullptr && temp->getName() != name) {
		return false;
	}
	else {
		return true;
	}
}

Route& RouteList::getRoute(string name) {
	Route* temp = head;
	while (temp->getNext() != nullptr && temp->getName() != name) {
		temp = temp->getNext();
	}
	return *temp;


}

void RouteList::addRoute(Route* route) {
	if (head == nullptr) {
		head = route;
	}
	else {
		Route* current = head;
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		current->setNext(route);
		route->setPrev(current);
	}
}

void RouteList::displayRoutes() {
	Route* current = head;
	while (current != nullptr) {
		std::cout << current->getName() << ", ";
		current = current->getNext();
	}
}

void RouteList::delRoute() {
	string name;
	displayRoutes();

	cout << "Que ruta desea eliminar: ";
	cin.ignore();
	getline(cin, name);
	if (!routeExist(name)) {
		cout << "Ruta no existe o nombre no coincide!" << endl;
		return;
	}
	Route* current = head;
	while (current->getNext() != nullptr && current->getName() != name) {
		current = current->getNext();
	}
	if (current->getNext() == nullptr && current->getName() != name) {
		cout << "Ruta no encontrada o nombre no coincide!" << endl;
		return;
	}
	else {
		Route* next;
		Route* prev;
		next = current->getNext();
		prev = current->getPrev();

		next->setPrev(prev);
		prev->setNext(next);
		delete current;
		return;
	}

}

void RouteList::renameRoute() {
	string name;
;
	displayRoutes();

	cout << "Ingrese el nombre de la ruta que desea renombrar :";
	cin.ignore();
	getline(cin, name);

	if (!routeExist(name)) {
		cout << "Ruta no encontrada o nombre no coincide" << endl;
		system("pause");
		return;
	}
	cout << "Ingrese el nuevo nombre: ";
	cin.ignore();
	getline(cin, name);

	getRoute(name).setName(name);

}







