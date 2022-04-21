//
// Created by csien on 5/17/2021.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <map>
#include <string>
#include "Board.h"
#include "Ship.h"

namespace BattleShip {
    class Player {
        public:
            Player(std::string playerName, int boardHeight, int boardWidth);
            virtual ~Player();
            //Player() = delete;
            int boardHeight;
            int boardWidth;
            std::string getName() const;
            Board& getPlacementBoard();
            std::map<char, int>& getStoreShips();
            void placeShip(BattleShip::Ship ship, char orientation, int row, int col);
            virtual void attack(Board& opponentBoard, const std::string& opponentName, std::map<char,int>& opponentShips);
            void addShip(BattleShip::Ship ship);
            void displayBoards();
            void updateFiringBoard(char symbol, int row, int col);
            std::string name;
            Board placementBoard;
        private:

            void getTarget(int& row, int& col) const;




            Board firingBoard;
            std::map<char,int> storeShips;
    };

}

#endif //BATTLESHIP_PLAYER_H
