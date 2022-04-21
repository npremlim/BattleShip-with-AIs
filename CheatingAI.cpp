//
// Created by Naomi on 5/27/2021.
//

#include "CheatingAI.h"
#include <iostream>
#include <string>
#include <utility>
BattleShip::CheatingAI::CheatingAI(std::string playerName, int boardHeight, int boardWidth,std::mt19937& generator2) : AIPlayer(std::move(playerName), boardHeight, boardWidth,generator2) {
  //std::cout<<"Random AI created"<<std::endl;

}



void BattleShip::CheatingAI::attack(BattleShip::Board& opponentBoard, const std::string& opponentName, std::map<char,int>& opponentShips){
  int row, col;
  char element;

  do {
    do {
        bool end=false;
      for(int i=0;i<opponentBoard.height && !end;i++){
        for(int j=0;j<opponentBoard.width && !end;j++){

          char target;
          target=opponentBoard.getElement(i,j);
          if(target!='*' && target!='X' && target!='O'){

            row=i;
            col=j;
            end=true;
          }
        }
      }



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
