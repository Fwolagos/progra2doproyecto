#include "button.h"
Button::Button(float x, float y, float width, float height, const string& label) {
	buttonShape.setSize(sf::Vector2f(width, height));
	buttonShape.setPosition(x, y);
	buttonShape.setFillColor(NORMAL_COLOR);

	if (!font.loadFromFile(PATH_FONT)) {
		cerr << "Error al cargar la fuente" << endl;
	}

	///texto del boton
	buttonText.setFont(font);
	buttonText.setString(label);
	buttonText.setCharacterSize(CHARACTER_SIZE);
	buttonText.setFillColor(CHARACTER_COLOR);
	buttonText.setPosition(
		x + (width / VALUE) - (buttonText.getLocalBounds().width / VALUE),
		y + (height / VALUE) - (buttonText.getLocalBounds().height / VALUE)
	);
}
Button::Button(float x, float y, const string& label) {
	buttonShape.setSize(sf::Vector2f(WIDTH, HEIGHT));
	buttonShape.setPosition(x, y);
	buttonShape.setFillColor(NORMAL_COLOR);

	if (!font.loadFromFile(PATH_FONT)) {
		cerr << "Error al cargar la fuente" << endl;
	}

	///texto del boton
	buttonText.setFont(font);
	buttonText.setString(label);
	buttonText.setCharacterSize(CHARACTER_SIZE);
	buttonText.setFillColor(CHARACTER_COLOR);
	buttonText.setPosition(
		x + (WIDTH / VALUE) - (buttonText.getLocalBounds().width / VALUE),
		y + (HEIGHT / VALUE) - (buttonText.getLocalBounds().height / VALUE)
	);
}

Button::~Button() {}

void Button::draw(sf::RenderWindow& window) {
	window.draw(buttonShape);
	window.draw(buttonText);
}

void Button::setOnClick(function<void()> func) {
	onClick = func;
}

void Button::handleEvenet(sf::Event event, sf::RenderWindow& window) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	bool isHovered = buttonShape.getGlobalBounds().contains(
		static_cast<float>(mousePosition.x),
		static_cast<float>(mousePosition.y));

	if (isHovered) {
		buttonShape.setFillColor(HOVER_COLOR);
	}
	else {
		buttonShape.setFillColor(NORMAL_COLOR);
	}

	if (isHovered && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		buttonShape.setFillColor(PRESSED_COLOR);
		if (onClick) {
			onClick();
		}
	}
}



















