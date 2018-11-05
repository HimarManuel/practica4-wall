#pragma once

#include "block_t.hpp"
#include <vector>

class row_t {

private:
  vector<block_t> row_;
  int qblocks_; //Cantidad de bloques que hay en total
  int sz_; //tamaño total de la fila (unidades)

public:
  row_t (void) : sz_(0), qblocks_(-1), row_() {}
  row_t (int sz) : sz_(0), qblocks_(-1), row_(sz) {}

  ~row_t (void) {
    clear();
  }

  void insert (int num) { //insert at the end of the vector
    block_t aux (num);
    sz_ += num;
    qblocks_++;
    row_[qblocks_] = aux;
  }

  void rml (void) { //remove last element
    sz_ -= row_[qblocks_].block_size();
    qblocks_--;
  }

  void clear (void) {
    row_.clear();
    sz_ = 0;
    qblocks_ = -1;
  }

  const int at(int pos) { //Devuelve el tamaño de un bloque concreto

    assert(pos >= 0 && pos <= qblocks_);
    return row_[pos].block_size();
  }

  int blocks (void) { //Indica el numero total de bloques
    return qblocks_+1;
  }

  const int sz (void) { //Indica el tamaño total de la fila (unidades)
    return sz_;
  }

  ostream& write (ostream& os) {
    for (int i = 0; i < blocks(); i++) {
      if (row_[i].block_size() == 2) { os << "xx|"; } else { os << "xxx|"; }
    }
    os << "\n";
    return os;
  }

  ostream& write (void) {
    cout << '|';
    for (int i = 0; i < blocks(); i++) {
      row_[i].write();
    }
    return cout;
  }

  int operator[] (int pos) {
    return at(pos);
  }

};
