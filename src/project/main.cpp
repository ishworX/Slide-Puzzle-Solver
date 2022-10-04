#include <iostream>
#include "./boardTiles.h"
#include "./slidingSolver.h"
#include <cmath>
#include <string>
#include <list>


int main() {

  std::cout << "Please input your desired 3 x 3 tile board you want to solve. " << std::endl;
  std::cout << "Must contain all digits in 1-8, with the ninth digit being 0. " << std::endl;
  std::cout << "The condition above can be met by putting numbers in any order. " << std::endl;
  std::cout << "As long as the 3 x 3 tile board is 9 characters long. " << std::endl;

  std::cout << std::endl;

  std::cout << "Enter the Goal Configuration: ";
  std::string myGoal;
  std::cin >> myGoal;
  Board_Tile* gBoard = new Board_Tile(myGoal);

  std::cout << std::endl;

  std::cout << "Enter the Initial Configuration: ";
  std::string myString;
  std::cin >> myString;
  Board_Tile* board = new Board_Tile(myString);

  if(board->inputChecker() != false && gBoard->inputChecker() != false) {

  board->getMyBoard();
  board->getMyMoves();
  board->numMoves();

  std::cout<<"The Manhattan distance sum is "<< board->Manhattan_Distance(gBoard)<<std::endl;

  Sliding_Solver solver(myString, myGoal);
  Board_Tile solved = solver.solve_Puzzle();

  std::cout << "Final board: " << solved.getMyBoard() << std::endl;
  std::cout << "Total moves: " << solved.numMoves() << std::endl;
  std::cout << "Solve order: " << solved.getMyMoves() << std::endl;

// char c[myString.length()];
//
//     std :: cout<<"String to char array conversion:\n";
//     for (int i = 0; i < sizeof(c); i++) {
//         c[i] = myString[i];
//         std:: cout << c[i] << std:: endl;
//       }

  } else {

    std::cout << "You did not input your initial configuration correctly. " << std::endl;

  }

  return 0;
}
