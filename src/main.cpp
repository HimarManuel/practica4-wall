#include "../include/context_t.hpp"

unsigned tiempo0, tiempo1;

int main (void) {

  int L, H;

  cout << "Introduce un valor para L: ";
  cin >> L;
  cout << "Introduce un valor para H : ";
  cin >> H;

  tiempo0 = clock();

  context_t muros(L,H);

  muros.generate_walls();

  cout << "Combinaciones posibles: " << muros.posibilities() << "\n";
  tiempo1 = clock();

  cout << "Tiempo total: " << double(tiempo1-tiempo0)/CLOCKS_PER_SEC << "s\n";

  while(true) {
    char eleccion;
    cout << "¿Quieres imprimir todas las combinaciones posibles? (S/n): ";
    cin >> eleccion;

    if (eleccion == 'S' || eleccion == 's') {
      tiempo0 = clock();
      muros.write_walls();
      tiempo1 = clock();
      cout << "Tiempo total de impresion: " << double(tiempo1-tiempo0)/CLOCKS_PER_SEC << "s\n";
      break;
    } else if (eleccion == 'n' || eleccion == 'N') {
      break;
    } else {
      cerr << "Debes indicar con los descrito en los parentesis.\n";
    }
  }

}
