#include "routemanager.h"
#define PATH "sources/"


RouteManager::RouteManager() {
	this->head = nullptr;
}

void RouteManager::menu() {
	
}

void RouteManager::header() {

}

void RouteManager::initialize() {
	sf::RenderWindow window(sf::VideoMode(750,649), "test");

	sf::Texture texture;
	if (!texture.loadFromFile(PATH"img/CostaRica.jpg")) {
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
		window.display();
		menu();
	}
}












