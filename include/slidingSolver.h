// ****************************************************
// CPSC 3620 Spring 2022
// Project #1 Sliding_Solver Class
// File: slidingSolver.h
// Purpose : This is a header file for Sliding_Solver Class.
// Date: April 27th, 2022
// ****************************************************

#ifndef SLIDINGSOLVER_H
#define SLIDINGSOLVER_H

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "./boardTiles.h"

class Sliding_Solver {
  public:
/**
* Default Class constructor, for Sliding_Solver class, it takes initial
*  configuration and goal configuration as its paramaters
* @param[in] a string that contains initial configuration
* @param[in] a string that contains goal configuration
*/
    Sliding_Solver(std::string&, std::string&);

/**
* a void function that solves the puzzle using the A* search algorithm
*/
    Board_Tile solve_Puzzle();

    friend bool operator>(Board_Tile&, Board_Tile&);

  private:
// represents a minHeap of Board_Tile objects
    std::priority_queue<Board_Tile, std::vector<Board_Tile>, std::greater<Board_Tile>> tileQueue;
// represents initial configuration
    std::string inConfig;
// represents goal configuration
    std:: string goalConfig;
// represents the last move that was made
    char prevMove = ' ';
};

#endif
