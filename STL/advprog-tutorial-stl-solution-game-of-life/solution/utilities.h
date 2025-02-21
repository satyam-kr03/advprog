#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include "Matrix.h"
#include <cassert>
#include <iostream>

void print_domain(const Matrix<bool>& domain) {
  // Prints only the internal part of the matrix,
  // only fot the purpose of the game of life

  bool e;

  std::system("clear");
  for (auto j = 0; j < domain.columns(); j++) {
    std::cout << "__";
  }
  std::cout << std::endl;

  for (auto i = 1; i < domain.rows() - 1; i++) {
    std::cout << "| ";
    for (auto j = 1; j < domain.columns() - 1; j++) {
      e = domain(i, j);
      if (e == 0) {
        std::cout << "  ";
      } else {
        std::cout << "+ ";
      }
    }
    std::cout << " |";
    std::cout << std::endl;
  }

  for (auto j = 0; j < domain.columns(); j++) {
    std::cout << "==";
  }
  std::cout << std::endl;
}

/*
 * Add some interesting starting patterns for
 * game of life assuming a starting domain of size
 * at at least (20,20). Make sure you set the domain
 * to zero before calling this function.
 *
 */

void init_starting_patterns(Matrix<bool>& domain) {
  assert((domain.rows() >= 20) && "Needs at least 20 rows and columns");

  // beacon in bottom left
  domain(13, 2) = true;
  domain(13, 3) = true;
  domain(14, 2) = true;
  domain(14, 3) = true;

  domain(15, 4) = true;
  domain(15, 5) = true;
  domain(16, 4) = true;
  domain(16, 5) = true;

  // glider in top center
  domain(6, 10) = true;
  domain(6, 11) = true;
  domain(6, 12) = true;
  domain(5, 12) = true;
  domain(4, 11) = true;

  // blinker in center left
  domain(8, 3) = true;
  domain(8, 4) = true;
  domain(8, 5) = true;
}

#endif
