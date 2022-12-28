#include "Window.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>


Window::Window(){ Setup("Window", sf::Vector2u(640,480));}

Window::Window(const std::string& l_title,
const sf::Vector2u& l_size)
{
std::cout << "Window::Window(l_title,l_size)" << std::endl;
Setup(l_title,l_size);

mClock.restart(); 
}

Window::~Window(){ 
	Destroy();
}

void Window::Create()
{
auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
m_window.create({ m_windowSize.x, m_windowSize.y, 64 }, m_windowTitle, style);
}

void Window::Destroy(){
m_window.close();
}

void Window::Update(){
			sf::Event event;
		while(m_window.pollEvent(event))
		{
		if (event.KeyPressed && event.key.code == sf::Keyboard::F5)
			ToggleFullscreen();

		if (event.KeyPressed && event.key.code == sf::Keyboard::F6)
			ToggleFullscreen();

		switch (event.type)
		{
		case event.Closed:
			m_isDone = true;
			break;
		case event.KeyPressed:
			m_InputHandler.UpdateKey(event.key.code,true);
			break;
		case event.KeyReleased:
			m_InputHandler.UpdateKey(event.key.code,false);
			break;
		}
		}
}

void Window::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();

	m_window.setFramerateLimit(frameRate);	
}

void Window::BeginDraw(){ m_window.clear(sf::Color::Black); }

void Window::EndDraw(){ m_window.display(); }

bool Window::IsDone(){ return m_isDone; }

bool Window::IsFullscreen(){ return m_isFullscreen; }

sf::Vector2u Window::GetWindowSize(){ return m_windowSize; }

void Window::Draw(sf::Drawable&l_drawable)
{
m_window.draw(l_drawable);
}

sf::Time Window::GetDeltaTime()
{
	return mClock.restart();
}


