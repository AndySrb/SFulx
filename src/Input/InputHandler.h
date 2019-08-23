#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

class InputHandler
{
	private:
			InputHandler(const InputHandler &obj);
			InputHandler(InputHandler&& obj);

			static InputHandler *s_InputHandler;
			std::map<unsigned int,bool> m_KeyboardInput;
	public:

			InputHandler();
			void UpdateKey(const sf::Keyboard::Key &key,const bool &isPressed);
			bool isKeyboardKeyPressed(const sf::Keyboard::Key &key);


};

#endif
