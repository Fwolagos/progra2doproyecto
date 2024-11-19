#include "routemanager.h"

RouteManager::RouteManager() {
	this->routeList = RouteList();
	this->state = 0;
	circle.setRadius(RADIUS);
	circle.setFillColor(COLOR_POINT);
	circle.setOutlineColor(COLOR_OUTLINE);
	font.loadFromFile(PATH_FONT);
	this->label = sf::Text();
	label.setFont(font);
	label.setCharacterSize(CHARACTER_SIZE);
	label.setFillColor(COLOR_TEXT);
	label.setOutlineThickness(OUTLINETHICKNESS);

	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Black);
	text.setPosition(50, 200);
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
	header();
	std::cout << "\n=== COMANDOS DISPONIBLES ===\n";
	std::cout << "Ctrl + C: Crear ruta\n";
	std::cout << "Ctrl + E: Eliminar ruta\n";
	std::cout << "Ctrl + V: Ver rutas\n";
	std::cout << "Ctrl + D: Editar ruta\n";
	std::cout << "Ctrl + Q: Salir\n";
	std::cout << "=============================\n";
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

			if (event.type == sf::Event::KeyPressed ) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					state = 2;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
					routeList.displayRoutes();
				}

				if (state == 2 && event.key.code == sf::Keyboard::Escape) {
					state = 0;
					saveRoute();
				}
			}

			// Manejar entrada de texto
			if (event.type == sf::Event::TextEntered && state == 3) {
				getText(event);
			}
		}
		text.setString(inputText);
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

		window.draw(text);
		window.display();
		if (state == 1) {
			ressetVectors();
		}
		if (state == 0) {
			menu();
			state = 1;
		}

	}
	return;
}

void RouteManager::ressetVectors() {
	circles.clear();
	lines.clear();
	labels.clear();
}

void RouteManager::drawRoute(sf::RenderWindow& window) {

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);/// esto podria estar dentro de una funcion y nada mas le paso window
	circle.setPosition(sf::Vector2f(mousePos.x - RADIUS, mousePos.y - RADIUS));
	circles.push_back(circle);
	lines.push_back(sf::Vertex(sf::Vector2f(mousePos.x, mousePos.y), COLOR_LINE));
	state = 3;
	return;
}

void RouteManager::saveRoute() {
	PointList pointList;
	int size = circles.size();
	for (int i = 0; i < size; i++) {
		sf::Vector2f position = circles[i].getPosition();
		pointList.addPoint(labels[i].getString(), position.x, position.y);
	}
	string routename;
	routename = labels[0].getString() + " - " + labels[labels.size() - 1].getString();
	Route* route = new Route();
	route->setName(routename);
	route->setPointList(pointList);
	routeList.addRoute(route);
}

void RouteManager::getText(sf::Event& event) {
	cout << "Pude ingresar texto: ";
	// Si se presiona Enter, imprime y reinicia el texto
	if (event.text.unicode == '\r') { // '\r' es Enter en SFML
		std::cout << "Texto ingresado: " << inputText << std::endl;
		sf::Vector2f position = circles[circles.size() - 1].getPosition();
		label.setString(inputText);
		label.setPosition(sf::Vector2f(position.x, position.y));

		labels.push_back(label);
		inputText.clear();
		state = 2;
	}
	// Si se presiona Backspace, elimina el último carácter
	else if (event.text.unicode == '\b') { // '\b' es Backspace
		if (!inputText.empty()) {
			inputText.pop_back();
		}
	}
	// Para caracteres normales, los agregamos al texto
	else if (event.text.unicode < 128) { // Filtrar caracteres válidos (ASCII)
		inputText += static_cast<char>(event.text.unicode);
	}
}





















