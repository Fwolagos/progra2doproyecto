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
	text.setPosition(TEXBOX_WIDTH, TEXBOX_HEIGHT);
	textBox.setSize(sf::Vector2f(300, 40));
	textBox.setFillColor(sf::Color::White);
	textBox.setPosition(sf::Vector2f(TEXBOX_WIDTH, TEXBOX_HEIGHT));
	isTextEntered = false;
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
	cout << "\n=== COMANDOS DISPONIBLES ===\n";
	cout << "Ctrl + C: Crear ruta\n";
	cout << "Ctrl + E: Eliminar ruta\n";
	cout << "Ctrl + V: Ver rutas\n";
	//cout << "Ctrl + D: Editar ruta\n";
	/*cout << "Ctrl + Q: Salir\n";*/
	cout << "Ctrl + R: limpiar pantalla\n";
	cout << "=============================\n";
}

void RouteManager::initialize() {
	importDates();
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
			if (event.type == sf::Event::Closed) {
				exportToFile();
				window.close();
			}
			
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				if (state == 2) {
					drawRoute(window);
				}


			}

			if (event.type == sf::Event::KeyPressed) {

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
					state = 2;
					ressetVectors();
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					ressetVectors();
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
					routeList.displayRoutes();
					state = 4;
				}
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					routeList.displayRoutes();
					state = 5;
				}
			
					if (state == 2 && event.key.code == sf::Keyboard::Escape) {
					state = 0;
					isTextEntered = false;
					saveRoute();


				}
			}

			// Manejar entrada de texto
			if (event.type == sf::Event::TextEntered && isTextEntered) {
				getText(event);
			}
		}
		if (state == 4|| state == 5) {
			isTextEntered = true;// esto es para que no me tome caracteres raros que no van

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

		window.draw(textBox);
		window.draw(text);
		window.display();

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

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f currentPoint(mousePos.x, mousePos.y);

	// Dibujar el punto en la pantalla
	circle.setPosition(currentPoint.x - RADIUS, currentPoint.y - RADIUS);
	circles.push_back(circle);

	// Si ya hay puntos, genera una curva entre el último punto y el nuevo
	if (!lines.empty()) {
		sf::Vector2f lastPoint = lines.back().position;
		vector<sf::Vertex> curve = generateCurve(lastPoint, currentPoint);
		lines.insert(lines.end(), curve.begin(), curve.end());
	}
	else {
		// Si es el primer punto, simplemente agrégalo a la lista
		lines.push_back(sf::Vertex(currentPoint, COLOR_LINE));
	}

	isTextEntered = true;
	state = 3;
}

void RouteManager::saveRoute() {
	PointList pointList;
	int size = circles.size();
	for (int i = 0; i < size; i++) {
		sf::Vector2f position = circles[i].getPosition();
		pointList.addPoint(labels[i].getString(), position.x, position.y);
	}
	string routename;
	routename = labels[0].getString() + "-" + labels[labels.size() - 1].getString();
	Route* route = new Route();
	route->setName(routename);
	route->setPointList(pointList);
	routeList.addRoute(route);
	ressetVectors();
}

