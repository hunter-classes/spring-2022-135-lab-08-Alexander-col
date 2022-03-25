
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
  std::cout << "taskA.pgm, was created" << std::endl;

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
  // std::cout << midpoint << std::endl;  
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
  std::cout << "taskB.pgm, was created" << std::endl;

  return; 
}
// Write a program box.cpp that draws a white box exactly in the middle of the picture. The dimensions of the box should be 50% by 50% of the original picture’s width and height
void box(std::string filename)
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
      if ((row < h*3/4) && (row > h/4) && (col > w/4) && (col < w*3/4)) // should stay portional to whatever png image is given
      {
        out[row][col] = 255; // this will assure that the values in these area are all blank with the value of 255
      }
      else 
      {
        out[row][col] = img[row][col];
      }
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("taskC.pgm",out, h, w);
  std::cout << "taskC.pgm, was created" << std::endl;

  return;
}

void frame(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  
  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      if ((row <= h*3/4 && row >= h/4 && col >= w/4 && col <= w*3/4) && (row == h*3/4 || row == h/4 || col == w/4 || col == w*3/4)) // same measurments are the white box task 
      {
        out[row][col] = 255;
      }
      else 
      {
        out[row][col] = img[row][col];
      }
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("taskD.pgm",out, h, w);
    std::cout << "taskD.pgm, was created" << std::endl;

  return;
}

void pixelate(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;
  int total;
  int avg;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"

  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row += 2) 
  {
    for(int col = 0; col < w; col += 2) 
    {
      total = img[row][col] + img[row+1][col] + img[row][col+1] + img[row+1][col+1]; //average of groups of four are found and set as that
      avg = total / 4;
      out[row][col] = avg;
      out[row+1][col] = avg;
      out[row][col+1] = avg;
      out[row+1][col+1] = avg;
    }
  }
  std::string newfilename = "taskF.pgm";
  writeImage(newfilename,out, h, w);
  std::cout << "taskF.pgm, was created" << std::endl;
  return;
}