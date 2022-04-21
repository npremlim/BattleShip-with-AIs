//
// Created by Naomi on 5/28/2021.
//

#ifndef BATTLESHIPSRC__HUMANPLAYER_H_
#define BATTLESHIPSRC__HUMANPLAYER_H_
#include "Player.h"
#include "Board.h"
#include <vector>
#include <utility>
#include <random>
namespace BattleShip {
class HumanPlayer : public Player {
 public:
  HumanPlayer(std::string playerName, int boardHeight, int boardWidth);



};

}
#endif //BATTLESHIPSRC__HUMANPLAYER_H_
