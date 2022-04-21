
#ifndef BATTLESHIPSRC__AIPLAYER_H_
#define BATTLESHIPSRC__AIPLAYER_H_
#include "Player.h"
#include "Board.h"
#include <vector>
#include <utility>
#include <random>
namespace BattleShip {
    class AIPlayer : public Player {
     public:
      std::mt19937& generator2;
      AIPlayer(std::string playerName, int boardHeight, int boardWidth,std::mt19937& generator2);

      char get_orientation();
      std::vector<std::pair<int,int> > vect;
      int get_row(char orientation, int shipLen);
      int get_col(char orientation, int shipLen);


};

}
#endif //BATTLESHIPSRC__AIPLAYER_H_
