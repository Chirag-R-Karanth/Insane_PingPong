#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle {
public:
    sf::RectangleShape shape;
    float speed;

    Paddle(float x, float screenH, bool isRight) {
        float height = screenH * 0.18f;
        shape.setSize(sf::Vector2f(25.0f, height));
        shape.setFillColor(sf::Color::White);
        shape.setOrigin(isRight ? 25.0f : 0, height / 2.0f);
        shape.setPosition(x, screenH / 2.0f);
        speed = screenH * 0.85f;
    }

    void move(float direction, float dt, float screenH) {
        shape.move(0, direction * speed * dt);
        float halfH = shape.getSize().y / 2.0f;
        if (shape.getPosition().y < halfH) shape.setPosition(shape.getPosition().x, halfH);
        if (shape.getPosition().y > screenH - halfH) shape.setPosition(shape.getPosition().x, screenH - halfH);
    }
};

#endif
