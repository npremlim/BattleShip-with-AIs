//
// Created by Naomi on 5/26/2021.
//
#include "RandomAI.h"
#include <iostream>
#include <string>
#include <utility>
BattleShip::RandomAI::RandomAI(std::string playerName, int boardHeight, int boardWidth,std::mt19937& generator2) : AIPlayer(std::move(playerName), boardHeight, boardWidth,generator2) {
  //std::cout<<"Random AI created"<<std::endl;

}


void BattleShip::RandomAI::attack(BattleShip::Board& opponentBoard, const std::string& opponentName, std::map<char,int>& opponentShips){
  int row, col,index;
  char element;

  do {
    do {
      std::uniform_int_distribution<int> dist(0, (int) coords.size() - 1);
      index=dist(generator2);
      row=coords[index].first;
      col=coords[index].second;

      coords.erase(coords.begin()+index);

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
