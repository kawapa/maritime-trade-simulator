#pragma once

#include "Cargo.hpp"
#include "Player.hpp"

class Store {
public:  
    enum class Response {
        done,
        lack_of_money,
        lack_of_cargo,
        lack_of_space
    };

    Store();
    ~Store();

    Response buy(Cargo* cargo, size_t amount, Player* player);
    // Response sell(Cargo* cargo, size_t amount, Player* player);
    void nextDay();
    void generateNewStock();

private:

};
