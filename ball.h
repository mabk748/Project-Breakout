#ifndef BALL_H 
#define BALL_H

#include "constants.h"
#include "entity.h"

// Class to represent bouncing ball
// Inherits from moving_entity
class ball: public moving_entity
{
    // Private data members
    static sf::Texture texture;

public:
    // Interface of the class

    // Constructor
    // Arguments are the initial coordinates of the center of the ball
    // SMFL uses the computer graphics convention
    // (0, 0) is the top left corner of the screen
    // x increases to the right
    // y increases downwards
    ball(float x, float y);

    // Implement the pure virtual functions
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif //BALL_H