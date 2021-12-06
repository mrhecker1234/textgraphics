//renders display

//imports
#include <time.h>
#include <stdio.h>
#include "render.h"

//private helper function
unsigned int return_ms()
{
  return (float)clock() / (float)CLOCKS_PER_SEC * 1000;
}

//returns proper bytes to allocate to the display's pixel array
unsigned short display_size(BYTE width, BYTE height)
{
  return width * height;
}

//sets up display to be a grid of pxls
void initialize_display(BYTE width, BYTE height, PIXEL display[])
{ 
  //initialize pixels to be blue
  for(unsigned short i = 0; i < display_size(width, height); i++)
  {
    display[i] = (PIXEL){4};
  }
}

//puts pixel on screen
void pixel(BYTE width, BYTE height, BYTE x, BYTE y, PIXEL pixel, PIXEL display[])
{
  unsigned short display_array_pixel_index = x % width + (y % height) * width;
  display[display_array_pixel_index] = pixel;
}

//print screen
void render_screen(BYTE width, BYTE height, PIXEL display[])
{
  //clear screen
  printf("\x1b[2J\x1b[0;0H");
  //print screen
  unsigned int index = 0;
  for(unsigned int i = 0; i < height; i++)
  {
    for(unsigned int j = 0; j < width; j++)
    {
      printf("\x1b[48;5;%um  ", display[index].code);
      index++;
    }
    printf("\n");
  }
  printf("\x1b[0m");
}

//delay program x ms
void delay_ms(unsigned int ms)
{
  unsigned int ms_bef = return_ms();

  while(return_ms() - ms_bef < ms)
  {
    //do nothing but stall thread
  }
}