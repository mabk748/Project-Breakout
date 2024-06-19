#include <SFML/Graphics.hpp>

#include <string>

#include "constants.h"
#include "ball.h"
#include "background.h"

using namespace std::literals;

// The main function of the program
int main()
{
    // Create the background object
    background the_background(0.0f, 0.0f);

    // Create the ball object in the middle of the screen
    ball the_ball(constants::window_width/2.0f, constants::window_height/2.0f);
    // Create the games's window using an object of class RenderWindow
    // The constructor takes an SFML 2D vector with the window dimensions
    // and an std::string with the window title
    // The SFML code is in the sf namespace
    sf::RenderWindow game_window{{constants::window_width, constants::window_height}, "Sinple Breakout Game Version 2"s};

    // Limit the framerate
    // This allows other processes to run and reduce power consumtion
    game_window.setFramerateLimit(60);  // Max rate is 60 fps

    // Game loop
    // Clear the screen
    // Check for user input
    // Calculate the updated graphics
    // Display the updated graphics
    while (game_window.isOpen())
    {
        // Clear the screen
        game_window.clear(sf::Color::Black);

        // Check for any events since the last loop iteration
        sf::Event event;

        // If the user pressed "Escape", or clicked on "close",
        // This will terminate the program
        while (game_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game_window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            game_window.close();
        
        // Calculate the updated graphics
        the_background.update();
        the_ball.update();

        // Display the updated graphics
        the_background.draw(game_window);
        the_ball.draw(game_window);
        game_window.display();

    }
}
