#pragma once

#include <iostream>

#include <vector>
#include <cmath>

using namespace std;

typedef unsigned short block_t; //Tipo de bloque Si es 1 se trata de un b2,
                                //si es 0 se trata de un b3

typedef struct {
  int b2; //numero de bloques de 2x1
  int b3; //numero de bloques de 3x1
} wall_section; //Una fila del muro

class wall_t {
private:
  //int b2_; //Numero de bloques de 2x1
  //int b3_; //Numero de bloques de 3x1

  int H_; //Altura del muro
  int L_; //Anchura del muro

  int muros_; //Numero de muros posibles

public:

  wall_t (void); //Constructor por defecto
  wall_t (int l, int h);

  ostream& write (ostream& os);
  ostream& write_section (ostream& os, vector<wall_section>& sections);
  ostream& write (ostream& os, vector<block_t>& v);

  void create_wall (void);
  int combinations (void);

private:
  vector<wall_section> combination_number_blocks (void); //Calcula el numero de combinaciones posibles para una sola fila
  void create_section (wall_section s, block_t initial);
  void create_wall (const vector<wall_section>& ws, int initial_value);
};
