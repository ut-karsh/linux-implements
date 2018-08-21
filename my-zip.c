#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(char input);

char checker = '\0';
int count = 0;
/* Main function:
 * Primarily opens file pointer, reads character, and passes to check.
 */
int main(int argc, char* argv[] ) {

  int int_char; //Integer ascii value of characters

  // Handling wrong execution case
  if (argc <= 1) {
    printf ("my-zip: file1 [file2 ...]\n");
    exit(1);
  }

  for (int i=1; i<argc; i++) {

    FILE *f_pointer = fopen(argv[i], "rb");

    if (f_pointer == NULL) {
      printf("my-zip: cannot open file\n");
      exit(1);
    }

    //Extracts character from pointer and passes it to check()
    while ((int_char = fgetc(f_pointer)) != EOF) { check((char)int_char); }

    fclose(f_pointer);
  }
  //Outputs last data which could not be written due to while loop terminaton.
  fwrite(&count, sizeof(int), 1, stdout);
  fprintf(stdout, "%c", checker);
  return(0);
}

/* Checks if input character is same as previous character.
 * If it is then count is incremented.
 * If not, previous character's output is written and new character becomes checker.
 */
void check(char input) {

  if(input == checker) { count++; }
  else{
    if(count > 0) {
      fwrite(&count, sizeof(int), 1, stdout);
      fprintf(stdout, "%c", checker);
    }
    checker = input;
    count = 1;
  }
}
