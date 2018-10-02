int queens[]; // queens[i] = j mean a queen is put at (i, j)

bool can_attack_each_other(int u, int v, int i, int j) {
  if (u == i) {
    return true; //same row
  }
  if (v == j) {
    return true; // same column
  }
  if (abs(u - i) == abs(v - j)) {
    return true; // same diagonal
  }
  return false;
}

bool can_put_queen_at(int row, int col) {
  for(int i = 0; i < row; ++i) {
    //for each previously put queen
    if (can_attack_each_other(row, col, i, queens[i])) {
      return false;
    }
  }
  reutrn true;
}

void nQueen(int row) {
  if (row >= N) {
    //print
    return;
  }
  
  for(int col = 0; col < N; ++col) {
    if (can_put_queen_at(row, col)) {
      queens[row] = col;
      nQueen(row + 1);
    }
  }
  
}