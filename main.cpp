#include <vector>
#include <memory>
#include "setup.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include "Utility.h"

int main(int argc, char** argv) {
    int boardHeight, boardWidth;
    std::vector<BattleShip::Ship> ships;
    std::vector<std::unique_ptr<BattleShip::Player>> players;


    std::map<char,int> store;
    if (argc > 1) {
        //read in text file to set up the board and ships
        int seed;
        if (argc == 2) {
            seed = (int) time(nullptr); // default seed if not provided
        } else {
            seed = std::atoi(argv[2]); // get seed
        }
        std::string choice;
        BattleShip::configBoardAndShips(argv[1], boardHeight, boardWidth, ships,store);
        // create players
        std::cout<<"What type of game do you want to play?"<<std::endl<<"1. Human vs Human"<<std::endl<<"2. Human vs AI"<<std::endl<<"3. AI vs AI"<<std::endl;
        std::cout<<"Your choice: ";
        std::getline(std::cin, choice);

        std::mt19937 generator2(seed);

        if(choice=="1"){
          BattleShip::createHumanPlayers(boardHeight, boardWidth, ships, players);
          BattleShip::createHumanPlayers(boardHeight, boardWidth, ships, players);

          //play the game

          BattleShip::Game theGame(players);
          theGame.play();
        }else if(choice=="2"){
          std::string AIchoice;
          std::cout<<"What AI do you want?"<<std::endl<<"1. Cheating AI"<<std::endl<<"2. Random AI"<<std::endl<<"3. Hunt Destroy AI"<<std::endl;
          std::cout<<"Your choice: ";


          if(AIchoice=="1"){
            BattleShip::createCheatingAI(boardHeight,boardWidth,ships,players,generator2);

          }
          else if(AIchoice=="2"){
            BattleShip::createRandomAI(boardHeight,boardWidth,ships,players,generator2);

          }
          else if(AIchoice=="3"){
            BattleShip::createSearchDestroyAI(boardHeight,boardWidth,ships,players,generator2);

          }
          BattleShip::createHumanPlayers(boardHeight, boardWidth, ships, players);


          BattleShip::Game theGame(players);
          theGame.play();
        }
        else if(choice=="3"){
          std::string AIchoice;
          std::cout<<"What AI do you want?"<<std::endl<<"1. Cheating AI"<<std::endl<<"2. Random AI"<<std::endl<<"3. Hunt Destroy AI"<<std::endl;
          std::cout<<"Your choice: ";
          std::getline(std::cin, AIchoice);


          if(AIchoice=="1"){
            BattleShip::createCheatingAI(boardHeight,boardWidth,ships,players,generator2);
            std::cout<<"What AI do you want?"<<std::endl<<"1. Cheating AI"<<std::endl<<"2. Random AI"<<std::endl<<"3. Hunt Destroy AI"<<std::endl;
            std::cout<<"Your choice: ";
            std::string secondchoice;
            std::getline(std::cin, secondchoice);
            if(secondchoice=="1"){
              BattleShip::createCheatingAI(boardHeight,boardWidth,ships,players,generator2);
            }
            else if(secondchoice=="2"){
              BattleShip::createRandomAI(boardHeight,boardWidth,ships,players,generator2);
            }
            else if(secondchoice=="3"){
              BattleShip::createSearchDestroyAI(boardHeight,boardWidth,ships,players,generator2);
            }

          }

          else if(AIchoice=="2"){
            BattleShip::createRandomAI(boardHeight,boardWidth,ships,players,generator2);
            std::cout<<"What AI do you want?"<<std::endl<<"1. Cheating AI"<<std::endl<<"2. Random AI"<<std::endl<<"3. Hunt Destroy AI"<<std::endl;
            std::cout<<"Your choice: ";

            std::string secondchoice;
            std::getline(std::cin, secondchoice);
            if(secondchoice=="1"){
              BattleShip::createCheatingAI(boardHeight,boardWidth,ships,players,generator2);
            }
            else if(secondchoice=="2"){
              BattleShip::createRandomAI(boardHeight,boardWidth,ships,players,generator2);
            }
            else if(secondchoice=="3"){
              BattleShip::createSearchDestroyAI(boardHeight,boardWidth,ships,players,generator2);
            }
          }
          else if(AIchoice=="3"){
            BattleShip::createSearchDestroyAI(boardHeight,boardWidth,ships,players,generator2);
            std::cout<<"What AI do you want?"<<std::endl<<"1. Cheating AI"<<std::endl<<"2. Random AI"<<std::endl<<"3. Hunt Destroy AI"<<std::endl;
            std::cout<<"Your choice: ";

            std::string secondchoice;
            std::getline(std::cin, secondchoice);
            if(secondchoice=="1"){
              BattleShip::createCheatingAI(boardHeight,boardWidth,ships,players,generator2);
            }
            else if(secondchoice=="2"){
              BattleShip::createRandomAI(boardHeight,boardWidth,ships,players,generator2);
            }
            else if(secondchoice=="3"){
              BattleShip::createSearchDestroyAI(boardHeight,boardWidth,ships,players,generator2);
            }
          }

          BattleShip::Game theGame(players);
          theGame.play();
        }

    }
    return 0;
}
