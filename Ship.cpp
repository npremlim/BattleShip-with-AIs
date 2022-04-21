//
// Created by csien on 5/17/2021.
//

#include "Ship.h"

BattleShip::Ship::Ship(char shipType, int length) : identifier(shipType), size(length) {}

char BattleShip::Ship::getType() const {
    return identifier;
}

int BattleShip::Ship::getSize() const {
    return size;
}
