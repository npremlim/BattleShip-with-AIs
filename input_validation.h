//
// Created by csien on 5/17/2021.
//

#ifndef BATTLESHIP_INPUT_VALIDATION_H
#define BATTLESHIP_INPUT_VALIDATION_H

#include <string>
#include <vector>
#include "Board.h"

namespace BattleShip {
    char oriRowAndCol(const std::string& name, char shipType, int shipSize, int& row, int& col);
    char shipHorOrVer(const std::string& name, char shipType);
    char getHorOrVer(const std::string& name, char shipType);
    bool validHorOrVer(const std::vector<char>& values, char value);
    bool getRowAndCol(const std::string& name, char shipType, int shipSize, int& row, int& col);
    bool legalPlacement(char orientation, int row, int col, int shipSize, const Board& board);

    template<typename RandomGeneratorType>
    int getRandInt(int min, int max, RandomGeneratorType& generator);

    //get a random number between [min,max]
    template<typename RandomGeneratorType>
    int getRandInt(int min, int max, RandomGeneratorType& generator) {
        std::uniform_int_distribution<> distribution(min, max);
        return distribution(generator);
    }
}

#endif //BATTLESHIP_INPUT_VALIDATION_H
