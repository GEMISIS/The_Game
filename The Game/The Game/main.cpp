#include <Windows.h>
#include "CharacterClass.h"

//############################################################
//############################################################
//------------------------------------------------------------
// change these variables to change how many sprites are drawn.
//------------------------------------------------------------
#define WIDTH 640
#define HEIGHT 480
#define SPRITE_WIDTH 64
#define SPRITE_HEIGHT 64
//------------------------------------------------------------
//############################################################
//############################################################

#define TOTAL_SPRITES ((WIDTH / SPRITE_WIDTH) * (HEIGHT / SPRITE_HEIGHT))

//###################################################################
//###################################################################
//-------------------------------------------------------------------
// Quick test of everything.  fills the screen with the test sprite.
//-------------------------------------------------------------------
//###################################################################
//###################################################################
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");

	Character w[TOTAL_SPRITES];

	for(int y = 0;y < HEIGHT / SPRITE_WIDTH;y += 1)
	{
		for(int x = 0;x < WIDTH / SPRITE_HEIGHT;x += 1)
		{
			int i = x + y * (WIDTH / SPRITE_WIDTH);
			w[i].setImage("test.png");
			w[i].setPosition((float)x * SPRITE_WIDTH, (float)y * SPRITE_HEIGHT);
		}
	}

    while (window.isOpen())
    {
		Character b("test.png");
		b.setPosition(WIDTH / 2, HEIGHT / 2);
		b.setColor(sf::Color::Red);

		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		
		for(int y = 0;y < HEIGHT / SPRITE_WIDTH;y += 1)
		{
			for(int x = 0;x < WIDTH / SPRITE_HEIGHT;x += 1)
			{
				int i = x + y * (WIDTH / SPRITE_WIDTH);
				window.draw(w[i]);
			}

			window.draw(b);
		}

        window.display();
    }

    return 0;
}
