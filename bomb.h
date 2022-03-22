#pragma once
#include "SFML/Graphics.hpp"

class Bomb {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx;
	float speedy;
	static std::string bomb_file_names[];
public:
	Bomb();
	void draw(sf::RenderWindow& window);
	void update();
	size_t getWidth();
	size_t getHeight();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	sf::Vector2f getCenter();
	void spawn();
};