#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <SFML/Graphics.hpp>
#include <string>

class ScoreBoard {
public:
    sf::Text text;
    int p1 = 0, p2 = 0;
    float screenW;

    ScoreBoard(sf::Font& font, float w, float h) : screenW(w) {
        text.setFont(font);
        text.setCharacterSize(static_cast<unsigned int>(h * 0.2f));
        text.setFillColor(sf::Color(255, 255, 255, 40));
        updateDisplay();
    }

    void addPoint(int player) {
        if (player == 1) p1++; else p2++;
        updateDisplay();
    }

    void updateDisplay() {
        text.setString(std::to_string(p1) + "  " + std::to_string(p2));
        sf::FloatRect b = text.getLocalBounds();
        text.setOrigin(b.left + b.width / 2.0f, 0);
        text.setPosition(screenW / 2.0f, 50.0f);
    }
};

#endif
