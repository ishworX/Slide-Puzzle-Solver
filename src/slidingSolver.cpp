// ****************************************************
// CPSC 3620 Spring 2022
// Project #1 Sliding_Solver Class
// File : slidingSolver.cpp
// Purpose : Implementing the class for Sliding_Solver Class
// ****************************************************

#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include <functional>
#include <vector>
#include "./slidingSolver.h"
#include "./boardTiles.h"

Sliding_Solver::Sliding_Solver(std::string& iniBoard, std::string& goalBoard) {
  inConfig = iniBoard; // passing value of initial configuration
  goalConfig = goalBoard; // passing value of goal configuration
  Board_Tile tile1(iniBoard);
  tileQueue.push(tile1);
}

Board_Tile Sliding_Solver::solve_Puzzle() {
  std::vector<Board_Tile> previousS;
  std::vector<Board_Tile> nexts;
  Board_Tile* goalB = new Board_Tile(goalConfig);
  previousS.push_back(tileQueue.top());
  while (!tileQueue.empty()) {
    Board_Tile temp = tileQueue.top();
    tileQueue.pop();
    if (temp.getMyBoard() == goalConfig) {
      return temp;
    }
    // get nextConfigs
    nexts = temp.nextConfigs();
    // check that nextConfigs aren't duplicates (create vector to hold previous states)
    // call Manhattan_Distance using goalConfig object
    // if nextConfig is a state that is not a duplicate, push to back of queue (and to back of vector)

    for (int i = 0; i < nexts.size(); i++) {
      bool notRepeat = true;
      for (int j = 0; j < previousS.size(); j++) {
        if (nexts[i].getMyBoard() == previousS[j].getMyBoard()) {
          notRepeat = false;
        }
      }
      if (notRepeat) {
        nexts[i].Manhattan_Distance(goalB);
        tileQueue.push(nexts[i]);
        previousS.push_back(nexts[i]);
      }
    }
  }
  Board_Tile tile(goalConfig);
  return tile;
}

bool operator>(const Board_Tile& boardA, const Board_Tile& boardB) {
  return (boardA.getBothD() > boardB.getBothD());
}
