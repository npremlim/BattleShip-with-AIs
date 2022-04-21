//
// Created by csien on 5/17/2021.
//

#include <iostream>
#include <sstream>
#include "Player.h"
#include <map>
#include <memory>
BattleShip::Player::Player(std::string playerName, int boardHeight, int boardWidth) : boardHeight(boardHeight),boardWidth(boardWidth),name(std::move(playerName)),placementBoard(boardHeight, boardWidth), firingBoard(boardHeight, boardWidth) {}

BattleShip::Player::~Player() = default;

std::string BattleShip::Player::getName() const {
    return name;
}

BattleShip::Board& BattleShip::Player::getPlacementBoard() {
    return placementBoard;
}

std::map<char, int>& BattleShip::Player::getStoreShips() {
    return storeShips;
}

void BattleShip::Player::updateFiringBoard(char symbol, int row, int col) {
    firingBoard.updateElement(symbol, row, col);
}

void BattleShip::Player::displayBoards() {
    // display both firing and placement boards
    std::cout << name << "'s Firing Board" << std::endl;
    firingBoard.printBoard();
    std::cout << std::endl << std::endl;
    std::cout << name << "'s Placement Board" << std::endl;
    placementBoard.printBoard();
}

void BattleShip::Player::addShip(BattleShip::Ship ship){
    // add ship into map storeShips
    storeShips.insert({ship.getType(), ship.getSize()});
}

void BattleShip::Player::placeShip(BattleShip::Ship ship, char orientation, int row, int col) {
    // function to place ships on current player's placement board
    for (int i = 0; i < ship.getSize(); ++i) {
        if (orientation == 'v' or orientation == 'V') {
            placementBoard.updateElement(ship.getType(), row + i, col);
        } else {
            placementBoard.updateElement(ship.getType(), row, col + i);
        }
    }
}

void BattleShip::Player::attack(Board& opponentBoard, const std::string& opponentName, std::map<char,int>& opponentShips) {
    // function to fire at opponent's board with coordinates row,col

    int row, col;
    char element;

    do {
        do {
            displayBoards();
            getTarget(row, col);
        } while (not opponentBoard.validRowAndCol('v', row, col, 1));
        element = opponentBoard.getElement(row, col);
    } while (element == 'X' or element == 'O');
    // if the element is a ship element, destroy it and update with X symbol
    if (element != '*') {
        updateFiringBoard('X', row, col);
        opponentBoard.updateElement('X', row, col);
        displayBoards();
        std::cout << name << " hit " << opponentName << "'s " << element << "!" << std::endl;
        opponentShips[element]--;
        if (opponentShips[element] == 0) {
            std::cout << name << " destroyed " << opponentName << "'s "<< element << "!" << std::endl;
            opponentShips.erase(element);
        }
        std::cout << std::endl;
    } else {
        // if not, update element with 0 symbol
        updateFiringBoard('O', row, col);
        opponentBoard.updateElement('O', row, col);
        displayBoards();
        std::cout << "Missed." << std::endl << std::endl;
    }
}

void BattleShip::Player::getTarget(int& row, int& col) const {
    std::string line;
    while (true) {
        std::cout << name << ", where would you like to fire?" << std::endl;
        std::cout << "Enter your attack coordinate in the form row col: ";
        std::getline(std::cin, line); // grabs the entire line
        std::stringstream line2parse(line);
        line2parse >> row >> col;
        if (line2parse) { // if I was able to read the number
            std::string what_is_left;
            line2parse >> what_is_left;
            if (not line2parse) { // if there is nothing left we will fail to read it
                return;
            }
        }
    }
}
