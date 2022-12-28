#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SFML/System.hpp>
#include "Window.h"
#include "../AssetManager/AssetManager.h"
//#include "../Renderer/Animator.h"
#include "../Renderer/FontManager.h"
#include "../Input/InputHandler.h"
#include "../AssetManager/ResourceManager.h"

#include "../Logic/Player.h"
#include "../Logic/Object.h"



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
		FontMenager *m_FontMenager;
		InputHandler m_InputHandler; //InputHandler is already initilized in Window.cpp
		ResourceManager *m_ResourceManager;

		sf::Time delta;
		sf::Font font;

		Player m_PlayerClass; // src/Logic/Player
		Object m_object; //src/Logic/Object

  void foo();



};

#endif
