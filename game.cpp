#include "game.h"
Game::Game() :
	window(sf::VideoMode(
		static_cast<size_t> (WINDOW_WIDTH),
		static_cast<size_t> (WINDOW_HEIGHT)
	),
		"game",
		sf::Style::Titlebar | sf::Style::Close
	), 
	player(WINDOW_WIDTH / 2 - 120 / 2.f,
		WINDOW_HEIGHT - 120.f, "k_.png")
{
	window.setFramerateLimit(60);
	fruit_sprites.reserve(7);
	for (size_t i = 0; i < 7; i++) {
		fruit_sprites.push_back(new Fruit());
	}
	/*bomb_sprites.reserve(3);
	for (size_t i = 0; i < 3; i++) {
		bomb_sprites.push_back(new Bomb());
	}*/
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
	}
}
void Game::update() {
	switch (game_state) {
	case PLAY:
		player.update();
		for (size_t i = 0; i < 7; i++) {
			fruit_sprites[i]->update();
		}
		/*for (size_t i = 0; i < 3; i++) {
			bomb_sprites[i]->update();
		}*/
		check_collisions();
		break;
	case GAME_OVER:
		break;
	}
}
void Game::draw() {

	window.clear();
	switch (game_state) {

	case PLAY:
		for (size_t i = 0; i <7; i++) {
			fruit_sprites[i]->draw(window);
		}
		/*for (size_t i = 0; i < 3; i++) {
			bomb_sprites[i]->draw(window);
		}*/
		player.draw(window);
		
		break;
	}
	window.display();
}
void Game::check_collisions() {
	
	for (size_t i = 0; i < 7; i++) {
		if (player.getHitBox().intersects(
			fruit_sprites[i]->getHitBox()))
		{
			player.reduceSc(fruit_sprites[i]->getWidth() / 3);
			fruit_sprites[i]->spawn();
		}
	}
	/*for (size_t i = 0; i < 7; i++) {
		if (player.getHitBox().intersects(
			bomb_sprites[i]->getHitBox()))
		{
			player.reduceHp(bomb_sprites[i]->getWidth() / 3);
			bomb_sprites[i]->spawn();
		}
	}*/
	if (player.isDead()) game_state = GAME_OVER;
}