#include "include/io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#ifdef _WIN32
size_t getline(char **lineptr, size_t *n, FILE *stream) 
{
    char *bufptr = NULL;
    char *p = bufptr;
    size_t size;
    int c;

    if (lineptr == NULL || stream == NULL || n == NULL) return -1;

    bufptr = *lineptr;
    size = *n;
    c = fgetc(stream);

    if (c == EOF)  return -1;

    if (bufptr == NULL) 
    {
        bufptr = malloc(128);
        if (bufptr == NULL) return -1;
        size = 128;
    }

    p = bufptr;
    while(c != EOF) 
    {
        if ((p - bufptr) > (size - 1))
        {
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL) return -1;
        }
        *p++ = c;
        if (c == '\n') break;
        c = fgetc(stream);
    }

    *p++ = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr - 1;
}
#endif

char* tac_read_file(const char* filename)
{
  FILE* fp;
  char* line = NULL;
  size_t len = 0;
  size_t read;

  fp = fopen(filename, "rb");
  if (fp == NULL)
  {
    printf("Could not read file `%s`\n", filename);
    exit(1);
  }

  char* buffer = (char*)calloc(1, sizeof(char));
  buffer[0] = '\0';

  while ((read = getline(&line, &len, fp)) != -1)
  {
    buffer = (char*)realloc(buffer, (strlen(buffer) + strlen(line) + 1) * sizeof(char));
    strcat(buffer, line);
  }

  fclose(fp);
  if (line)
    free(line);

  return buffer;
}
