#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main() {
    // 1. Get Desktop Resolution
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Pong", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    const float W = (float)desktop.width;
    const float H = (float)desktop.height;

    const float PADDLE_SPEED = H * 0.8f;
    float ballSpeedX = W * 0.3f;
    float ballSpeedY = H * 0.3f;

    // --- Font & Text Setup (Fedora Specific Path) ---
    sf::Font font;
    // Common Fedora path for Liberation Sans
    if (!font.loadFromFile("/usr/share/fonts/open-sans/OpenSans-Bold.ttf")) {
        // Fallback for DejaVu Sans
        if (!font.loadFromFile("")) {
            std::cout << "Font not found! Check /usr/share/fonts/ for available .ttf files.\n";
        }
    }

    int score1 = 0;
    int score2 = 0;

    sf::Text scoreCard;
    scoreCard.setFont(font);
    scoreCard.setCharacterSize(static_cast<unsigned int>(H * 0.2f)); // Huge score!
    scoreCard.setFillColor(sf::Color(255, 255, 255, 50)); // Very subtle/transparent
    scoreCard.setString("0  0");

    // Position logic
    auto centerText = [&]() {
        sf::FloatRect tr = scoreCard.getLocalBounds();
        scoreCard.setOrigin(tr.left + tr.width / 2.0f, 0);
        scoreCard.setPosition(W / 2.0f, H * 0.1f);
    };
    centerText();

    // --- Ball Setup ---
    sf::CircleShape ball(15.0f);
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(15.0f, 15.0f);
    ball.setPosition(W / 2.0f, H / 2.0f);

    // --- Paddles ---
    sf::RectangleShape player1(sf::Vector2f(25.0f, H * 0.18f));
    player1.setOrigin(0, (H * 0.18f) / 2.0f);
    player1.setPosition(W * 0.03f, H / 2.0f);

    sf::RectangleShape player2(sf::Vector2f(25.0f, H * 0.18f));
    player2.setOrigin(25.0f, (H * 0.18f) / 2.0f);
    player2.setPosition(W * 0.97f, H / 2.0f);

    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
               (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        // --- Paddle Controls ---
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player1.getPosition().y - player1.getOrigin().y > 0)
            player1.move(0, -PADDLE_SPEED * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player1.getPosition().y + player1.getOrigin().y < H)
            player1.move(0, PADDLE_SPEED * dt);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player2.getPosition().y - player2.getOrigin().y > 0)
            player2.move(0, -PADDLE_SPEED * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player2.getPosition().y + player2.getOrigin().y < H)
            player2.move(0, PADDLE_SPEED * dt);

        // --- Ball Physics ---
        ball.move(ballSpeedX * dt, ballSpeedY * dt);

        if (ball.getPosition().y <= 15.0f || ball.getPosition().y >= H - 15.0f) {
            ballSpeedY *= -1.0f;
        }

        if (ball.getGlobalBounds().intersects(player1.getGlobalBounds()) ||
            ball.getGlobalBounds().intersects(player2.getGlobalBounds())) {
            ballSpeedX *= -1.08f; // Reverse and increase speed slightly
        }

        // --- Scoring ---
        if (ball.getPosition().x < 0 || ball.getPosition().x > W) {
            if (ball.getPosition().x < 0) score2++; else score1++;

            ball.setPosition(W / 2.0f, H / 2.0f);
            ballSpeedX = (ballSpeedX > 0 ? -(W * 0.3f) : (W * 0.3f));
            scoreCard.setString(std::to_string(score1) + "  " + std::to_string(score2));
            centerText();
        }

        // --- Rendering ---
        window.clear(sf::Color::Black);
        window.draw(scoreCard); // Background
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.display();
    }

    return 0;
}
