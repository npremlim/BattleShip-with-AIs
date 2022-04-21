//
// Created by csien on 5/16/2021.
//

#include <iostream>
#include "Board.h"

BattleShip::Board::Board(int boardHeight, int boardWidth) : height(boardHeight), width(boardWidth), board(boardHeight, std::vector<char>(boardWidth, '*')) {}

void BattleShip::Board::printBoard() const {
    // function to print board
    std::cout << "  ";
    for (int i = 0; i < width; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < height; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < width; ++j) {
            std::cout << board.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

void BattleShip::Board::updateElement(char element, int row, int col) {
    // update element at coordinate row,col
    board.at(row).at(col) = element;
}

char BattleShip::Board::getElement(int row, int col) {
    // get element at coordinate row,col
    return board.at(row).at(col);
}


bool BattleShip::Board::validRowAndCol(char orientation, int row, int col, int length) const {
    // check if row and col are out of bounds
    if (row < height && row >= 0 and col < width && col >= 0) {
        if (orientation == 'v' or orientation == 'V') {
            return (row + length - 1) < height;
        } else {
            return (col + length - 1) < width;
        }
    }
    return false;
}

bool BattleShip::Board::availablePlacement(char orientation, int row, int col, int length) const {
    // check if coordinate already has a ship placed there
    for (int i = 0; i < length; ++i) {
        if (orientation == 'v' or orientation == 'V') {
            if (board.at(row + i).at(col) != '*') {
                return false;
            }
        } else {
            if (board.at(row).at(col + i) != '*') {
                return false;
            }
        }
    }
    return true;
}
