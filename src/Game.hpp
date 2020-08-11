#pragma once

#include <memory>

#include "Map.hpp"
#include "Player.hpp"
#include "Store.hpp"

class Game {
public:
    Game(size_t start_money, size_t game_days, size_t final_goal);
    ~Game() = default;
    size_t getStartMoney() const;
    size_t getGameDays() const;
    size_t getFinalGoal() const;

    void startGame();

private:
    std::unique_ptr<Store> store_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Map> map_;

    size_t start_money_;
    size_t game_days_;
    size_t final_goal_;
};
