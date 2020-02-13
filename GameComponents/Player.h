#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Player
{
public:
	Player(float startX, float startY);
	~Player();
	FloatRect getPosition();
	RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt);



private:
	Vector2f m_Position;

	//Rectangle shape object
	RectangleShape m_Shape;

	float m_Speed = 1000.0f;
	bool m_MovingRight = false;
	bool m_MovingLeft = false;
	

};

