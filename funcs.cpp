
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

#include "imageio.h"

void invert(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"

  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) 
  {
    for(int col = 0; col < w; col++) 
    {

      out[row][col] = 255-img[row][col];
    }
  }
  writeImage("taskA.pgm",out, h, w);
  return ;
}
void invert_half(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;


  readImage(input, img, h, w);

  int out[MAX_H][MAX_W];
  int midpoint = h/2;
  std::cout << midpoint << std::endl;  
  for(int row = 0; row < h; row++) 
  {
    for(int col = 0; col < w; col++) 
    {
      if (col >= midpoint) 
      {
        out[row][col] = 255-img[row][col];
      }
      else {
        out[row][col] = img[row][col];
      }
    }
  }
  writeImage("taskB.pgm",out, h, w);
  return; 
}
