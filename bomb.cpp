#include "const.h"
#include "bomb.h"

std::string Bomb::bomb_file_names[] =
{ "bomb.png", "bomb1.png",
"bomb2t.png" };

Bomb::Bomb() {
	size_t type = rand() % 3;
	texture.loadFromFile(Bomb::bomb_file_names[type]);
	sprite.setTexture(texture);
	spawn();
}
void Bomb::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Bomb::update() {
	sprite.move(speedx, speedy);
	if (sprite.getPosition().x < 0.f - getWidth() ||
		sprite.getPosition().x > WINDOW_WIDTH ||
		sprite.getPosition().y > WINDOW_HEIGHT
		)
	{
		spawn();
	}
}
size_t Bomb::getWidth() { return sprite.getLocalBounds().width; }
size_t Bomb::getHeight() { return sprite.getLocalBounds().height; }
sf::FloatRect Bomb::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Bomb::getPosition() { return sprite.getPosition(); }
void Bomb::spawn() {
	float startx = rand() % (static_cast<size_t>(WINDOW_WIDTH) - getWidth() + 1);
	float starty = rand() % (static_cast<size_t>(WINDOW_HEIGHT) + 1) - WINDOW_HEIGHT;
	sprite.setPosition(startx, starty);
	speedx = rand() % 5 - 2;
	speedy = rand() % 8 + 3;
}
sf::Vector2f Bomb::getCenter() {
	return sf::Vector2f
	(
		sprite.getPosition().x + getWidth() / 2.0,
		sprite.getPosition().y + getHeight() / 2.0
	);
}