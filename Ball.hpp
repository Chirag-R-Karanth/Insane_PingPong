#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float baseSpeedX;

    Ball(float screenW, float screenH) {
        baseSpeedX = screenW * 0.3f;
        shape.setRadius(15.0f);
        shape.setFillColor(sf::Color::White);
        shape.setOrigin(15.0f, 15.0f);
        reset(screenW, screenH);
    }

    void update(float dt) { shape.move(velocity * dt); }

    void reset(float screenW, float screenH) {
        shape.setPosition(screenW / 2.0f, screenH / 2.0f);
        velocity = sf::Vector2f((velocity.x > 0 ? -baseSpeedX : baseSpeedX), screenH * 0.3f);
    }

    void bounceY() { velocity.y *= -1.0f; }
    void bounceX() { velocity.x *= -1.1f; }
};

#endif
