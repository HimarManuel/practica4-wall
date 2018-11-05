#pragma once

#include "row_t.hpp"

class wall_t {
private:

  int H_; //Altura del muro

  vector<row_t> wall_;

public:

  wall_t (int h) : H_(0), wall_(h) {}
  wall_t (void) : H_(0), wall_() {}

  ~wall_t (void) { wall_.clear(); };

  void insert_row (row_t& row) {
    wall_[H_] = row;
    H_++;
  }

  void remove_row (void) {
    H_--;
  }

  int heigh (void) {
    return H_;
  }

  ostream& write (void) {
    for (int i = 0; i < wall_.size(); i++) {
      wall_[i].write();
      cout << "\n";
    }
    return cout;
  }

  ostream& write (ostream& os) {
    for (int i = 0; i < wall_.size(); i++) {
      wall_[i].write();
      os << "\n";
    }
    return os;
  }
};
