//
// Created by csien on 5/17/2021.
//

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include "setup.h"
#include "input_validation.h"
#include "AIPlayer.h"
#include "RandomAI.h"
#include "CheatingAI.h"
#include "SearchDestroyAI.h"
#include "HumanPlayer.h"
void BattleShip::configBoardAndShips(char *filepath, int& boardHeight, int& boardWidth, std::vector <BattleShip::Ship>& ships,std::map<char,int> &store) {
    std::ifstream inFS;
    int numShips;
    char shipType;
    int shipLength;

    inFS.open(filepath); // open file
    if (!inFS.is_open()) {
        std::cout << "Could not open file." << std::endl;
        return;
    }
    // read in all ships and their lengths
    inFS >> boardHeight;
    inFS >> boardWidth;
    inFS >> numShips;

    for (int i = 0; i < numShips; ++i) {
        inFS >> shipType;
        inFS >> shipLength;
        // store ship into ships vector
        store.insert({shipType,shipLength});
     //   ships.emplace_back(shipType, shipLength);
    }
  std::map<char, int>::iterator it;

  for (it = store.begin(); it != store.end(); it++)
  {
    ships.emplace_back(it->first, it->second);
  }
}
void BattleShip::createSearchDestroyAI(int& boardHeight,int& boardWidth, std::vector <BattleShip::Ship>& ships, std::vector<std::unique_ptr<BattleShip::Player>>& players,std::mt19937& generator2){
  int playernumb;
  if(players.empty()){
    playernumb =1;
  }else if(!players.empty()){
    playernumb=2;
  }
  std::string playername= std::to_string(playernumb);

  //std::minstd_rand generator2(3);
  std::string name="AI "+playername;
  char orientation;
  int row,col;
  SearchDestroyAI player1(name, boardHeight, boardWidth,generator2);
  for(int x=0;x<boardHeight;x++){
    for(int y=0;y<boardWidth;y++){
      player1.coords.emplace_back(std::make_pair(x,y));
    }
  }

  //player1.getPlacementBoard().printBoard();

  for (auto& ship : ships) {
    do {
      orientation=player1.get_orientation();
      row=player1.get_row(orientation, ship.getSize());
      col=player1.get_col(orientation, ship.getSize());
    } while (not BattleShip::legalPlacement(orientation, row, col, ship.getSize(), player1.getPlacementBoard()));

    player1.placeShip(ship, orientation, row, col);
    player1.addShip(ship);
    std::cout<<name<<"'s Board"<<std::endl;
    player1.getPlacementBoard().printBoard();
    std::cout<<std::endl;
  }
  players.push_back(std::make_unique<BattleShip::SearchDestroyAI>(player1));


}
void BattleShip::createRandomAI(int& boardHeight,int& boardWidth, std::vector <BattleShip::Ship>& ships, std::vector<std::unique_ptr<BattleShip::Player>>& players,std::mt19937& generator2){
  int playernumb;
  if(players.empty()){
   playernumb =1;
  }else if(!players.empty()){
    playernumb=2;
  }
  std::string playername= std::to_string(playernumb);

  //std::minstd_rand generator2(3);
    std::string name="AI "+playername;
    char orientation;
    int row,col;
    RandomAI player1(name, boardHeight, boardWidth,generator2);
    for(int x=0;x<boardHeight;x++){
      for(int y=0;y<boardWidth;y++){
        player1.coords.emplace_back(std::make_pair(x,y));
      }
    }

    //player1.getPlacementBoard().printBoard();

  for (auto& ship : ships) {
    do {
      orientation=player1.get_orientation();
      row=player1.get_row(orientation, ship.getSize());
      col=player1.get_col(orientation, ship.getSize());

    } while (not BattleShip::legalPlacement(orientation, row, col, ship.getSize(), player1.getPlacementBoard()));

    player1.placeShip(ship, orientation, row, col);
    player1.addShip(ship);
    std::cout<<name<<"'s Board"<<std::endl;
    player1.getPlacementBoard().printBoard();
    std::cout<<std::endl;
  }
  players.push_back(std::make_unique<BattleShip::RandomAI>(player1));


}


void BattleShip::createCheatingAI(int& boardHeight,int& boardWidth, std::vector <BattleShip::Ship>& ships, std::vector<std::unique_ptr<BattleShip::Player>>& players,std::mt19937& generator2){
  int playernumb;
  if(players.empty()){
    playernumb =1;
  }else if(!players.empty()){
    playernumb=2;
  }
  std::string playername= std::to_string(playernumb);

  //std::minstd_rand generator2(3);
  std::string name="AI "+playername;
  char orientation;
  int row,col;
  CheatingAI player1(name, boardHeight, boardWidth,generator2);


  //player1.getPlacementBoard().printBoard();

  for (auto& ship : ships) {
    do {
      orientation=player1.get_orientation();
      row=player1.get_row(orientation, ship.getSize());
      col=player1.get_col(orientation, ship.getSize());
    } while (not BattleShip::legalPlacement(orientation, row, col, ship.getSize(), player1.getPlacementBoard()));

    player1.placeShip(ship, orientation, row, col);
    player1.addShip(ship);
    std::cout<<name<<"'s Board"<<std::endl;
    player1.getPlacementBoard().printBoard();
    std::cout<<std::endl;
  }

  players.push_back(std::make_unique<BattleShip::CheatingAI>(player1));


}

void BattleShip::createHumanPlayers(int& boardHeight, int& boardWidth, std::vector <BattleShip::Ship>& ships, std::vector<std::unique_ptr<BattleShip::Player>>& players) {
    // create instance of player class for both players
    int playernumb;
    if(players.empty()){
      playernumb =1;
    }else if(!players.empty()){
      playernumb=2;
    }
    std::string name;
    char orientation;
    int row, col;

    std::cout << "Player "<<playernumb<<" please enter your name: ";
    std::getline(std::cin, name);

    HumanPlayer player1(name, boardHeight, boardWidth);
    // print initial empty placement board
    player1.getPlacementBoard().printBoard();

    for (auto& ship : ships) {
        do {
            orientation = BattleShip::oriRowAndCol(name, ship.getType(), ship.getSize(), row, col);
        } while (not BattleShip::legalPlacement(orientation, row, col, ship.getSize(), player1.getPlacementBoard()));
        // place ship on board
        player1.placeShip(ship, orientation, row, col);
        // add ship to map
        player1.addShip(ship);
        // print board with added ship
        player1.getPlacementBoard().printBoard();
    }

    players.push_back(std::make_unique<BattleShip::Player>(player1));

}
