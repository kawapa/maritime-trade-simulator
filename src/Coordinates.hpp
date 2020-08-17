#pragma once

#include <cstddef>

class Coordinates {
public:
    Coordinates(int x, int y);
    ~Coordinates();

    void printCoordinates() const;
    
    static int distance(const Coordinates& lhs, const Coordinates& rhs);
    bool operator==(const Coordinates& coordinates) const;

private:
    int positionX_;
    int positionY_;
};
