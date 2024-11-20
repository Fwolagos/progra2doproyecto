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

void RouteList::delRoute(string& name) {

	if (!routeExist(name)) {
		cout << "Ruta no existe o nombre no coincide!" << endl;
		return;
	}

	Route* current = head;

	// Buscar la ruta con el nombre especificado
	while (current != nullptr && current->getName() != name) {
		current = current->getNext();
	}

	// Si no se encontró la ruta
	if (current == nullptr) {
		cout << "Ruta no encontrada o nombre no coincide!" << endl;
		return;
	}

	// Si la ruta es la única en la lista
	if (current->getPrev() == nullptr && current->getNext() == nullptr) {
		head = nullptr; // La lista queda vacía
		delete current;
		return;
	}

	// Si la ruta es la primera en la lista
	if (current->getPrev() == nullptr) {
		head = current->getNext(); // El siguiente elemento se convierte en la cabeza
		head->setPrev(nullptr);
		delete current;
		return;
	}

	// Si la ruta es la última en la lista
	if (current->getNext() == nullptr) {
		current->getPrev()->setNext(nullptr);
		delete current;
		return;
	}

	// Si la ruta está en el medio de la lista
	Route* prev = current->getPrev();
	Route* next = current->getNext();
	prev->setNext(next);
	next->setPrev(prev);
	delete current;
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


Route& RouteList::getHead() {
	return*head;
}





