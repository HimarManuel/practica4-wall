#include "../include/wall_t.hpp"

wall_t::wall_t (void) {
  H_ = L_ = 0;
}

wall_t::wall_t (int l, int h) {
  //b2_ = b3_ = 0;
  H_ = h;
  L_ = l;

}

ostream& wall_t::write_section (ostream& os, vector<wall_section>& sections) {
  for (const wall_section section: sections) {
    cout << section.b3 << "," << section.b2 << "\n";
  }
}

/*ostream& wall_t::write (ostream& os) {

  int sum = 0;
  for (int i = v_.size()-1; i >= 0; i--) {
    if (i%L_ == 0) cout << "\n";
    if (v_[i] == 1) {
      cout << "[xx]";
      sum += 2;
    } else {
      cout << "[xxx]";
      sum +=3;
    }
  }
}

ostream& wall_t::write (ostream& os, vector<block_t>& v) {


  int sum = 0;
  for (int i = v.size()-1; i >= 0; i--) {
    if (sum%L_ == 0) cout << "\n";
    if (v[i] == 1) {
      cout << "[xx]";
      sum += 2;
    } else {
      cout << "[xxx]";
      sum +=3;
    }
  }
}*/

vector<wall_section> wall_t::combination_number_blocks (void) {
  wall_section section;
  vector<wall_section> aux;

  int combinaciones = 0;
  int dominantes = 0;

  for (int x = 0; x <= L_/3; x++) { //Representan los b3
    for (int y = 0; y <= L_/2; y++) { //Representan los b2
      if ((3*x + 2*y) == L_) {
        section.b3 = x;
        section.b2 = y;
        aux.push_back(section);
        //cout << x << "," << y << "\n";
        //create_section(section);
        //cout << section.b3 << "," << section.b2 << "\n";
        //cout << "\n";
        combinaciones++;
        if (section.b3 == 0 || section.b2 == 0) dominantes++;
      }
    }
  }
  muros_ = (combinaciones == dominantes ? combinaciones : (int)pow(combinaciones,H_));
  /*if (!aux.empty()) {
    cout << "Combinaciones totales: " << aux.size() << "\n";
    cout << "Muros totales: " << (int)pow(combinaciones_totales,H_) << "\n";
  } else {
    cout << "No hay combinaciones posibles." << "\n";
  }*/
  return aux;
}

void wall_t::create_section (wall_section s, block_t initial) {

  block_t buf = initial;
  int total = s.b3+s.b2;
  for (int i = 1; i <= total; i++) {
    if ((buf == 1 && s.b3 > 0) || (s.b3 > 0 && s.b2 <= 0)) {
      cout << "xxx|";
      s.b3--;
      buf = 0;
    } else if ((buf == 0 && s.b2 > 0) || (s.b2 > 0 && s.b3 <= 0)) {
      cout << "xx|";
      s.b2--;
      buf = 1;
    }
  }
}

void wall_t::create_wall (const vector<wall_section>& ws, int initial_value) {

  /*for (const wall_section section: ws) {
    create_section(section);
  }*/

  int j = initial_value;
  bool k = false;
  for (int i = 0; i < H_; i++) {
    if (j >= ws.size()) j = 0;
    create_section(ws[j++], k);
    k = !k;
    cout << "\n";
  }
}

void wall_t::create_wall (void) {
  vector<wall_section> aux = combination_number_blocks();
  for (int i = 0; i < muros_; i++) {
    cout << "Muro " << i+1 << ": " << "\n";
    create_wall(aux, i);

  }
}

int wall_t::combinations (void) {
  return muros_;
}
