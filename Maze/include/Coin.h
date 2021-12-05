#ifndef __COIN_H__
#define __COIN_H__

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Collision.h"

class Coin
{
private:
    sf::RectangleShape coin;

public:
    /** Default constructor */
    Coin();

    /** Default destructor */
    ~Coin();

    /** \brief Draw coin
     * \param window - Window to render coin
     */
    void Draw(sf::RenderWindow& window);

    /** \brief Improve coin position
     * \param x - New horizontal position
     * \param y - New vertical position
     */
    void SetPosition(float x, float y);

    /** \brief Pick up coin if player is near to coin
     * \param player - The player for whom the attempt to pick up the coin will be made
     * \return if selected player is close enought to pick up coin, return true and remove coin from map
     */
    bool PickUp(Player& player);
};

#endif // __COIN_H__