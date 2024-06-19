#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

// Abstract class to represent any graphical entity on the screen
class entity
{
protected:
    sf::Sprite sprite;
public:
    // Pure virtual functions
    // Concrete praphical entities must implement these functions
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    // Helper function to get the bounding box of a sprite
    sf::FloatRect get_bounding_box() const noexcept;

    // Helper function to get the center of a sprite
    sf::Vector2f get_center() const noexcept;

    // Helper functions to get the position of the sprite
    float x() const noexcept;
    float y() const noexcept;

    // Virtual destructor
    virtual ~entity() {}
};

// Abstract base class to represent graphical entities which can move around the screen
class moving_entity: public entity
{
protected:
    // SMFL vector to store the object's velocity
    // This is the distance the ball moves between screen updates
    sf::Vector2f velocity;
public:
    // Helper functions

    // Pure virtual functions inherited from parent class
    // virtual void update() = 0;
    // virtual void draw(sf::RenderWindow& window) = 0;
    // etc
};

#endif // ENTITY_H