#pragma once

#include <memory>

#include "Map.hpp"
#include "Player.hpp"
#include "Store.hpp"

class Game {
public:
    Game();
    Game(size_t start_money, size_t game_days, size_t final_goal);
    ~Game() = default;

    size_t getStartMoney() const;
    size_t getGameDays() const;
    size_t getFinalGoal() const;

    bool continueToPlay();
    void showGameStatus();
    void actionMenu();
    void userChooses();
    void buy();
    void sell();
    void sail();
    void startGame();

    Store* getStore();
    Player* getPlayer();

private:
    std::unique_ptr<Store> store_;
    std::unique_ptr<Player> player_;
    std::unique_ptr<Map> map_;

    size_t time_ = 0;
    size_t start_money_;
    size_t game_days_;
    size_t final_goal_;
};
