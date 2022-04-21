//
// Created by csien on 5/17/2021.
//

#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H

#include <vector>
#include <memory>

namespace BattleShip {
    class Player;
    class Game {
        public:
            explicit Game(std::vector<std::unique_ptr<Player>>& players);

            Game() = delete;

      void play();

        private:
            bool is_game_over() const;
            void do_a_round();

            std::vector<std::unique_ptr<Player>>* players;

            int turn;
    };
}

#endif //BATTLESHIP_GAME_H
