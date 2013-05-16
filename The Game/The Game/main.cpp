#include <Windows.h>
#include "InGameContext.h"

#define WIDTH 800
#define HEIGHT 600

#if _DEBUG
int main()
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#endif
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "The Game");
	InGameContext* game = new InGameContext(window);
	BaseContext::currentContext = game;
	sf::Clock deltaClock;

    while (window.isOpen())
    {
		sf::Time delta = deltaClock.restart();
		sf::Event event;
        while (window.pollEvent(event))
        {
			BaseContext::currentContext->handleEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

		BaseContext::currentContext->updateLogic(delta);

        window.clear();
		BaseContext::currentContext->draw();
		window.display();
    }

	delete game;
    return 0;
}
