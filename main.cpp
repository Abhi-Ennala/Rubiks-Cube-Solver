#include <bits/stdc++.h>
#include "Model/RubiksCube3dArray.cpp"
#include "Model/RubiksCube1dArray.cpp"
#include "Solver/BFSSolver.h"
#include "Solver/DFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Model/RubiksCube.cpp"

using namespace std;

int main(){
   RubiksCube3dArray cube;
   cube.print();

   vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
   for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
   cout << "\n";
   cube.print();

   DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
   vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();

   for (auto move: solve_moves) cout << cube.getMove(move) << " ";
   cout << "\n";
   dfsSolver.rubiksCube.print();
}