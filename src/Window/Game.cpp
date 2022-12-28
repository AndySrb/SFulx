#include "Game.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>


Game::Game(): m_window("SFulx", sf::Vector2u(1366,768)),
m_AssetMenager(new AssetMenager()), m_FontMenager(new FontMenager())//,circleShape(60)
{
// Setting up class members.
	std::cout << "Game::Game()" << std::endl;
	m_window.setFrameRate(60);
	//m_FontMenager->addFont(<font.ttf>); //Put here font, look FontMenager.h for more info
	//circleShape.setFillColor(sf::Color::Blue);
	//
	sf::Texture *texture = &m_AssetMenager->GetTexture("Textures-16.png");
	m_object.setTextureSprite(texture,sf::IntRect(16,0,16,16));
}

Game::~Game() {}

void Game::Update()
{
m_window.Update(); // Update window events.
HandleInput();
//someObject->Update(delta);
//updateScore();


// In Update function here we are checking for input
// look in src/Logic/Player for example - refactoring soon
// Documentation will be slowly added over time
m_PlayerClass.Update(delta); 




delta = m_window.GetDeltaTime();
}


void Game::Render()
{
m_window.BeginDraw(); // Clear.
//m_window.Draw(circleShape);

// Testing collision and imput handling from diffrent class.
m_window.Draw(m_PlayerClass);
m_window.Draw(m_object);

if (m_object.getSprite()->getGlobalBounds().intersects(m_PlayerClass.getSprite()->getGlobalBounds()))
	std::cout << "Collison: Detected\n";
else 
	std::cout << "Collison: Not Detected \n";


//m_window.Draw(<Some Object>); //Here add draw commands
m_window.EndDraw();
}


void Game::HandleInput()
{
	/*
	if (m_InputHandler.isKeyboardKeyPressed(sf::Keyboard::Enter))
	{
		//Do something
	}
	if (m_InputHandler.isKeyboardKeyPressed(sf::Keyboard::Up))
	{
		//Do something
	}
	*/

}

Window* Game::GetWindow()
{
	Window *ptr = &m_window;
	return ptr;
}

