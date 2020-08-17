#include "Game.hpp"

#include <iostream>

#include "Alcohol.hpp"
#include "Fruit.hpp"

Game::Game() : Game(1000, 100, 2000) {}

Game::Game(size_t start_money, size_t game_days, size_t final_goal)
    : start_money_(start_money),
      game_days_(game_days),
      final_goal_(final_goal)
{
    store_ = std::make_unique<Store>();
    player_ = std::make_unique<Player>(std::make_shared<Ship>(), start_money);
    map_ = std::make_unique<Map>();
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

bool Game::continueToPlay() {
    return (start_money_ < final_goal_) && (time_ <= game_days_);
}

void Game::startGame() {
    while (continueToPlay()) {
        showGameStatus();
        actionMenu();
    }
}

void Game::showGameStatus() {
    std::cout << std::endl;
    std::cout << "|---------------------------------|\n";
    std::cout << "| Money: " << player_->getMoney() << " (" << final_goal_ << ") "
              << "Day: " << time_ << " (" << game_days_ << ") | \n";
    std::cout << "|---------------------------------|\n";
}

void Game::actionMenu() {
    std::cout << std::endl;
    std::cout << "USER MENU:\n";
    std::cout << "* Press '0' to SHOW your cargo\n";
    std::cout << "* Press '1' to BUY something at the store\n";
    std::cout << "* Press '2' to SELL something from your cargo\n";
    std::cout << "* Press '3' to SAIL to another island\n";
    std::cout << std::endl;
    
    int userChoice;
    do {
        std::cout << "Your choice: ";
        std::cin >> userChoice;
    } while (userChoice > 3);
   
    switch (userChoice) {
        case 0:
            player_->getShip()->printCargo();
            break;
        case 1:
            buy();
            break;
        case 2:
            sell();
            break;
        case 3:
            sail();
            break;        
    }
}

void Game::userChooses() {

}

void Game::buy() {
    std::cout << *store_;
    std::cout << "You'd like to buy item: ";
    int userChoice;
    std::cin >> userChoice;
    std::cout << "\n What amount? ";
    int userAmount;
    std::cin >> userAmount;
    Store::Response response = store_->sell(userChoice, userAmount, player_.get());

    switch (response) {
        case Store::Response::lack_of_money:
            std::cout << "Error! You don't have sufficient funds!\n";
            break;
        case Store::Response::lack_of_cargo:
            std::cout << "Error! You're trying to buy more than we have on stock!\n";
            break;
        case Store::Response::lack_of_space:
            std::cout << "Error! You don't have enough space on your ship!\n";
            break;
        default:
            std::cout << "The transaction ended successfully! Cheers!\n";
            break;
    }
}

void Game::sell() {

}

void Game::sail() {

}


Store* Game::getStore() { return store_.get(); }
Player* Game::getPlayer() { return player_.get(); }