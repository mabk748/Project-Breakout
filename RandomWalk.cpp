#include <SFML/Graphics.hpp>
#include <string>
#include <random>
#include "constants.h"

using namespace std;
using namespace std::literals;

// Class to represent the creature moving around the screen
class creature
{
    // Static random number engine and Bernoulli distribution objects
    static mt19937 mt;
    static bernoulli_distribution bd;

    // Define some properties of the creature
    // SMFL uses floats internally
    float vx{4.0f};
    float vy{4.0f};
    sf::Vector2f velocity;

    // We use the SFML CircleShape
    sf::CircleShape circle;
public:
    // Interface of the class

    // Constructor
    // Arguments are the initial coordinates of the center of the ball
    // SFML uses the computer graphics convention
    // (0, 0) is the top left corner of the screen
    // x increases to the right
    // y increases downwards
    creature(float x, float y)
    {
        // Set the initial position and velocity
        // Use (x, y) for the initial position
        velocity = {vx, vy};
        circle.setPosition(x, y);

        // Set the graphical properties
        circle.setRadius(5.0f);
        circle.setFillColor(sf::Color::Red);
    }

    void draw(sf::RenderWindow& window)
    {
        // Ask the window to draw the shape for us
        window.draw(circle);
    }

    // Compute the creature's new position
    void update()
    {
        // Change the direction of movement at random
        vx = bd(mt) ? vx : -vx;
        vy = bd(mt) ? vy : -vy;

        // Move the vreature to it's new position
        circle.move({vx, vy});
    }
};

mt19937 creature::mt;
bernoulli_distribution creature::bd;

// The main funtion for the program
int main()
{
    // Create a creature object in the middle of the screen
    creature the_creature(constants::window_width/2.0, constants::window_height/2.0);

    // Create the games's window using an object of class RenderWindow
    // The constructor takes an SFML 2D vector with the window dimensions
    // and an std::string with the window title
    // The SFML code is in the sf namespace
    sf::RenderWindow game_window{{constants::window_width, constants::window_height}, "Sinple Breakout Game Version 1"s};

    // Limit the framerate
    // This allows other processes to run and reduce power consumtion
    game_window.setFramerateLimit(60);  // Max rate is 60 fps

    // Game loop
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
        the_creature.update();

        // Display the updated graphics
        the_creature.draw(game_window);
        game_window.display();

    }
}