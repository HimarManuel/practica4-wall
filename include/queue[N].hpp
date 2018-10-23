#pragma once

#include <iostream>

using namespace std;

template <class T>
class queue_v_t {
private:
  T* v_; //Vector que almacena la pila de datos
  int top; //Marca el tope de la pila

public:
  queue_v_t(void) : v_(NULL), top(-1) {} //Constructor por defecto

  void push (const T value) {
    if (top == -1)
  }
};
