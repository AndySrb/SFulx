#include "Game.h"


Game::Game(): m_window("SFulx", sf::Vector2u(800,600)),
m_AssetMenager(new AssetMenager())
{
// Setting up class members.
	std::cout << "Game::Game()" << std::endl;
	m_window.setFrameRate(60);


}

Game::~Game() {}

void Game::Update()
{
m_window.Update(); // Update window events.
HandleInput();
// someObject->Update(delta);
updateScore();
delta = m_window.GetDeltaTime();
}


void Game::Render()
{
m_window.BeginDraw(); // Clear.
//m_window.Draw(<Some Object>); //Here add draw commands
m_window.EndDraw();
}


void Game::HandleInput()
{
	if (m_InputHandler.isKeyboardKeyPressed(sf::Keyboard::Enter))
	{
		//Do something
	}
	if (m_InputHandler.isKeyboardKeyPressed(sf::Keyboard::Up))
	{
		//Do something
	}

}

Window* Game::GetWindow()
{
	Window *ptr = &m_window;
	return ptr;
}

