#ifndef WINDOW_H
#define WINDOW_H 

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Input/InputHandler.h"

class Window{
public:
	Window();
	Window(const std::string& l_title,const sf::Vector2u& l_size);
	~Window();
	void BeginDraw(); // Clear the window.
	void EndDraw(); // Display the changes.
	void Render();
	void Update();
	bool IsDone();
	bool IsFullscreen();
	sf::Vector2u GetWindowSize();
	void ToggleFullscreen();
	void Draw(sf::Drawable& l_drawable);

	void RefreshWindow()
	{
		this->Destroy();
		m_window.setSize(m_windowSize);
		this->Create();
	}

	void initializeShutdown()
	{
		m_isDone = true;
	}

	void setFrameRate(int fps)
	{
		frameRate = fps;
		if (frameRate != 0)
		{
		m_window.setFramerateLimit(fps);
		}
	}
	
	sf::RenderWindow* GetRenderWindow()
	{
		return &m_window;
	}

	sf::Time GetDeltaTime();

private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size)
	{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
	}

	sf::Event m_Event; // Used for InputHandler

	void Destroy();
	void Create();
	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;

	InputHandler m_InputHandler;


	int frameRate = 0;
	sf::Clock mClock;

};

#endif
