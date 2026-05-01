#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "ScoreBoard.hpp"

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Modular Pong", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    float W = (float)desktop.width;
    float H = (float)desktop.height;

    sf::Font font;
    font.loadFromFile("/usr/share/fonts/open-sans/OpenSans-Bold.ttf");

    Ball ball(W, H);
    Paddle p1(W * 0.03f, H, false);
    Paddle p2(W * 0.97f, H, true);
    ScoreBoard score(font, W, H);
    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        // Input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) p1.move(-1.f, dt, H);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) p1.move(1.f, dt, H);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) p2.move(-1.f, dt, H);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) p2.move(1.f, dt, H);

        // Logic
        ball.update(dt);
        if (ball.shape.getPosition().y <= 15.f || ball.shape.getPosition().y >= H - 15.f) ball.bounceY();
        if (ball.shape.getGlobalBounds().intersects(p1.shape.getGlobalBounds()) ||
            ball.shape.getGlobalBounds().intersects(p2.shape.getGlobalBounds())) ball.bounceX();

        if (ball.shape.getPosition().x < 0) { score.addPoint(2); ball.reset(W, H); }
        if (ball.shape.getPosition().x > W) { score.addPoint(1); ball.reset(W, H); }

        // Render
        window.clear(sf::Color::Black);
        window.draw(score.text);
        window.draw(p1.shape);
        window.draw(p2.shape);
        window.draw(ball.shape);
        window.display();
    }
    return 0;
}
