#pragma once

#include <string>
#include <iterator>
#include <memory>
#include <vector>

#include "Cargo.hpp"

class Ship {
public:
    Ship();
    Ship(int id, const std::string& name, size_t speed, size_t maxCrew, size_t capacity);
    Ship(int id, size_t speed, size_t maxCrew);
    ~Ship();

    size_t getId() const;
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
    void nextDay();

    Ship& operator+=(const size_t crew);
    Ship& operator-=(const size_t crew);

private:
    int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_ = 0;
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
