#include "Coordinates.hpp"

#include <iostream>
#include <cstddef>
#include <cmath>

Coordinates::Coordinates(int x, int y)
    : positionX_(x),
      positionY_(y) { }

Coordinates::~Coordinates() = default;

void Coordinates::printCoordinates() const {
    std::cout << "X: " << positionX_ << ", Y: " << positionY_ << std::endl;
}

int Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs) {
    int xDiff = std::abs(lhs.positionX_ - rhs.positionX_);
    int yDiff = std::abs(lhs.positionY_ - rhs.positionY_);
    return xDiff + yDiff;
}

bool Coordinates::operator==(const Coordinates& coordinates) const {
    return ((positionX_ == coordinates.positionX_) &&
           (positionY_ == coordinates.positionY_));
}
