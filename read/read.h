//header file to configure read.c to be imported, #include "read.h"
//this reads console

//imports
#include <stdbool.h>

//if guards to not let code be redefined
#ifndef readcode
#define readcode

//function headers
//reads stdin into "buffer[]"
void read_stdin(char buffer[], unsigned int read_depth, bool nonblocking);

//looks for if a key has been pressed
bool read_keybuff(char buffer[], unsigned int read_depth, char key);

#endif