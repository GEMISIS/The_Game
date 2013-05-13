#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "WorldClass.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	World w[5];

	for(int i = 0;i < 3;i += 1)
	{
		w[i].setTexture("test.png");
		w[i].setPosition(((float)i) * 64.0f, 0.0f);
		//w[i].setPosition(((float)i) * 0.0f, 0.0f);
	}

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		
		for(int i = 0;i < 5;i += 1)
		{
			w[i].Update(window);
		}
        
        window.display();
    }

    return 0;
}
