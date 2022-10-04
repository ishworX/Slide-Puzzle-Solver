// ****************************************************
// CPSC 3620 Spring 2022
// Project #1 Board_Tile Class
// File : slidingTiles.cpp
// Purpose : Implementing the class for Board_Tile Class,
// ****************************************************
//
#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>
#include "./boardTiles.h"

Board_Tile:: Board_Tile(const std::string& board) {
    config = board;
    movesFromStart = "";
}

bool Board_Tile:: inputChecker() {
  if (config.length() != 9) {
    return false;
  } else {
      for (char const &c : config) {
        if (std::isdigit(c) == 0 || c == '9') {
          return false;
        }
      }
      return true;
  }
}

std::string Board_Tile:: getMyMoves() {
  return movesFromStart;
}

int Board_Tile:: numMoves() const{
  return movesFromStart.length();
}

std::string Board_Tile:: getMyBoard() {
  return config;
}

int Board_Tile:: Manhattan_Distance(const Board_Tile* goalconfig) {
  int  i = 0;
  int sum = 0;

  while (i < config.length()){
    std::string che = "0";
    if (config[i] == goalconfig->config[i]) {
      i++;
    } else {
      int j = 0;
      do {
        if(config[i] == goalconfig->config[j]) {
          int row1, col1, row2, col2;
          row1 = i / 3;
          col1 = i % 3;
          row2 = j / 3;
          col2 = j % 3;

          if (config[i] == che[0]){
            sum = sum + 0;
          } else
          if ((fabs(row2 - row1) == 2 && fabs(col2 - col1) == 2)) {
            sum = sum + 4;
          } else if ((fabs(row2 - row1) == 1 && fabs(col2 - col1) == 1)) {
            sum = sum + 2;
          } else if ((fabs(row2 - row1) == 2 && fabs(col2 - col1) == 1) || (fabs(row2 - row1)
          == 1 && fabs(col2 - col1) == 2)) {
            sum = sum + 3;
          } else if (fabs(row2 - row1) == 1 || fabs(col2 - col1) == 1) {
            sum = sum + 1;
          } else if (fabs(row2 - row1) == 2 || fabs(col2 - col1) == 2) {
            sum = sum + 2;
          }
          j = config.length();
        } else {
          j++;
        }
      } while (j < config.length());
      i++;
    }
  }
  manHatD = sum;
  return sum;
}

int Board_Tile::findZero() {
    for (int i = 0; i <= config.length(); i++)
        if (config[i] == '0')
            return i;
    return -1;
}

bool Board_Tile::checkUp() {
    int zero = findZero();
    if ((zero / 3) < 1)
        return false;
    else
        return true;
}

bool Board_Tile::checkDown() {
    int zero = findZero();
    if (zero / 3 >= 2)
        return false;
    else
        return true;
}

bool Board_Tile::checkLeft() {
    int zero = findZero();
    if ((zero % 3) < 1)
        return false;
    else
        return true;
}

bool Board_Tile::checkRight() {
    int zero = findZero();
    if (zero % 3 >= 2)
        return false;
    else
        return true;
}

Board_Tile Board_Tile::moveUp() {
    std::string temp = config;
    int zero = findZero();
    if (checkUp())
      std::swap(temp[zero], temp[zero-3]);
    else
      std::cout << "\nCan't move up";
    Board_Tile newTile(temp);
    newTile.movesFromStart = movesFromStart + 'U';
    return newTile;
}

Board_Tile Board_Tile::moveDown() {
    std::string temp = config;
    int zero = findZero();
    if (checkDown())
      std::swap(temp[zero], temp[zero+3]);
    else
      std::cout << "\nCan't move down";
    Board_Tile newTile(temp);
    newTile.movesFromStart = movesFromStart + 'D';
    return newTile;
}

Board_Tile Board_Tile::moveLeft() {
    std::string temp = config;
    int zero = findZero();
    if (checkLeft())
      std::swap(temp[zero], temp[zero-1]);
    else
      std::cout << "\nCan't move left";
    Board_Tile newTile(temp);
    newTile.movesFromStart = movesFromStart + 'L';
    return newTile;
}

Board_Tile Board_Tile::moveRight() {
    std::string temp = config;
    int zero = findZero();
    if (checkRight())
      std::swap(temp[zero], temp[zero+1]);
    else
      std::cout << "\nCan't move right";
    Board_Tile newTile(temp);
    newTile.movesFromStart = movesFromStart + 'R';
    return newTile;
}

//vector nextConfig that returns a vector of possible moves
std::vector<Board_Tile> Board_Tile::nextConfigs() {
  std::vector<Board_Tile> next;
  if (checkUp()) {
    Board_Tile up = moveUp();
    next.push_back(up);
  }
  if (checkDown()) {
    Board_Tile down = moveDown();
    next.push_back(down);
  }
  if (checkLeft()) {
    Board_Tile left = moveLeft();
    next.push_back(left);
  }
  if (checkRight()) {
    Board_Tile right = moveRight();
    next.push_back(right);
  }
  return next;
}

int Board_Tile::getBothD() const {
    return numMoves() + manHatD;
}

void Board_Tile:: swap(std::string c, int left, int right) {
  char temp = c[left];
  c[left] = c[right];
  c[right] = temp;
}
