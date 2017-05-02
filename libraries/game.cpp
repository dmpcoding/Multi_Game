#include "game.h"

void P_Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (sf::RectangleShape x : game_map) {
        target.draw(x, states);
    }

    target.draw(meta, states);
    target.draw(player, states);
    sf::Time time = clock.getElapsedTime();
    int m = time.asSeconds() / 60;
    int s = int(time.asSeconds()) % 60;
    sf::Text textTime(std::to_string(m) + ":" + std::to_string(s), *font, 16);
    textTime.setPosition(game_window->getSize().x - textTime.getGlobalBounds().width, 0);
    target.draw(textTime, states);
}

P_Game::P_Game() {
    player.setRadius(10);
    player.setFillColor(sf::Color::Red);
    player.setPosition(0, 15);
    meta_texture.loadFromFile("x.png");
    meta.setTexture(meta_texture);
}

void P_Game::resetClock() { 
    clock.restart();
}

void P_Game::refresh() {
    sf::CircleShape test = player;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        test.move(0.1, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        test.move(0, 0.1);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        test.move(-0.1, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        test.move(0, -0.1);
    }

    bool off_the_screen =
        (test.getPosition().x > 0 && test.getPosition().y > 0 &&
        test.getPosition().x <
            game_window->getSize().x - test.getGlobalBounds().width &&
        test.getPosition().y <
            game_window->getSize().y - test.getGlobalBounds().height);

    if (off_the_screen) {
        bool collision = false;

        for (std::size_t i = 0; i < game_map.size() && !collision; i++)
            collision = game_map[i].getGlobalBounds().intersects(test.getGlobalBounds());

        if (collision == false) {
            player = test;
        }
    }
}

void P_Game::setUpMap(int i, int x, int y, int w, int h, int r) {
    game_map[i].setPosition(x, y);
    game_map[i].setSize(sf::Vector2f(w, h));
    game_map[i].setRotation(r);
    game_map[i].setFillColor(sf::Color::White);
}

void P_Game::addMapElement(int x, int y, int w, int h, int r) {
    sf::RectangleShape a;
    game_map.push_back(a);
    setUpMap(game_map.size() - 1, x, y, w, h, r);
}

void P_Game::addMapElement(map_element_value values) {
    addMapElement(values.x, values.y, values.w, values.h, values.r);
}

void P_Game::setUpMapEnd(int x, int y) {
    meta.setPosition(x, y);
}
