#include "Coordinates.hpp"

#include <cstddef>
#include <cmath>

Coordinates::Coordinates(size_t x, size_t y)
    : positionX_(x),
      positionY_(y) { }

Coordinates::~Coordinates() = default;

size_t Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    int xDiff = lhs.positionX_ - rhs.positionX_;
    int yDiff = lhs.positionY_ - rhs.positionY_;
    return std::sqrt(xDiff * xDiff + yDiff * yDiff);
}

bool Coordinates::operator==(const Coordinates& coordinates) const {
    return ((positionX_ == coordinates.positionX_) &&
           (positionY_ == coordinates.positionY_));
}
