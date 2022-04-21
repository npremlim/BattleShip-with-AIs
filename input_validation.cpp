//
// Created by csien on 5/17/2021.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include "input_validation.h"

char BattleShip::oriRowAndCol(const std::string& name, char shipType, int shipSize, int& row, int& col) {
    char orientation;
    bool areNums;
    do {
        orientation = BattleShip::shipHorOrVer(name, shipType);
        areNums = BattleShip::getRowAndCol(name, shipType, shipSize, row, col);
    } while (not areNums);
    return orientation;
}

char BattleShip::shipHorOrVer(const std::string& name, char shipType) {
    std::vector<char> goodVals = {'h', 'H', 'v', 'V'};
    char orientation;
    do {
        orientation = getHorOrVer(name, shipType);
    } while (not BattleShip::validHorOrVer(goodVals, orientation));
    return orientation;
}

char BattleShip::getHorOrVer(const std::string& name, char shipType) {
    std::string line;
    while (true) {
        std::cout << name << ", do you want to place " << shipType << " horizontally or vertically?" << std::endl;
        std::cout << "Enter h for horizontal or v for vertical" << std::endl;
        std::cout << "Your choice: ";
        std::getline(std::cin, line); // grabs the entire line
        std::stringstream line2parse(line);
        std::string word;
        line2parse >> word;
        if (line2parse) { // if I was able to read the word
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse) { // if there is nothing left we will fail to read it
                if (word.size() == 1) {
                    return word.at(0);
                }
            }
        }
    }
}

bool BattleShip::validHorOrVer(const std::vector<char>& values, char value) {
    return std::find(values.begin(), values.end(), value) != values.end();
}

bool BattleShip::getRowAndCol(const std::string& name, char shipType, int shipSize, int& row, int& col) {
    std::string line;
    std::cout << name << ", enter the row and column you want to place " << shipType;
    std::cout << ", which is " << shipSize << " long, at with a space in between row and col: ";
    std::getline(std::cin, line); // grabs the entire line
    std::stringstream line2parse(line);
    line2parse >> row >> col;
    if (line2parse) { // if I was able to read the number
        std::string what_is_left;
        line2parse >> what_is_left;
        if (not line2parse) { // if there is nothing left we will fail to read it
            return true;
        }
    }
    return false;
}

bool BattleShip::legalPlacement(char orientation, int row, int col, int shipSize, const Board& board) {
    return (board.validRowAndCol(orientation, row, col, shipSize) and
            board.availablePlacement(orientation, row, col, shipSize));
}
