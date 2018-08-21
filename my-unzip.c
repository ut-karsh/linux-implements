#include <stdio.h>
#include <stdlib.h>

/* Uncompresses data from input file encoded in RLE and prints it to screen.*/
int main(int argc, char* argv[] ) {

  size_t file_size; //Total length of files
  int repeat_num = 0; //Number of repetitions of character

  //Deals with wrong execution
  if (argc <= 1) {
    printf ("my-unzip: file1 [file2 ...]\n");
    exit(1);
  }

  //This loop primarily calculates total length of files for buffer size
  for (int i=1; i<argc; i++) {

    FILE *file_pointer = fopen(argv[i], "rb");

    if (file_pointer == NULL) {
      printf("my-zip: cannot open file\n");
      exit(1);
    }
    /* Calculating size of files for buffer*/
    fseek(file_pointer, 0, SEEK_END);
    file_size += ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);

    fclose(file_pointer);
  }
  //This loop unzips each file from RLE to normal text
  for (int i=1; i<argc; i++) {

    FILE *fpointer = fopen(argv[i], "rb");

    if (fpointer == NULL) {
      printf("my-zip: cannot open file\n");
      exit(1);
    }
    //First reading integer number of repititions, hence size 4
    while ((fread(&repeat_num, 1, 4, fpointer)) != 0 ) {
      char c;
      fread(&c, 1, 1, fpointer); //Reading character from file stream

      for (int i=0; i<repeat_num; i++) {
        printf("%c", c); //Printing chaacter repeated number of times
      }
    }

    fclose(fpointer);
  }

  return(0);
}
