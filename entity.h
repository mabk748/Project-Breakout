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

    // Virtual destructor
    virtual ~entity() {}
};

#endif // ENTITY_H