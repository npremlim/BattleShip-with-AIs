//
// Created by csien on 5/17/2021.
//

#ifndef BATTLESHIP_SETUP_H
#define BATTLESHIP_SETUP_H

#include "Ship.h"
#include "Player.h"
#include "AIPlayer.h"
#include "CheatingAI.h"
namespace BattleShip {

    void configBoardAndShips(char *filepath, int& boardHeight, int& boardWidth, std::vector <BattleShip::Ship> &ships,std::map<char,int> &store);
    void createRandomAI(int& boardHeight,int& boardWidth, std::vector <BattleShip::Ship>& ships, std::vector<std::unique_ptr<BattleShip::Player>>& players,std::mt19937& generator2);
    void createSearchDestroyAI(int& boardHeight,int& boardWidth, std::vector <BattleShip::Ship>& ships, std::vector<std::unique_ptr<BattleShip::Player>>& players,std::mt19937& generator2);

    void createHumanPlayers(int& boardHeight, int& boardWidth, std::vector <BattleShip::Ship> &ships, std::vector<std::unique_ptr<BattleShip::Player>>& players);
    void createCheatingAI(int& boardHeight,int& boardWidth, std::vector <BattleShip::Ship>& ships, std::vector<std::unique_ptr<BattleShip::Player>>& players,std::mt19937& generator2);

}

#endif //BATTLESHIP_SETUP_H
