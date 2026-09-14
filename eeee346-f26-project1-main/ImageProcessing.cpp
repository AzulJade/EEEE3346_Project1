#include "ImageProcessing.h"
#include <iostream> // to use cout and cin
#include <cmath> // to use sqrt()

using namespace std;

// This is a reference function that copies the image from oData to rData.
// See how arrays are utilized.
void copyImage(int **oData, int **rData, int height, int width) {
  for (int j=0; j<height; j++) {
    for (int k=0; k<width; k++) {
      rData[j][k] = oData[j][k];
    }
  }
}

void histogramStretching(int **oData, int **rData, int height, int width) {
  // TODO: write your code
}

void btc(int **oData, int **rData, int height, int width) {
  // TODO: write your code
}

void edgeDetect(int **oData, int **rData, int height, int width) {
  // X-direction filter
  int Fx[3][3] = {{-1, 0, 1}, 
                  {-2, 0, 2},
                  {-1, 0, 1}};
  
  // Y-direction filter
  int Fy[3][3] = {{ 1,  2,  1}, 
                  { 0,  0,  0},
                  {-1, -2, -1}};

  // TODO: write your code
}
