#include "PlayerCircle.h"

PlayerCircle::PlayerCircle()
    :Player()
{
    color = sf::Color(255,0,0);
    player = std::make_shared<sf::CircleShape>(size/2);
    player->setFillColor(color);
    player->move(63,63);
}

PlayerCircle::~PlayerCircle()
{

}

void PlayerCircle::Move()
{
    if(use_joystic)
    {
        JoystickMove();
    }
    else
    {
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            speed = 0;
        }
        else
        {
            speed = max_speed * (1 - smooth) + speed * smooth;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player->move(0, -speed);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player->move(0, speed);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player->move(-speed, 0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player->move(speed, 0);
        }
    }
}
