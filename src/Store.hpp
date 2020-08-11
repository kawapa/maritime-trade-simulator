#pragma once

#include <iostream>
#include <vector>

#include "Cargo.hpp"
#include "Player.hpp"

class Store {
public:
    Store();
    ~Store();

    enum class Response {
        done,
        lack_of_money,
        lack_of_cargo,
        lack_of_space
    };

    Response buy(Cargo* cargo, size_t amount, Player* player);
    Response sell(Cargo* cargo, size_t amount, Player* player);
    void generateNewStock();
    void showAssortment();

    friend std::ostream& operator<<(std::ostream& os, const Store& obj);

private:
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
