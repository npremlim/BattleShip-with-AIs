//
// Created by Naomi on 5/27/2021.
//

#ifndef BATTLESHIPSRC__SEARCHDESTROYAI_H_
#define BATTLESHIPSRC__SEARCHDESTROYAI_H_
#include "RandomAI.h"
#include "Board.h"
#include <vector>
#include <utility>
#include <random>

namespace BattleShip {
class SearchDestroyAI : public RandomAI {
 public:

  SearchDestroyAI(std::string playerName, int boardHeight, int boardWidth,std::mt19937& generator2);
  void attack(Board& opponentBoard, const std::string& opponentName, std::map<char,int>& opponentShips) override;
};
}
#endif //BATTLESHIPSRC__SEARCHDESTROYAI_H_
