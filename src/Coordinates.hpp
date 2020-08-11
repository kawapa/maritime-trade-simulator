#pragma once

#include <cstddef>

class Coordinates {
public:
    Coordinates(size_t x, size_t y);
    ~Coordinates();

    static size_t distance(const Coordinates& lhs, const Coordinates& rhs);

    bool operator==(const Coordinates& coordinates) const;

private:
    size_t positionX_;
    size_t positionY_;
};
