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
  cout << height << endl;
  cout << "hello" <<endl;
  cout << width <<endl;
  int Ry = height/4;
  int Rx = width/4;
  int j; // counter for image height index
  int k; // counter for image width index
  // --------
  int o; // counter for cell height
  int p; // counter for cell width
  int cell_avg = 0;
  int cell_array [4] [4];
  int low_level_avg = 0;
  int low_level_count = 0;
  int high_level_avg = 0;
  int high_level_count = 0;
  for (j = 0; j < height; j = j+4) // gets the height of the image cell we work on
  {
    for (k = 0; k < width; k = k+4) // gets the width of the image cell we work on 
    {
      for (o = j; o<(j+4);o++) // this for loop add up all the cell data
      {
        for (p=k; p <(k+4);p++)
        {
          cell_avg = cell_avg + oData[p][o]; 
        }
      }
      
      cell_avg = cell_avg/16 ; // finding the average of all 16 cells

      for (o = j; o<(j+4);o++) // this for loop compares all the data in the cell against cell_avg  
      {
        for (p=k; p <(k+4);p++)
        {
          if (oData[p][o] >= cell_avg) // if the data in the cell is equal to or greater than the average
          {
            rData[p][o] = 1; // read data is set to 1
            high_level_avg = high_level_avg + oData[p][o]; // add the data in the cell to a High Level Sum
            high_level_count++; // increment counter by 1
          }
          else
          {
            rData[p][o] = 0; // read data is set to 0
            low_level_avg = low_level_avg + oData[p][o]; // add the data in the cell to a Low Level Sum
            low_level_count++; // increment counter by 1
          }
        }
      }

      high_level_avg = high_level_avg/high_level_count; // find the average of the high level sums
      low_level_avg = low_level_avg/low_level_count; // find the average of the low level sums

      for (o = j; o<(j+4);o++) // for loop to set the high and low level avgs
      {
        for (p=k; p <(k+4);p++)
        {
          if(rData[p][o] == 1) // if the data has a 1 
          {
            rData[p][o] = high_level_avg; // set the high level average 
          }
          else // if the data has a 0 
          {
            rData[p][o] = low_level_avg; // set the low level average 
          }
        }
      }

      high_level_count = 0; // resets high level count
      low_level_count = 0; // resets low level count
      high_level_avg = 0; // resets high level average
      low_level_avg = 0; // resetes low level average
      cell_avg = 0; // resets the cell average 
    }
  }
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
