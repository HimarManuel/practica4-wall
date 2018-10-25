#include "../include/wall_t.hpp"

wall_t::wall_t (void) {
  H_ = L_ = 0;
}

wall_t::wall_t (int l, int h) {
  H_ = h;
  L_ = l;

  rows();

}

void wall_t::insert_row (int b3, int b2, vector<int>& row) {
  if (b3 > 0) {
    row.push_back(3);
    cout << 3 << ",";
    insert_row(b3-1, b2, row);
  } else if (b2 > 0){
    row.push_back(2);
    cout << 2 << ",";
    insert_row(b3, b2-1, row);
  }
}

void wall_t::generate_rows (vector<int>& row) {

  
}

void wall_t::row_combinations (vector<int>& row) {

}

int wall_t::rows (void) {
  vector<int> row;

  for (int x = 0; x <= L_/3; x++) {
    row.clear();
    for (int y = 0; y <= L_/2; y++) {
      if (3*x + 2*y == L_) {
        insert_row(x, y, row);
        r_.push_back(row);
        cout << "\n";
      }
    }
  }
}
