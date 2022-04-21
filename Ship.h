//
// Created by csien on 5/17/2021.
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

#include <string>

namespace BattleShip {
    class Ship {
        public:
            Ship(char shipType, int length);
            Ship() = delete;

            char getType() const;
            int getSize() const;

        private:
            char identifier;
            int size;
    };
}

#endif //BATTLESHIP_SHIP_H
