// Copyright [2022] <Alejandro B, Fabian V, Kenneth V>

#ifndef DEFENSEMOVE_HPP
#define DEFENSEMOVE_HPP

#include "Move.hpp"

class DefenseMove : public Move {
 public: // Rule of 4
  DECLARE_RULE4(DefenseMove, default);

 public: // Default constructor and destructor
   DefenseMove();
   ~DefenseMove() = default;

 private: // General methods
  bool use(Monster* user,
  Monster* target = nullptr) const override;
};

#endif // DEFENSEMOVE_HPP
