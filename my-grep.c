#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Performs Grep corresponding to type of input stream.
* Grep is a search technique which prints out the line in a file containing
* required search term.
*/
int main(int argc, char* argv[] ) {

  char* search; //Search term

  //Prints default output if not enough input parameters.
  if (argc <= 1) {
    printf ("my-grep: searchterm [file ...]\n");
    exit(1);
  }

  //Enables use of standard input for grep if no input file is mentioned.
  if (argc == 2) {
    search = argv[1];
    size_t buffer_size = 512;
    char* buffer = malloc(buffer_size);
    // Gets input line
    while((getline(&buffer, &buffer_size, stdin))!=EOF) {
      // Prints line if search term is found in it
      if((strstr(buffer, search)) != NULL) {
        printf("%s", buffer);
      }
    }
  }

  if (argc > 2) {

    search = argv[1];
  }
  for (int i=2; i<argc; i++) {
    //File pointer for input files
    FILE *fpointer = fopen(argv[i], "r");

    if (fpointer == NULL) { //Error handling file pointers.
      printf("my-grep: cannot open file\n");
      exit(1);
    }

    size_t buffer_size = 512;
    char* buffer = malloc(buffer_size);

    //Stores individual lines to be processed in buffer.
    while((getline (&buffer,&buffer_size, fpointer)) != EOF) {

      // Prints line if search term is found in it.
      if((strstr(buffer, search)) != NULL) {
        printf("%s", buffer);
      }
    }
    fclose(fpointer);
  }
  return(0);
}
