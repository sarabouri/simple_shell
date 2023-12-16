#include  "main.h"

char print(char *c){
     write(STDOUT_FILENO, c, sizeof(c) - 1);

}
