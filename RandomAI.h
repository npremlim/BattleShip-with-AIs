//
// Created by Naomi on 5/26/2021.
//

#ifndef BATTLESHIPSRC__RANDOMAI_H_
#define BATTLESHIPSRC__RANDOMAI_H_
#include "AIPlayer.h"
#include "Board.h"
#include <vector>
#include <utility>
#include <random>

namespace BattleShip {
class RandomAI : public AIPlayer {
 public:
  RandomAI(std::string playerName, int boardHeight, int boardWidth,std::mt19937& generator2);
  void attack(Board& opponentBoard, const std::string& opponentName, std::map<char,int>& opponentShips) override;
  std::vector<std::pair<int,int> > coords;
  std::vector<std::pair<int,int> > list;

};
}

#endif //BATTLESHIPSRC__RANDOMAI_H_
