//
// Created by csien on 5/17/2021.
//

#include <iostream>
#include "Game.h"
#include "Player.h"
#include "AIPlayer.h"

BattleShip::Game::Game(std::vector<std::unique_ptr<Player>>& players) : players(&players), turn(0) {}

void BattleShip::Game::play() {
    // play the game and change turns while winning condition is not met
    while(not is_game_over()){
        do_a_round();

    }
}

bool BattleShip::Game::is_game_over() const {
    // if the map storing the ships of any of the players are empty, the game is over
    if(players->at(0)->getStoreShips().empty()) {
        std::cout << players->at(1)->getName() << " won the game!" << std::endl;
        return true;
    } else if (players->at(1)->getStoreShips().empty()) {
        std::cout << players->at(0)->getName() << " won the game!" << std::endl;
        return true;
    } else {
        return false;
    }
    // check ship map for remaining ships on both players' boards, if both are empty return true
}

void BattleShip::Game::do_a_round() {
    // change turns and ask for player's input to fire at the opponent's board
    if (turn == 0) {

        players->at(0)->attack(players->at(1)->getPlacementBoard(), players->at(1)->getName(), players->at(1)->getStoreShips());
        turn = 1;
    } else {
        players->at(1)->attack(players->at(0)->getPlacementBoard(), players->at(0)->getName(), players->at(0)->getStoreShips());
        turn = 0;
    }
}
