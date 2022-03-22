#pragma once
#include "SFML/Graphics.hpp"

class Fruit {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx;
	float speedy;
	static std::string fruit_file_names[];
public:
	Fruit();
	void draw(sf::RenderWindow& window);
	void update();
	size_t getWidth();
	size_t getHeight();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	sf::Vector2f getCenter();
	void spawn();
};