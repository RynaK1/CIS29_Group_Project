#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Player : public GameObject
{
	// Default values
	static const float PLAYER_WIDTH;
	static const float PLAYER_HEIGHT;
	static const float PLAYER_X_VELOCITY;
	static const float PLAYER_Y_VELOCITY;

public:

	Player(const sf::Texture& texture, const sf::IntRect& rect, const sf::Vector2f& pos) :
		GameObject(
			texture,
			rect,
			pos,
			sf::Vector2f(0, 0),
			5.0f		// Initial speed
		)
	{ }
	~Player();

};


#endif
