#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE (512)

/* Reads input file(s) and outputs its content onto the screen. */
int main(int argc, char* argv[] ) {

for (int i=1; i<argc; i++) { //Deals with multiple input files
  FILE *fpointer = fopen(argv[i], "r");

  if (fpointer == NULL) {
    printf("my-cat: cannot open file\n");
    exit(1);
  }

  char buffer[BUFFER_SIZE]; // Buffer to store file content
  while (fgets(buffer, BUFFER_SIZE, fpointer) != NULL) {
    printf("%s", buffer); // Printing content to screen
  }

  fclose(fpointer);
}
  return(0);
}
