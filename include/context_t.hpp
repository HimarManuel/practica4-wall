#pragma once

#include "wall_t.hpp"

#include <ctime>
#include <cmath>

#define MAX_WALLS 3000000

/* Clase entorno o contexto. Se encarga de generar todas las combinaciones posibles de muros*/
class context_t {
public: //Atributos publicos

  int H_; //Alto del muro
  int L_; //Ancho del muro
  int c_; //Contador de posibles combinaciones de muros

  vector<wall_t> walls_; //numero de muros posibles

private: //Atributos privados

  vector<row_t> rows_; //Numero de filas posibles
  vector<vector<int> > next_; //rows_[0] it's compatible with rows_[1] and rows_[2], if and only if next_[0] = {1,2}

public:
  context_t (int l, int h);
  ~context_t(void);

  void generate_walls (void); //Genera todos los muros posibles de L_xH_
  int posibilities (void); //Devuelve todos los muros que se han podido generar

  ostream& write_walls (void); //Imprime por pantalla todos los muros generados
  ostream& write_walls (ostream& os); //Imprime todos los muros generados en algun sitio pasado por parametro

private:
  void generate_rows (void); //Iniciador del metodo recursivo
  void generate_rows (row_t& row); //metodo recursivo que genera todas las filas posibles
  bool check (row_t& r1, row_t& r2);
  void next_rows (void); //Filas compatibles
  void create_walls (wall_t& wall, int i, int& z);
};
