//configures render functions to be imported

//if guard to not redefine code
#ifndef render
#define render

//imports

//types
typedef unsigned char BYTE;
struct _PIXEL
{
    BYTE code;
};
typedef struct _PIXEL PIXEL;

//function headers
//returns ms passed
unsigned int return_ms();

//returns proper bytes to allocate to the display's pixel array
unsigned short display_size(BYTE width, BYTE height);

//sets up display to be a grid of squares w/ newlines
void initialize_display(BYTE width, BYTE height, PIXEL display[]);

//puts pixel on screen
void pixel(BYTE width, BYTE height, BYTE x, BYTE y, PIXEL pixel, PIXEL display[]);

//print screen
void render_screen(BYTE width, BYTE height, PIXEL display[]);

//delay program x ms
void delay_ms(unsigned int ms);

#endif