void RouteManager::getText(sf::Event& event) {
	//cout << "Pude ingresar texto: ";
	// Si se presiona Enter, imprime y reinicia el texto
	if (event.text.unicode == '\r') { // '\r' es Enter en SFML
		if (state == 3) {
			std::cout << "Texto ingresado: " << inputText << std::endl;
			sf::Vector2f position = circles[circles.size() - 1].getPosition();
			label.setString(inputText);
			label.setPosition(sf::Vector2f(position.x, position.y));

			labels.push_back(label);
			inputText.clear();
			isTextEntered = false;
			state = 2;
		}
		if (state == 4) {
			std::cout << "Texto ingresado: " << inputText << std::endl;
			isTextEntered = false;
			loadRoute(inputText);
			inputText.clear();
			state = 0;
		}
		if (state == 5) {
			std::cout << "Texto ingresado: " << inputText << std::endl;
			routeList.delRoute(inputText);
			isTextEntered = false;
			inputText.clear();
			state = 0;
		}


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

void RouteManager::loadRoute(string& routeName) {
	ressetVectors();
	if (routeList.routeExist(routeName)) {
		Route& route = routeList.getRoute(routeName);
		PointList& pointList = route.getPointList();
		PointNode& head = pointList.getHead();
		///ya que tengo a head literalmente cargo lo puntos
		PointNode* current = &head;
		while (current != nullptr) {
			circle.setPosition(sf::Vector2f(current->getX(), current->getY()));
			circles.push_back(circle);
			lines.push_back(sf::Vertex(sf::Vector2f(current->getX(), current->getY()), COLOR_LINE));
			label.setString(current->getName());
			labels.push_back(label);
			current = current->getNext();
		}

		return;
	}
	else {
		cout << "Ruta no encontrada" << endl;
		state = 0;
		return;
	}
}


///*************************cargar y descarga de datos a un txt

void RouteManager::exportToFile() {
	ofstream outFile(PATH_FILE);
	if (!outFile.is_open()) {
		cout << "No se pudo abrir el archivo para guardar." << endl;
		return;
	}

	Route* currentRoute = &routeList.getHead();
	while (currentRoute != nullptr) {
		outFile << "Route: " << currentRoute->getName() << endl;
		PointNode* currentPoint = &currentRoute->getPointList().getHead();
		while (currentPoint != nullptr) {
			outFile << "Point: " << currentPoint->getName() << ","
				<< currentPoint->getX() << ","
				<< currentPoint->getY() << endl;
			currentPoint = currentPoint->getNext();
		}
		currentRoute = currentRoute->getNext();
		outFile << "EndRoute" << endl; // Marcador para finalizar una ruta
	}

	outFile.close();
	cout << "Datos guardados en " << PATH_FILE << endl;
}
void RouteManager::importDates() {
	ifstream inFile(PATH_FILE);
	if (!inFile.is_open()) {
		cout << "No se pudo abrir el archivo para cargar." << endl;
		return;
	}

	string line, routeName, pointName;
	int x, y;
	Route* currentRoute = nullptr;

	while (getline(inFile, line)) {
		if (line.find("Route:") == 0) { // Detecta una nueva ruta
			routeName = line.substr(7); // Elimina "Route: "
			currentRoute = new Route(routeName);
			routeList.addRoute(currentRoute);
		}
		else if (line.find("Point:") == 0) { // Detecta un nuevo punto
			size_t comma1 = line.find(",", 7);
			size_t comma2 = line.find(",", comma1 + 1);
			pointName = line.substr(7, comma1 - 7);
			x = stoi(line.substr(comma1 + 1, comma2 - comma1 - 1));
			y = stoi(line.substr(comma2 + 1));

			if (currentRoute != nullptr) {
				currentRoute->getPointList().addPoint(pointName, x, y);
			}
		}
		else if (line == "EndRoute") {
			currentRoute = nullptr; // Finaliza una ruta
		}
	}

	inFile.close();
	cout << "Datos cargados desde " << PATH_FILE << endl;
}

vector<sf::Vertex> RouteManager::generateCurve(const sf::Vector2f& start, const sf::Vector2f& end) {
	vector<sf::Vertex> curve;

	// Generar un punto de control intermedio
	sf::Vector2f control = (start + end) / 2.0f; // Punto medio
	float offset = 50.0f; // Ajusta este valor para controlar la curvatura
	control.x += static_cast<float>(rand() % static_cast<int>(offset * 2)) - offset;
	control.y += static_cast<float>(rand() % static_cast<int>(offset * 2)) - offset;

	// Generar puntos de la curva usando interpolación cuadrática
	for (float t = 0; t <= 1; t += 0.01f) {
		float u = 1 - t;
		sf::Vector2f point = (u * u) * start + (2 * u * t) * control + (t * t) * end;
		curve.push_back(sf::Vertex(point, COLOR_LINE));
	}

	return curve;
}

















