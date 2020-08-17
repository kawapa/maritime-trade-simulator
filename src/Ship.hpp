#pragma once

#include <iterator>
#include <memory>
#include <string>
#include <vector>

#include "Cargo.hpp"

class Ship {
public:
    Ship();
    Ship(const std::string& name, size_t speed, size_t crew, size_t maxCrew, size_t capacity);
    ~Ship();

    std::string getName() const;
    size_t getSpeed() const;
    size_t getCrew() const;
    size_t getMaxCrew() const;
    size_t getCapacity() const;

    void printCargo() const;

    size_t getCargoWeight() const;
    void load(std::shared_ptr<Cargo> cargo);
    void unload(std::shared_ptr<Cargo> cargo, size_t amount);

private:
    std::vector<std::shared_ptr<Cargo>>::iterator returnCargoIterator(std::shared_ptr<Cargo> cargo);

    std::string name_;
    size_t speed_;
    size_t crew_;
    size_t maxCrew_;
    size_t capacity_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
