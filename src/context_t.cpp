#include "../include/context_t.hpp"

unsigned tiempo2, tiempo3; //Variables de medida de tiempo

/*METODOS PUBLICOS*///////////////////////////////////////////////////////////////////////////////////

context_t::context_t (int l, int h) : L_(l), H_(h), walls_(), rows_(), next_(), c_(0) {}

context_t::~context_t (void) {
  walls_.clear();
  rows_.clear();
  next_.clear();
}

void context_t::generate_walls (void) {


  if (L_ < 2 || H_ < 1) { cerr << "Error. No se pueden calcular muros de tamaño " << H_ << "x" << L_ << "\n"; return; }

  cout << "GENERANDO FILAS...\n";
  tiempo2 = clock();
  generate_rows();
  tiempo3 = clock();
  cout << "FILAS GENERADAS... " << double(tiempo3-tiempo2)/CLOCKS_PER_SEC << "\n";
  cout << "Filas totales generadas: " << rows_.size() << "\n";

  cout << "BUSCANDO FILAS COMPATIBLES...\n";
  tiempo2 = clock();
  next_rows();
  tiempo3 = clock();
  cout << "FILAS COMPATIBLES ENCONTRADAS... " << double(tiempo3-tiempo2)/CLOCKS_PER_SEC << "\n";

  tiempo2 = clock();
  wall_t wall(H_);
  walls_.resize(MAX_WALLS);
  int z = 0;
  for (int i = 0; i < rows_.size(); i++) {
    wall.insert_row(rows_[i]);
    create_walls(wall, i, z);
    wall.remove_row();
  }
  tiempo3 = clock();

  cout << "TODOS LOS MUROS IMPRESOS... " << double(tiempo3-tiempo2)/CLOCKS_PER_SEC << "\n";
}

int context_t::posibilities (void) {
  return c_;
}

ostream& context_t::write_walls (void) {
  assert(!walls_.empty());
  for (int i = 0; i < c_; i++) {
    walls_[i].write();
    cout << "\n";
    if (i >= MAX_WALLS) break;
  }
  return cout;
}

ostream& context_t::write_walls (ostream& os) {
  assert(!walls_.empty());
  for (int i = 0; i < c_; i++) {
    walls_[i].write(os);
    os << "\n";
    if (i >= MAX_WALLS) break;
  }
  return os;
}

/*METODOS PRIVADOS*////////////////////////////////////////////////////////////////////////

void context_t::generate_rows (void) {
  row_t aux(L_); //fila auxiliar
  generate_rows(aux);
}

void context_t::generate_rows (row_t& row) {

  if (row.sz() == L_) {
    rows_.push_back(row);
  } else if (row.sz() < L_) {
    row.insert(3);
    generate_rows(row);
    row.rml();
    row.insert(2);
    generate_rows(row);
    row.rml();
  }
}

bool context_t::check (row_t& r1, row_t& r2) {
  int i = 1, j = 1, cont1 = r1[0], cont2 = r2[0];

  while (i < r1.blocks() && j < r2.blocks()) {
    if (cont1 == cont2) { return false; }
    if (cont1 < cont2) {
      cont1 += r1[i++];
    } else if (cont1 > cont2) {
      cont2 += r2[j++];
    }
  }
  return true;
}

void context_t::next_rows (void) {

  next_.resize(rows_.size());
  vector<int> aux;

  for (int i = 0; i < rows_.size(); i++) {
    for (int j = 0; j < rows_.size(); j++) {
      if (i == j && (L_ != 2 || L_ != 3)) { continue; }
      if (check(rows_[i], rows_[j])) {
        aux.push_back(j);
      }
    }
    next_[i] = aux;
    aux.clear();
  }
}

void context_t::create_walls (wall_t& wall, int i, int& z) {
  if (wall.heigh() == H_) {
    c_++;
    if (z < walls_.size()) { walls_[z++] = wall; }
  } else {
    for (int k = 0; k < next_[i].size(); k++) {
      wall.insert_row(rows_[next_[i][k]]);
      create_walls(wall, next_[i][k], z);
      wall.remove_row();
      }
  }
}
