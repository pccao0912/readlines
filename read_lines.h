
#ifndef READ_LINES
#define READ_LINES
#include <stdio.h>

  void allocate_space(FILE* fp, char*** lines, int* num_lines);
	void read_lines(FILE* fp, char*** lines, int* num_lines);
#endif
