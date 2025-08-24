#include "RubiksCube.h"


class RubiksCube3dArray : public RubiksCube {
private:
  
  void rotateFace(int ind){
    char temp_arr[3][3] = {};
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        temp_arr[i][j] = cube[ind][i][j];
      }
    }
    for(int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
    for(int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
    for(int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
    for(int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
  }

public:
  char cube[6][3][3]{};

  RubiksCube3dArray() {
    for(int i = 0; i < 6; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          cube[i][j][k] = getColorLetter(COLOR(i));
        }
      }
    }
  }

  COLOR getColor(FACE face, unsigned row, unsigned col) const override {
    char color = cube[int(face)][row][col];
    switch (color) {
      case 'B':
        return COLOR::BLUE;
      case 'R':
        return COLOR::RED;
      case 'G':
        return COLOR::GREEN;
      case 'O':
        return COLOR::ORANGE;
      case 'Y':
        return COLOR::YELLOW;
      default:
        return COLOR::WHITE;
    }
  }
   bool isSolved() const override {
      for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
          for (int k = 0; k < 3; k++) {
            if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
            return false;
          }
        }
      }
      return true;
    }
};