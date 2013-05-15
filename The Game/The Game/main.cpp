#include <Windows.h>
#include "InGameContext.h"

#define WIDTH 800
#define HEIGHT 600

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "The Game");

	BaseContext* currentContext;

	RenderTexture mainGameTexture;
	if(!mainGameTexture.create(WIDTH, HEIGHT))
	{
		return 0;
	}

	InGameContext mainGameContext(&mainGameTexture);

	currentContext = &mainGameContext;

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
		Sprite sprite(mainGameTexture.getTexture());
		window.draw(sprite);
		window.display();
    }

    return 0;
}
