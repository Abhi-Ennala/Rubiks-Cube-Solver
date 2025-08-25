#include <bits/stdc++.h>
#include "Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "Solver/BFSSolver.h"
#include "Model/RubiksCube.cpp"

using namespace std;

int main(){
  RubiksCube1dArray cube1;

  // vector<RubiksCube::MOVE> shuffle_moves = cube1.randomShuffleCube(5);
  // for(auto move: shuffle_moves) cout << cube1.getMove(move) << " ";
  // cout << "\n";
  cube1.b();
  cube1.u();
  cube1.f();
  cube1.d();
  cube1.b();
  cube1.print();

  BFSSolver<RubiksCube1dArray, Hash1d> bfsSolver(cube1);
  vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();

  for(auto move : solve_moves) cout << cube1.getMove(move) << " ";
  cout << "\n";

  bfsSolver.rubiksCube.print();
}