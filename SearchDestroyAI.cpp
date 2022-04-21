//
// Created by Naomi on 5/27/2021.
//

#include "SearchDestroyAI.h"
#include <iostream>
#include <string>
#include <algorithm>
BattleShip::SearchDestroyAI::SearchDestroyAI(std::string playerName, int boardHeight, int boardWidth,std::mt19937& generator2) : RandomAI(playerName, boardHeight, boardWidth,generator2) {}


void BattleShip::SearchDestroyAI::attack(BattleShip::Board& opponentBoard, const std::string& opponentName, std::map<char,int>& opponentShips) {
  int row, col;
  char element;
if(list.empty()){
  BattleShip::RandomAI::attack(opponentBoard,opponentName,opponentShips);
}else{


  do {
    do {
      row = list[0].first;
      col = list[0].second;
      list.erase(list.begin());
      coords.erase(std::remove(coords.begin(), coords.end(), std::make_pair(row, col)), coords.end());


    } while (not opponentBoard.validRowAndCol('v', row, col, 1));
    element = opponentBoard.getElement(row, col);
    if(element!='*' && element!='X' && element!='O'){
        char nextElement;
        if (col-1 >= 0) {
            nextElement = opponentBoard.getElement(row, col - 1);
            if (nextElement != 'X' && nextElement != 'O') {
                list.emplace_back(std::make_pair(row, col - 1));
            }
        }
        if (row-1 >= 0) {
            nextElement = opponentBoard.getElement(row - 1, col);
            if (nextElement != 'X' && nextElement != 'O') {
                list.emplace_back(std::make_pair(row - 1, col));
            }
        }
        if (col+1 < boardWidth) {
            nextElement = opponentBoard.getElement(row, col + 1);
            if (nextElement != 'X' && nextElement != 'O') {
                list.emplace_back(std::make_pair(row, col + 1));
            }
        }
        if (row+1 < boardHeight) {
            nextElement = opponentBoard.getElement(row + 1, col);
            if (nextElement != 'X' && nextElement != 'O') {
                list.emplace_back(std::make_pair(row + 1, col));
            }
        }
    }
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
}