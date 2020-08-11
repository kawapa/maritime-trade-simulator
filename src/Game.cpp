#include "Game.hpp"

#include "Alcohol.hpp"
#include "Fruit.hpp"

Game::Game(size_t start_money, size_t game_days, size_t final_goal)
    : start_money_(start_money),
      game_days_(game_days),
      final_goal_(final_goal) {
    store_ = std::make_unique<Store>();
    auto ship = std::make_shared<Ship>("Eagle", 5, 10, 60, 200);
    player_ = std::make_unique<Player>(ship, start_money);
}

size_t Game::getStartMoney() const {
    return start_money_;
}
size_t Game::getGameDays() const {
    return game_days_;
}
size_t Game::getFinalGoal() const {
    return final_goal_;
}

void Game::startGame() {
}
