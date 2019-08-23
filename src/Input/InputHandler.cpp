#include "InputHandler.h"

InputHandler* InputHandler::s_InputHandler = nullptr;

InputHandler::InputHandler()
{
	if (s_InputHandler == nullptr)
		s_InputHandler =this;
}

void InputHandler::UpdateKey(const sf::Keyboard::Key &key,const bool &isPressed)
{
	s_InputHandler->m_KeyboardInput[key] = isPressed;
}

bool InputHandler::isKeyboardKeyPressed(const sf::Keyboard::Key &key)
{
	return s_InputHandler->m_KeyboardInput[key];
}
