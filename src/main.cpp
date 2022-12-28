#include <iostream>
#include "Window/Game.h"

int main()
{
	Game game;
	std::cout << "Window size: X:" <<  game.GetWindow()->GetWindowSize().x  << " Y:" << game.GetWindow()->GetWindowSize().y << std::endl;

while(!game.GetWindow()->IsDone()){
// Game loop.
	game.Update();
	game.Render();




}

	int *ptr = new int[10];

return 0;
}

