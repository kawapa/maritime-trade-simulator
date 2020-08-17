#include "Map.hpp"

#include <algorithm>
#include <iostream>
#include <random>

#include "Coordinates.hpp"
#include "Island.hpp"

constexpr int minCoordinate = 0;
constexpr int maxCoordinate = 10;
constexpr int numberOfIslands = 10;

Map::Map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minCoordinate, maxCoordinate);

    islands_.reserve(numberOfIslands);
    bool coordinatesAreFree;

    while (islands_.size() != numberOfIslands) {
        auto tempX = static_cast<size_t>(distrib(gen));
        auto tempY = static_cast<size_t>(distrib(gen));

        coordinatesAreFree = std::none_of(begin(islands_), end(islands_), [tempX, tempY](const std::shared_ptr<Island>& island) {
            return !(island.get()->getPosition() == Coordinates(tempX, tempY));
        });

        if (coordinatesAreFree) {
            islands_.push_back(std::make_shared<Island>(Island(tempX, tempY)));
        }
    }
}

Map::~Map() = default;

Island* Map::getIsland(const Coordinates& coordinate) {
    auto search = std::find_if(begin(islands_), end(islands_), [&coordinate](const std::shared_ptr<Island>& island){
        return island->getPosition() == coordinate;
    });
    if (search != end(islands_)) {
        return search->get();
    }
    return nullptr;
}

Island* Map::getCurrentPosition() const {
    return currentPosition_;
}

void Map::showIslands() {
    
}