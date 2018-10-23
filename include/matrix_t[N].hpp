#include <iostream>

using namespace std;

template <class T>
class matrix_t {

private:

  T* v_;
  int m_; //Fila
  int n_; //Columna

private:
  void clear (void) {
    delete [] v_;
    v_ = NULL;
  }

  void redimensionar ()

public:

  //Constructores
  matrix_t (void) : v_(NULL), m_(0), n_(0) {}
  matrix_t (int m, int n) : v_(NULL), m_(m), n_(n) {
    v_ = new T [m*n];
  }
  matrix_t (matrix_t& M) : v_(NULL), m_(sz_m()), n_(sz_n()) {

    clear();

    redimensionar(m_, n_);

    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {

        v_[pos(i,j)] = M(i,j); //Incluir metodo pos(i,j) y operator()
      }
    }
  }

};
