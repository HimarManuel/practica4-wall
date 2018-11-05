#pragma once

#include <iostream>

#include <cassert>

using namespace std;

class block_t {

private:
  int n_; //Tamaño del bloque

public:
  block_t (void) : n_(0) {}
  block_t (int n) : n_(n) {}

  ~block_t (void) {}

  const int block_size (void) { //Devuelve el tamaño del bloque
    return n_;
  }

  ostream& write (void) {

    if (n_ == 2) { cout << "xx"; } else if (n_ == 3) { cout << "xxx"; } else {
      for (int i = 0; i < n_; i++) {
        cout << 'x';
      }
    }
    cout << '|';
    return cout;
  }

  ostream& write (ostream& os) {
    if (n_ == 2) { os << "xx"; } else if (n_ == 3) { os << "xxx"; } else {
      for (int i = 0; i < n_; i++) {
        os << 'x';
      }
    }
    os << '|';
    return os;
  }
};
