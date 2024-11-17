#include "routemanager.h"


RouteManager::RouteManager() {
	this->head = nullptr;
}

RouteManager::~RouteManager() {}

void RouteManager::header() {
	system("cls");
	// Datos para el encabezado
	string titulo = "GESTOR DE RUTAS TURÍSTICAS";
	string desarrollador = "Antony Vega";
	string fecha = "2024";

	// Imprimir el encabezado
	cout << "\n";
	cout << "╔══════════════════════════════════════════╗" << endl;
	cout << "║ " << titulo << "                                     ║" << endl;
	cout << "║ Desarrollador: " << desarrollador << "                  ║" << endl;
	cout << "║ Fecha: " << fecha << "                        ║" << endl;
	cout << "╚══════════════════════════════════════════╝" << endl;
	cout << "\n";
}

void RouteManager::menu(sf::RenderWindow& window) {
	int option;
	header();
	cout << "----------------------------" << endl;
	cout << "1. Ver rutas" << endl;
	cout << "2. Crear ruta" << endl;
///	cout << "3. Editar ruta" << endl;
	cout << "4. Eliminar ruta" << endl;
	cout << "5. Renombrar ruta" << endl;
///	cout << "6. Renombrar punto de ruta" << endl;
	cout << "0. Salir" << endl;
	cout << "----------------------------" << endl;
	cout << "Seleccione una opción: ";
	cin >> option;

	if (cin.fail()) {
		cin.clear(); // Limpia el estado de error de `cin`
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada incorrecta
		menu(window); // Llamada recursiva
		return;
	}
	switch (option) {
	case 1:
		// Lógica para "Ver rutas"
		cout << "Mostrando rutas..." << endl;
		break;
	case 2:
		// Lógica para "Crear ruta"
		cout << "Creando nueva ruta..." << endl;
		break;
	case 3:
		// Lógica para "Editar ruta"
		cout << "Editando ruta..." << endl;
		break;
	case 4:
		// Lógica para "Eliminar ruta"
		cout << "Eliminando ruta..." << endl;
		break;
	case 5:
		// Lógica para "Renombrar ruta"
		cout << "Renombrando ruta..." << endl;
		break;
	case 6:
		// Lógica para "Renombrar punto de ruta"
		cout << "Renombrando punto de ruta..." << endl;
		break;
	case 0:
		// Opción para salir

		window.close();
		cout << "Saliendo del programa..." << endl;
		return;
	default:
		// Si se ingresa un número fuera del rango
		menu(window); // Llamada recursiva para volver a mostrar el menú
		return;
	}
}

void RouteManager::initialize() {
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), NAME_WINDOW);

	sf::Texture texture;
	if (!texture.loadFromFile(BACKGROUND)) {
		system("echo error imagen no cargada& pause");
		return;
	}
	sf::Sprite sprite(texture);



	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		if (!lines.empty()) {
			// Si hay puntos en lines, se dibujan como una línea continua conectada entre ellos usando sf::LinesStrip.
			// sf::LinesStrip dibuja una serie de vértices conectados, formando una línea desde el primer punto hasta el último.
			window.draw(&lines[0], lines.size(), sf::LinesStrip);
		}
		window.draw(sprite);
		///dibujar puntos
		for (const auto& circles : circles) {
			window.draw(circles);
		}

		window.display();
		menu(window);
	}
}

/// <summary>
/// limpiar vectores 
/// </summary>
void RouteManager::ressetVectors() {
	circles.clear();
	lines.clear();
}

bool RouteManager::routeExist(string name) {
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

Route& RouteManager::getRoute(string name) {
	Route* temp = head;
	while (temp->getNext() != nullptr && temp->getName() != name) {
		temp = temp->getNext();
	}
	return *temp;


}

void RouteManager::createRoute(sf::RenderWindow& window) {
	ressetVectors();

	string name;
	Route* route = new Route();
	PointList pointList;
	bool isDrawing = true;

	std::cout << "Ingrese el nombre de la ruta: ";
	cin.ignore();
	getline(cin, name);
	route->setName(name);


	sf::CircleShape circle(RADIUS);///aqui luego damos retoques con el tema de los circulos
	circle.setFillColor(COLOR_POINT);

	while (isDrawing) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return;
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				float x = static_cast<float>(mousePos.x);
				float y = static_cast<float>(mousePos.y);

				circle.setPosition(x - RADIUS, y - RADIUS);/// si centras los puntos 
				circles.push_back(circle);

				///conectamemos lineas
				lines.push_back(sf::Vertex(sf::Vector2f(x, y), COLOR_LINE));

				cout << "Ingrese el nombre del lugar en el punto (" << x << ", " << y << "): ";
				cin.ignore();
				getline(cin, name);
				pointList.addPoint(name, x, y);
			}


			// Salir del modo de creación si presionamos ESC
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				isDrawing = false;
				route->setPointList(pointList);
				addRoute(route);
			}
		}

		window.clear();/// revisar si este en alguna ocacion nos afecta con el tema de limpiar pantalla a cada rato 
		window.display();
	}
}

void RouteManager::addRoute(Route* route) {
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

void RouteManager::showRoutes(sf::RenderWindow& window) {
	header();
	ressetVectors();;
	displayRoutes();
	string name;

	cout << "Ingrese el nombre de la ruta que desea mostrar: ";
	cin.ignore();
	getline(cin, name);

	if (!routeExist(name)) {
		cout << "Ruta no existe o nombre no coincide con la ruta" << endl;
		system("pause");
		menu(window);
		return;

	}

	getRoute(name).getPointList().loadPoints(circles, lines);
	return;

}

void RouteManager::displayRoutes() {
	Route* current = head;
	while (current != nullptr) {
		std::cout << current->getName() << ", ";
		current = current->getNext();
	}
}










