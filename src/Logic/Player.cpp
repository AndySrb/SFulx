#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <cstdio>
#include <iostream>

Player::Player()
{
	m_sprite.setRadius(80);
	ToggleColor();
}

void Player::ToggleColor()
{
    if(m_toggle)
	{
    m_sprite.setFillColor(sf::Color::Blue);
	m_toggle = false;
	}
    else
	{
    m_sprite.setFillColor(sf::Color::Red);
	m_toggle = true;
	}
}


void Player::Update(sf::Time time)
{
	if(m_InputHandler.isKeyboardKeyPressed(sf::Keyboard::Up))
	{
	m_sprite.move(0,-10);
	}
	if(m_InputHandler.isKeyboardKeyPressed(sf::Keyboard::Right))
	{
	m_sprite.move(10,0);
	}
	if(m_InputHandler.isKeyboardKeyPressed(sf::Keyboard::Left))
	{
	m_sprite.move(-10,0);
	}
	if(m_InputHandler.isKeyboardKeyPressed(sf::Keyboard::Down))
	{
	m_sprite.move(0,10);
	}
	if (m_InputHandler.isKeyboardKeyPressed(sf::Keyboard::Enter))
	{
		ToggleColor();
	}
}
