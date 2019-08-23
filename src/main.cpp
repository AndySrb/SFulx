#include <iostream>
#include "Window/Game.h"

int main()
{
	Game game;
	std::cout << "Window size: X:" <<  game.GetWindow()->GetWindowSize().x  << " Y:" << game.GetWindow()->GetWindowSize().y << std::endl;
	sf::Event event;

while(!game.GetWindow()->IsDone()){
// Game loop.
	game.Update();
	game.Render();
}

return 0;
}

