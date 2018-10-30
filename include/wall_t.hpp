#pragma once

#include <iostream>

#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

unsigned tiempo0, tiempo1;

class wall_t {
private:

  int H_; //Altura del muro
  int L_; //Anchura del muro

  vector<vector<int> > rows_; //Numero de filas posibles
  vector<vector<int> > next_; //rows_[0] it's compatible with rows_[1] and rows_[2], if and only if next_[0] = {1,2}
  vector<vector<int> > walls_; //numero de muros posibles

public:

  wall_t (void); //Constructor por defecto
  wall_t (int l, int h);
  ostream& write_row (vector<int>& v);
  void write_wall (vector<int>& wall);
  void walls (void);
  //const vector<vector<int> > get_rows (void);

private:
  void next_rows (void);
  void generate_rows (void);
  void generate_rows (vector<int>& row);
  int total (vector<int>& v);
  bool check (vector<int>& v1, vector<int>& v2);
  void create_walls (vector<int>& wall, int i);
};
