#include "Island.hpp"

#include "Coordinates.hpp"

Island::Island(size_t x, size_t y)
    : position_(Coordinates(x, y)) {}

Island::~Island() = default;

Coordinates Island::getPosition() const {
    return position_;
}
