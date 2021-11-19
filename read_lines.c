#include <stdio.h>
#include <stdlib.h>
#include "read_lines.h"

void read_lines(FILE* fp, char*** lines, int* num_lines) {
    char character;
    int count = 0;
    *num_lines = 0;
    allocate_space(fp, lines, num_lines);
    character = fgetc(fp);
    while (!feof(fp)) {
      (*lines)[*num_lines] = (char*)realloc((*lines)[*num_lines], (count + 1) * sizeof(char));
      if (character == '\n') {
        (*lines)[*num_lines] = (char*)realloc((*lines)[*num_lines], (count + 2) * sizeof(char));
        (*lines)[*num_lines][count] = '\n';
        (*lines)[*num_lines][count + 1] = '\0';
        *num_lines += 1;
        *lines = (char**)realloc(*lines, (*num_lines + 1) * sizeof(char*));
        (*lines)[*num_lines] = (char*)malloc(sizeof(char));
        count = 0;
        character = fgetc(fp);
      } else {
        (*lines)[*num_lines][count] = character;
        count += 1;
        character = fgetc(fp);
    }
  }
}

void allocate_space(FILE* fp, char*** lines, int* num_lines) {
  *lines = (char**)malloc(sizeof(char*));
  (*lines)[*num_lines] = (char*)malloc(sizeof(char));
}
