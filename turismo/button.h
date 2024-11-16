#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#define PATH_FONT "sources/font/arial.ttf"
#define CHARACTER_SIZE 15 /// tamaño de la letra en los botones
#define WIDTH 200.f
#define HEIGHT 50.f
#include <SFML/Graphics.hpp>
#define CHARACTER_COLOR	sf::Color::White /// color de las letras creo
const float VALUE = 2.f; ///Constante para formula que sirve para centra el texto en el boton
const sf::Color NORMAL_COLOR = sf::Color::Blue;/// colores para los estados del boton 
const sf::Color HOVER_COLOR	= sf::Color::Green;
const sf::Color PRESSED_COLOR = sf::Color::Red;
#include <iostream>
#include <functional>
#include <string>
using namespace std;


class Button
{
private:
	sf::RectangleShape buttonShape; /// figura del boton que es un regtangulo
	sf::Text buttonText; ///texto en pantalla que vamos a colocar sobre  el boton
	sf::Font font; /// fuente para el texto
	function<void()> onClick; /// sacado del c# jaja para los botones XD para el tema de clis 
public:
	Button(float, float, float, float, const string&);
	Button(float , float , const string& );
	~Button();
	void draw(sf::RenderWindow&);
	void setOnClick(function<void()> func);
	void handleEvenet(sf::Event event, sf::RenderWindow& window);

};
#endif
