#include "Map_draw.h"
#include "fileio.h"



int main()
{

    Fio w;
    w.create("spata");

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(230, 280), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;

	// Start the game loop

    engine::Map stage;

    while (app.isOpen())
    {
        stage.drawHorizontalLine(app,1,2,10);
        stage.drawVerticalLine(app, 1,3 ,10);
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }


        // Clear screen
        //app.clear();

        // Draw the sprite
//        app.draw(sprite);

        // Update the window
       app.display();
    }

    return EXIT_SUCCESS;
}
