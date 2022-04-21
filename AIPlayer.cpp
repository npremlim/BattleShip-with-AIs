//
// Created by Naomi on 5/25/2021.
//
#include "AIPlayer.h"
#include <vector>
#include <iostream>
#include "Board.h"
#include <random>
BattleShip::AIPlayer::AIPlayer(std::string playerName, int boardHeight, int boardWidth,std::mt19937& generator2) :Player(playerName, boardHeight, boardWidth) ,generator2(generator2){}

char BattleShip::AIPlayer::get_orientation(){
  std::uniform_int_distribution<int> dist(0, 1);

  int num;
  char orientation;
  num=dist(generator2);
  if(num==0){
    orientation='h';
  }
  else if(num==1){
    orientation='v';
  }
  return orientation;
}

int BattleShip::AIPlayer::get_row(char orientation, int shipLen){
  int num;
  if (orientation == 'h') {
    std::uniform_int_distribution<int> dist(0, boardHeight - 1);
    num=dist(generator2);
  } else {
    std::uniform_int_distribution<int> dist(0, boardHeight - shipLen);
    num=dist(generator2);
}

return num;
}

int BattleShip::AIPlayer::get_col(char orientation, int shipLen){
  int num;
  if (orientation == 'h') {
    std::uniform_int_distribution<int> dist(0, boardWidth - shipLen);
    num=dist(generator2);
  } else {
    std::uniform_int_distribution<int> dist(0, boardWidth - 1);
    num=dist(generator2);
  }

  return num;
}