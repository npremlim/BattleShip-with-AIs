//
// Created by csien on 5/16/2021.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <vector>

namespace BattleShip {
    class Board {
        public:
            Board(int boardHeight, int boardWidth);

            void printBoard() const;
            void updateElement(char element, int row, int col);
            char getElement(int row, int col);
            bool validRowAndCol(char orientation, int row, int col, int length) const;
            bool availablePlacement(char orientation, int row, int col, int length) const;
            int height, width;
        private:

            std::vector<std::vector<char>> board;
    };
}

#endif //BATTLESHIP_BOARD_H
