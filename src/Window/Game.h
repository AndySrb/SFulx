#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SFML/System.hpp>
#include "Window.h"
#include "../Renderer/AssetMenager.h"
#include "../Renderer/Animator.h"
#include "../Input/InputHandler.h"



class Game
{

	public:
		Game();
		~Game();

		void HandleInput();
		void UpdateBall();
		void Update();
		void Render();
		void updateScore();

		Window* GetWindow();

	private:

		Window m_window;
		AssetMenager *m_AssetMenager;
		InputHandler m_InputHandler;
		sf::Time delta;
		sf::Font font;


};

#endif
