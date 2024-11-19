#include "routemanager.h"

RouteManager::RouteManager() {
	this->routeList = RouteList();
	this->state = 2;
	circle.setRadius(RADIUS);
	circle.setFillColor(COLOR_POINT);
	circle.setOutlineColor(COLOR_OUTLINE);
	font.loadFromFile(PATH_FONT);
	this->label = sf::Text();
	label.setFont(font);
	label.setCharacterSize(CHARACTER_SIZE);
	label.setFillColor(COLOR_TEXT);
	label.setOutlineThickness(OUTLINETHICKNESS);
}

RouteManager::~RouteManager() {}


void RouteManager::header() {
	system("cls");
	// Datos para el encabezado
	string titulo = "GESTOR DE RUTAS TURISTICAS";
	string desarrollador = "Antony Vega";
	string fecha = "2024";

	// Imprimir el encabezado
	cout << "\n";
	/////////--------------------------------------------
	cout << "+------------------------------------------+" << endl;
	cout << "| " << titulo << "                         |" << endl;
	cout << "| Desarrollador: " << desarrollador << "   |" << endl;
	cout << "| Fecha: " << fecha << "                   |" << endl;
	cout << "+------------------------------------------+" << endl;
	cout << "\n";
}

void RouteManager::menu() {
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
	cout << "Seleccione una opcion: ";
	cin >> option;

	if (cin.fail()) {
		cin.clear(); // Limpia el estado de error de `cin`
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada incorrecta
		return;
	}
	switch (option) {
	case 1:
		///showRoutes(window);
		break;
	case 2:
		state = 2;
		///createRoute(window);
		break;
	case 3:
		// Lógica para "Editar ruta"
		cout << "Editando ruta..." << endl;
		break;
	case 4:
		///delRoute();
		break;
	case 5:
		///renameRoute();
		break;
	case 6:
		// Lógica para "Renombrar punto de ruta"
		cout << "Renombrando punto de ruta..." << endl;
		break;
	case 0:
		// Opción para salir

		///window.close();
		cout << "Saliendo del programa..." << endl;
		return;
	default:
		// Si se ingresa un número fuera del rango
		///menu(window); // Llamada recursiva para volver a mostrar el menú
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
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				if (state == 2) {
					drawRoute(window);
				}


			}
			if (event.type == sf::Event::KeyPressed && (state == 2 && event.key.code == sf::Keyboard::Escape)) {
				if (state == 2 && event.key.code == sf::Keyboard::Escape) {
					state = 1;
					///saveRoute();
				}
			}
		}

		window.clear();
		window.draw(sprite);
		if (!labels.empty()) {
			for (const auto& label : labels) {
				window.draw(label);
			}
		}
		if (!lines.empty()) {
			// Si hay puntos en lines, se dibujan como una línea continua conectada entre ellos usando sf::LinesStrip.
			// sf::LinesStrip dibuja una serie de vértices conectados, formando una línea desde el primer punto hasta el último.
			window.draw(&lines[0], lines.size(), sf::LinesStrip);
		}

		///dibujar puntos
		if (!circles.empty()) {
			for (const auto& circles : circles) {
				window.draw(circles);
			}
		}

		window.display();
		/*	if (state == 0) {
				menu();
			}*/

	}
	return;
}

void RouteManager::ressetVectors() {
	circles.clear();
	lines.clear();
}

void RouteManager::drawRoute(sf::RenderWindow& window) {
	//string name;
	//header();
	/*cout << "Ingrese el nombre del punto: ";*/
	//cin.ignore();
	//getline(cin, name);
	this->label.setString("Dinosaurio");
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);/// esto podria estar dentro de una funcion y nada mas le paso window
	label.setPosition(sf::Vector2f(mousePos.x, mousePos.y));
	circle.setPosition(sf::Vector2f(mousePos.x - RADIUS, mousePos.y - RADIUS));
	circles.push_back(circle);
	lines.push_back(sf::Vertex(sf::Vector2f(mousePos.x, mousePos.y), COLOR_LINE));
	this->labels.push_back(this->label);
	system("cls");
	return;
}

//void RouteManager::saveRoute() {
//	PointList route;
//	circles[1];
//	for (const auto& point : circles) {
//		sf::Vector2f position;
//		position = circle.getPosition();
//		route.
//	}
//}




















