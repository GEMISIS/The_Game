#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "WorldClass.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	World w("test.png");
	World w1("test.png");
	World w2("test.png");
	World w3("test.png");

    while (window.isOpen())
    {
		World w4("test.png");
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		
		w.Update(window);
		w1.Update(window);
		w2.Update(window);
		w3.Update(window);
		w4.Update(window);
        
        window.display();
    }

    return 0;
}
