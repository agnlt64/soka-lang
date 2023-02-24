#include "include/soka.h"

#include <stdio.h>

int main (int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("tac: error: no input files!\n");
    return -1;
  }
  soka_compile_file(argv[1]);

  return 0;
}
