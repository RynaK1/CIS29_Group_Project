#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Projectile.h"

const int MAX_PROJECTILE_NUM = 500;
const int PROJECTILE_TIME_INTERVAL = 200;
const sf::Time PROJECTILE_TIME_DELTA = sf::milliseconds(PROJECTILE_TIME_INTERVAL);


int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Space Invader?", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Green);

	std::vector<Projectile*> projectileArray;
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				printf("%c", e.text);
			}
		}

		// Handle Key press
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move(0.0f, 0.1f);
		}


		sf::Time elapse_time = clock.getElapsedTime();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			// Interval for each projectile
			if (elapse_time >= PROJECTILE_TIME_DELTA)
			{
				std::cout << elapse_time.asMilliseconds() << std::endl;
				projectileArray.push_back(
					new Projectile(player.getPosition() + sf::Vector2f(player.getSize().x / 2, 0.0f)));
				clock.restart();
			}
		}


		window.clear();

		// Draw all projectile
		for (int i = 0; i < projectileArray.size(); i++)
		{
			if (projectileArray[i]->checkBoundry())
			{
				projectileArray[i]->update();
				window.draw(*projectileArray[i]);
			}
			else
			{
				std::swap(projectileArray[i], projectileArray.back());
				delete projectileArray.back();
				projectileArray.pop_back();
			}
		}
		window.draw(player);
		window.display();
	}

	return 0;
}