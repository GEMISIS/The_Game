#include <Windows.h>
#include "InGameContext.h"

#define WIDTH 800
#define HEIGHT 600

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "The Game");
	BaseContext* currentContext = new InGameContext(window);
	sf::Clock deltaClock;

    while (window.isOpen())
    {
		sf::Time delta = deltaClock.restart();
		sf::Event event;
        while (window.pollEvent(event))
        {
			currentContext->handleEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

		currentContext->updateLogic(delta);

        window.clear();
		currentContext->draw();
		window.display();
    }

	delete currentContext;
    return 0;
}
