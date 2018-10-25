#include "../include/wall_t.hpp"

wall_t::wall_t (void) {
  H_ = L_ = 0;
}

wall_t::wall_t (int l, int h) {
  H_ = h;
  L_ = l;
  cout << H_ << "," << L_ << "\n";
}

int wall_t::total (vector<int>& v) {
  int sum = 0;
  for (const int p: v) {
    sum += p;
  }
  return sum;
}

ostream& wall_t::write_row (vector<int>& v) {
  for (const int p: v) {
    if (p == 2) { cout << "xx|"; } else { cout << "xxx|"; }
  }
  cout << "\n";
  return cout;
}

bool wall_t::check (vector<int>& v1, vector<int>& v2) {
  int i = 1, j = 1, cont1 = v1[0], cont2 = v2[0];

  while (i < v1.size() && j < v2.size()) {
    if (cont1 == cont2) { return false; }
    if (cont1 < cont2) {
      cont1 += v1[i++];
    } else if (cont1 > cont2) {
      cont2 += v2[j++];
    }
  }

  return true;
}

void wall_t::next_rows (void) {

vector<int> aux;

  for (int i = 0; i < rows_.size(); i++) {
    for (int j = 0; j < rows_.size(); j++) {
      if (check(rows_[i], rows_[j])) {
        aux.push_back(j);
      }
    }
    next_.push_back(aux);
    aux.clear();
  }
}

void wall_t::generate_rows (void) {
  vector<int> aux;
  generate_rows(aux);
}

void wall_t::generate_rows (vector<int>& row) {
  if (total(row) == L_) {
    rows_.push_back(row);
  } else if (total(row) < L_) {
    row.push_back(3);
    generate_rows(row);
    row.pop_back();
    row.push_back(2);
    generate_rows(row);
    row.pop_back();
  }
}

void wall_t::walls (void) {
  generate_rows();
  next_rows();
  vector<int> wall;

  cout << rows_.size() << "\n";

  for (int i = 0; i < rows_.size(); i++) {
    wall.push_back(i);
    create_walls(wall, i);
    wall.pop_back();
  }
  cout << "Combinaciones diferentes: " << walls_.size() << "\n";
}

void wall_t::write_wall (vector<int>& wall) {
  for (const int w: wall) {
    cout << "|";
    write_row(rows_[w]);
  }
  cout << "------------------------------------" << "\n";
}

void wall_t::create_walls (vector<int>& wall, int i) {
  if (wall.size() == H_) {
    walls_.push_back(wall);
    //cout << walls_.size() << "\n";
    write_wall(wall);
  } else {
    for (int k = 0; k < next_[i].size(); k++) {
      wall.push_back(next_[i][k]);
      create_walls(wall, next_[i][k]);
      wall.pop_back();
      }
  }
}
