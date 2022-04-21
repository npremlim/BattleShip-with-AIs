//
// Created by Naomi on 5/27/2021.
//

#ifndef BATTLESHIPSRC__CHEATINGAI_H_
#define BATTLESHIPSRC__CHEATINGAI_H_
#include "AIPlayer.h"
#include "Board.h"
#include <vector>
#include <utility>
#include <random>

namespace BattleShip {
class CheatingAI : public AIPlayer {
 public:
  CheatingAI(std::string playerName, int boardHeight, int boardWidth,std::mt19937& generator2);
  void attack(Board& opponentBoard, const std::string& opponentName, std::map<char,int>& opponentShips) override;

  std::vector<std::pair<int,int> > coords;
};
}
#endif //BATTLESHIPSRC__CHEATINGAI_H_
