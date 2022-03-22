#include "const.h"
#include "fruit.h"

std::string Fruit::fruit_file_names[] =
{"melon.png",
"coconut.png",
"cherry.png", 
"lemon.png",
 };

Fruit::Fruit() {
	size_t type = rand() % 3;
	texture.loadFromFile(Fruit::fruit_file_names[type]);
	sprite.setTexture(texture);
	spawn();
}
void Fruit::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Fruit::update() {
	sprite.move(speedx, speedy);
	if (sprite.getPosition().x < 0.f - getWidth() ||
		sprite.getPosition().x > WINDOW_WIDTH ||
		sprite.getPosition().y > WINDOW_HEIGHT
		)
	{
		spawn();
	}
}
size_t Fruit::getWidth() { return sprite.getLocalBounds().width; }
size_t Fruit::getHeight() { return sprite.getLocalBounds().height; }
sf::FloatRect Fruit::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Fruit::getPosition() { return sprite.getPosition(); }
void Fruit::spawn() {
	float startx = rand() % (static_cast<size_t>(WINDOW_WIDTH) - getWidth() + 1);
	float starty = rand() % (static_cast<size_t>(WINDOW_HEIGHT) + 1) - WINDOW_HEIGHT;
	sprite.setPosition(startx, starty);
	speedx = rand() % 5 - 2;
	speedy = rand() % 8 + 3;
}
sf::Vector2f Fruit::getCenter() {
	return sf::Vector2f
	(
		sprite.getPosition().x + getWidth() / 2.0,
		sprite.getPosition().y + getHeight() / 2.0
	);
}