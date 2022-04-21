//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_UTILITY_H
#define BATTLESHIP_UTILITY_H
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <random>
#include <string>
#include <sstream>
namespace BattleShip {

//declarations

template<typename ValueType, typename ContainerType>
bool contains(const ValueType& value, const ContainerType& container);

template<typename T>
std::istream& verifiedReadWithOnlyWhiteSpaceAfter(std::istream& in, T& val);

template<typename T, typename...Args>
std::istream& verifiedReadWithOnlyWhiteSpaceAfter(std::istream& in, T& val1, Args&& ... args);

template<typename T>
std::istream& verifiedRead(std::istream& in, T& val);

template<typename T, typename...Args>
std::istream& verifiedRead(std::istream& in, T& val, Args&& ... args);

template<typename... Args>
std::istream& verifiedLineRead(std::istream& in, Args&& ... args);

template<typename ContainerType, typename RandomGeneratorType>
typename ContainerType::const_iterator chooseRandom(const ContainerType& container, RandomGeneratorType& rand_gen);

template<typename RandomGeneratorType>
int getRandInt(int min, int max, RandomGeneratorType& generator);



//definitions

template<typename ValueType, typename ContainerType>
bool contains(const ValueType& value, const ContainerType& container) {
  return std::find(container.begin(), container.end(), value) != container.end();
}

template<typename T>
std::istream& verifiedReadWithOnlyWhiteSpaceAfter(std::istream& in, T& val) {
  verifiedRead(in, val);

  for (char curChar = in.peek(); in && !in.eof() && curChar != '\n'; curChar = in.get()) {
    if (!isspace(curChar)) {
      throw std::logic_error("Nonwhitespace character after read input");
    }
  }
  return in;
}

template<typename T, typename...Args>
std::istream& verifiedReadWithOnlyWhiteSpaceAfter(std::istream& in, T& val1, Args&& ... args) {
  verifiedRead(in, val1);
  verifiedReadWithOnlyWhiteSpaceAfter(in, std::forward<Args>(args)...);
  return in;
}

template<typename T>
std::istream& verifiedRead(std::istream& in, T& val) {
  if (in) {
    in >> val;
    if (!in) {
      throw std::logic_error("Failed to read in value. Value formatted incorrectly");
    }
  } else {
    throw std::logic_error("Failed to read as stream is no longer good.");
  }
  return in;
}

template<typename T, typename...Args>
std::istream& verifiedRead(std::istream& in, T& val, Args&& ... args) {
  verifiedRead(in, val);
  verifiedRead(in, std::forward<Args>(args)...);
  return in;
}

template<typename... Args>
std::istream& verifiedLineRead(std::istream& in, Args&& ... args) {
  std::string input;
  std::getline(in, input);
  std::stringstream line(input);
  verifiedReadWithOnlyWhiteSpaceAfter(line, std::forward<Args>(args)...);
  return in;
}

template<typename ContainerType, typename RandomGeneratorType>
typename ContainerType::const_iterator chooseRandom(const ContainerType& container, RandomGeneratorType& rand_gen) {
  int num_elements = std::distance(container.cbegin(), container.cend());
  std::uniform_int_distribution<> distribution(0, num_elements - 1);
  auto itr = container.cbegin();
  int move_amount = distribution(rand_gen);
  std::advance(itr, move_amount);
  return itr;
}

//get a random number between [min,max]
template<typename RandomGeneratorType>
int getRandInt(int min, int max, RandomGeneratorType& generator) {
  std::uniform_int_distribution<> distribution(min, max);
  return distribution(generator);
}

}

#endif //BATTLESHIP_UTILITY_H
