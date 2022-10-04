// ****************************************************
// CPSC 3620 Spring 2022
// Project #1 Board_Tile Class
// File: BoardTiles.h
// Purpose : This is a header file for Board_Tile Class.
// Date: April 27th, 2022
// ****************************************************

#ifndef BOARDTILES_H
#define BOARDTILES_H

#include <iostream>
#include <string>
#include <vector>


class Board_Tile {
  public:
/**
* Default Class constructor, for Board_Tile class, it ini tializes
*  the paramater to be the initial configuration
* @param[in] a string that contains user input for slide puzzle game
*/
    Board_Tile(const std::string&);

/**
* is a bool function that will return either true or false.
* true for if the user input is valid
* false for not
*/
    bool inputChecker();

/**
* returns a list of Board_Tile objects that are one move away
* from the current Board_Tile object
*/

/**
* returns number moves taken from initial board to reach the
* current configuration
*/
    int numMoves() const;

/**
* returns moves From Start to represent moves from initial configuration to
* current configuration
* @param[in] a Board Tile object that representes initial configuration
*/
    std::string getMyMoves();

/**
* gets initial configuration
* @param[in] a Board Tile object that representes initial configuration
*/
    std::string getMyBoard();

/**
* swaps numbers in the tile board from left to right
* @param[in] string c is a list of characters from initial configuration
* @param[in] int left is the left element of 0 in character array
* @param[in] int right is the right element of 0 in character array
*/
     void swap(std::string c, int left, int right);


/**
* returns the Manhattan Distance of object when compared to
* goalconfig
* @param[in] a Board Tile object that representes goalconfig
*/
    int Manhattan_Distance(const Board_Tile* goalconfig);

/**
* returns the position of '0' in our boards config string
*/
    int findZero();

/**
* returns true if a move is valid for our board
*/
    bool checkUp();
    bool checkDown();
    bool checkLeft();
    bool checkRight();

/**
* moves 0 either move up, down, left, or right
*/
    Board_Tile moveUp();
    Board_Tile moveDown();
    Board_Tile moveLeft();
    Board_Tile moveRight();
    int getBothD() const;

    std::vector<Board_Tile> nextConfigs();

  private:
// represents a 3 x 3 tile board configuration
    std::string config;

    int manHatD;

// represents the moves or steps taken that led from current configuration
// from initial configuration
    std::string movesFromStart;
};

#endif
