#include <sstream>
#include<SFML\Graphics.hpp>
#include "GameComponents\Player.h"
#include "GameComponents\Ball.h"
using namespace sf;

//TODO: Polish game add sprites to class make like it real volleyball



int main() {

	VideoMode vm(1920, 1080);

	RenderWindow window(vm,"Volleyball Game",Style::Default);

	int score = 0;
	int lives = 3;

	//Create a bat at the bottom center of the screen
	Player player(1920/2,1080-20);

	//Ball Section
	Ball ball(1920 / 2,0);
	//Create a TExt object called HUD
	Text Hud;

	//Font
	Font font;
	font.loadFromFile("resources/Fonts/KrunchBold.ttf");
	Hud.setFont(font);
	Hud.setCharacterSize(75);
	Hud.setFillColor(Color::White);
	Hud.setPosition(20, 20);

	//clock for time everything
	Clock clock;


	while (window.isOpen())
	{
		/*
		         Handle Palyer Input
                  *****************
        */
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				//Quit when window is closed
				window.close();
			}
		}
		//Close window by pressing ESC
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player.moveLeft();
		}
		else
		{
			player.stopLeft();

		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player.moveRight();
		}
		else
		{
			player.stopRight();
		}
		


		/*
		           Update Scence Section
				    (HUD, player,ball)
		             ***************
		*/
		Time dt = clock.restart();

		player.update(dt);
		ball.update(dt);
		//Update the HUD text
		std::stringstream ss;
		ss << "Score: " <<score<< "   Lives: " << lives;
		Hud.setString(ss.str());

		//Handling Ball Hittig the bottom
		if (ball.getPosition().top > window.getSize().y)
		{
			//Reverse ball direction
			ball.reboundBottom();

			//Remove life
			lives--;

			//check if no life left
			if (lives<1)
			{
				//reset the score
				score = 0;
				//reset the lives
				lives = 3;
			}
		}
		//Handle the ball hitting top
		if (ball.getPosition().top <0)
		{
			ball.reboundPlayerOrTop();

			//addpoint to the player
			score++;
		}
		//Handle the ball hitting sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x)
		{
			ball.reboundSides();
		}
		// Has the ball hit the player
		if (ball.getPosition().intersects(player.getPosition()))
		{
			//Hit Detected reverse the ball and score a point
			ball.reboundPlayerOrTop();
		}

		
		/*
		           Draw Scence Section
				    (HUD, player,ball)
		             ***************
		*/

		window.clear();
		window.draw(Hud);
		window.draw(player.getShape());
		window.draw(ball.getShape());

		window.display();

	}

	return 0;
}