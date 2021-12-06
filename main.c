//basic imports
#include <unistd.h>
#include <stdbool.h>

//custom imports
#include "render/render.h"
#include "read/read.h"

//consts / global vars
const BYTE width = 32;
const BYTE height = 32;
BYTE fps = 2;
bool running = true;

//function that runs every frame to run game, game loop
void tick(PIXEL display[], char keyboard[], BYTE w, BYTE h)
{
  static unsigned int ticks = 0;
  static PIXEL canvas_mem[32 * 32];
  static float cursor_x = 0;
  static float cursor_y = 0;
  static BYTE cursor_pps = 1;
  static BYTE color = 0;

  //beginning
  if(!ticks)
  {
    initialize_display(width, height, canvas_mem);
  }

  //code
  if(read_keybuff(keyboard, 4, 'w')) cursor_y = cursor_y - (float)cursor_pps / (float)fps;
  if(read_keybuff(keyboard, 4, 'a')) cursor_x = cursor_x - (float)cursor_pps / (float)fps;
  if(read_keybuff(keyboard, 4, 's')) cursor_y = cursor_y + (float)cursor_pps / (float)fps;
  if(read_keybuff(keyboard, 4, 'd')) cursor_x = cursor_x + (float)cursor_pps / (float)fps;
  if(read_keybuff(keyboard, 4, 'e')) pixel(width, height, cursor_x, cursor_y, (PIXEL){color}, canvas_mem);
  if(read_keybuff(keyboard, 4, '+')) color++;
  if(read_keybuff(keyboard, 4, '-')) color--;

  for(unsigned int i = 0; i < display_size(width, height); i++)
  {
    display[i] = canvas_mem[i];
  }

  pixel(width, height, cursor_x, cursor_y, (PIXEL){color}, display);

  ticks++;
}

//driver func
int main(void) {
  //allocates array of PIXEL, char, of "display_size" bytes
  PIXEL display[display_size(width, height)];
  //allocates array of key presses, stores them in array to be read
  char keyboard[4];

  //main part of game loop
  while(running)
  {
    //safety check fps to not divide by 0
    if(!fps) {
      fps = 1;
    }
    //val to calculate time elapsed for code to run
    unsigned int msbef = return_ms();
    //reads keyboard
    read_stdin(keyboard, 4, true);
    //sets up display to be an array of " "'s w/ /n to cause newlines of chars
    initialize_display(width, height, display);
    //runs tick func
    tick(display, keyboard, width, height);
    // printf's screen
    render_screen(width, height, display);
    //val to also calculate that
    unsigned int msaft = return_ms();
    //delays program x ms to make tick run every fps time per second
    if(1000 / fps > /*gets diff between when code started to run and when it stopped to subtract that time from delay so it runs at exactly x fps*/ msaft - msbef)
    {
      delay_ms(1000 / fps - (msaft - msbef));
      fps++;
    } else {
      fps--;
    }
  }
  
  //exit program
  return 0;
}
