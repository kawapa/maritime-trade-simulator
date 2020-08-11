#pragma once

#include <iterator>
#include <memory>
#include <string>
#include <vector>

#include "Cargo.hpp"

class Ship {
public:
    Ship() = default;
    Ship(const std::string& name, size_t speed, size_t crew, size_t maxCrew, size_t capacity);
    ~Ship();

    std::string getName() const;
    size_t getSpeed() const;
    size_t getMaxCrew() const;
    size_t getCapacity() const;
    size_t getCrew() const;
    void setName(const std::string& name);
    Cargo* getCargo(std::string name) const;
    size_t getCargoWeight() const;
    std::vector<std::shared_ptr<Cargo>>::iterator returnCargoIterator(std::shared_ptr<Cargo> cargo);
    void load(std::shared_ptr<Cargo> cargo);
    void unload(std::shared_ptr<Cargo> cargo, size_t amount);
    void removeCargoFromShip(Cargo* cargo);

    Ship& operator+=(const size_t crew);
    Ship& operator-=(const size_t crew);

private:
    std::string name_;
    size_t speed_;
    size_t crew_;
    size_t maxCrew_;
    size_t capacity_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
