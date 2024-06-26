#include "ball.h"

// Initialize static data
sf::Texture ball::texture;

ball::ball(float x, float y): moving_entity()
{
    // Load the texture
    texture.loadFromFile("ball.png");
    sprite.setTexture(texture);

    // Set the initial position and velocity of the ball
    // Use (x, y) for the initial position of the ball
    sprite.setPosition(x, y);
    velocity = {constants::ball_speed, constants::ball_speed};
}

// Compute the ball's new position
void ball::update()
{
    // Move the position of the ball
    sprite.move(velocity);

    // Check if the ball has moved off the left hand side of the window
    // If so, we change the sign of the x-component of the velocity
    // This will make it move at the same speed, but to the right
    // The ball will appear to bounce back into the window
    if (x() < 0)
        velocity.x = -velocity.x;
    // And similarly for the right hand side of the screen
    if (x() > constants::window_width)
        velocity.x = -velocity.x;
    
    // We can also do this for the top and bottom of the screen
    if (y() < 0)
        velocity.y = -velocity.y;
    // And similarly for the right hand side of the screen
    if (y() > constants::window_height)
        velocity.y = -velocity.y;
}

void ball::draw(sf::RenderWindow& window)
{
    // Ask the window to draw the sprite for us
    window.draw(sprite);
}