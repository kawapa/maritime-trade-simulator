#pragma once

#include <memory>
#include <vector>

#include "Coordinates.hpp"
#include "Island.hpp"

class Map {
public:
    Map();

    Island* getIsland(const Coordinates& coordinate);
    Island* getCurrentPosition() const;

private:
    std::vector<std::shared_ptr<Island>> islands_;
    Island* currentPosition_;
};
