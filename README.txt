@author: Utkarsh Maheshwari
@login: maheshwari
In this project we make 4 files, emulating standard Unix commands:
my-cat: Emulates the 'cat' command. Reads input file(s) and outputs their content onto the screen.
my-grep: Emulates the 'grep' command. Performs Grep corresponding to type of input stream.  Grep is a search technique which prints out the line in a file containing the required search term.
my-zip: Emulates the 'zip' command. This program encodes input files into a Run Length Encoding (RLE) format, thus helping reduce size of file in multiple instances. This file's primary method is the check() method. This method checks if input character is same as previous character. If it is then count is incremented. If not, previous character's output is written and new character becomes checker. This method performs RLE in a very efficient manner.
my-unzip: Emulates the 'unzip' command. This program uncompresses data from input file encoded in RLE and prints it to the screen according to the number of repetitions of each character.