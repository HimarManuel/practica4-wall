#include "../include/wall_t.hpp"

int main (void) {

  int L, H;

  cout << "Introduce un valor para L: ";
  cin >> L;
  cout << "Introduce un valor para H : ";
  cin >> H;

  tiempo0 = clock();

  wall_t wall(L,H);

  vector<int> aux;

  wall.walls();

  tiempo1 = clock();

  cout << "Tiempo total: " << double(tiempo1-tiempo0)/CLOCKS_PER_SEC << "s\n";
}
