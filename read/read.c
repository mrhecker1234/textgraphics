//this reads console

//imports
#include <stdbool.h>
#include <conio.h>
#include <unistd.h>

//funcs
//reads stdin into "buffer[]"
void read_stdin(char buffer[], unsigned int read_depth, bool nonblocking)
{
  if(nonblocking)
  {
    for(unsigned int i = 0; i < read_depth; i++)
    {
      if(_kbhit())
      {
        //forcefully write enter key to stdin to force it to read whatever is in there (that key is 0x0D)
        char enter[2] = {0x0D, 0x00};
        write(STDIN_FILENO, enter, 2);
        buffer[i] = getch();
      } else {
        buffer[i] = 0x00;
      }
    }
  } else
  {
    read(STDIN_FILENO, buffer, read_depth);
  }
}

//looks for if a key has been pressed
bool read_keybuff(char buffer[], unsigned int read_depth, char key)
{
  for(unsigned int i = 0; i < read_depth; i++)
  {
    if(buffer[i] == key) return true;
  }

  return false;
}