#include "Player.h"

Player::Player(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(50, 5));
	m_Shape.setPosition(m_Position);
}

Player::~Player()
{
}

FloatRect Player::getPosition()
{
	return m_Shape.getLocalBounds();
}

RectangleShape Player::getShape()
{
	return m_Shape;
}

void Player::moveLeft()
{
	m_MovingLeft = true;
}

void Player::moveRight()
{
	m_MovingRight = true;
}

void Player::stopLeft()
{
	m_MovingLeft = false;
}

void Player::stopRight()
{
	m_MovingRight = false;
}

void Player::update(Time dt)
{
	if (m_MovingLeft)
	{
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	if (m_MovingRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}
	m_Shape.setPosition(m_Position);
}
