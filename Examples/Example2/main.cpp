#include "Files.h"
/*
The first step is to declare an object of type ProgressBar:

Parameter 1: Location of the file. A The object accepts tabbed and CSV TXT files. Carefully read the ExampleA.txt and ExampleB.csv files to learn how to create your files.
Parameter 2: To enable debug mode, type DEBUG in parameter 2. Otherwise, disregard this parameter.

Attention: The values in the table will be converted to float type!
*/
File ExampleA("ExampleA.txt", DEBUG);

int main(){
  //Checking the existence of the file...
  if (ExampleA.b_doesFileExist() == false){                                         // If the file does not exist ...
    return 0;                                                                       // The program will be stopped!
  }

  //Viewing file information
  printf("Informations:\n\n");
  printf("Name:               Example A\n");
  printf("Amount of Lines:    %d\n", ExampleA.ui32_getAmountOfLines());             //Getting amount of lines
  printf("Amount of Columns:  %d\n", ExampleA.ui32_getAmountOfColumns());           //Getting amount of columns
  printf("Amount of Values:   %d\n", ExampleA.ui32_getAmountOfValues());            //Getting amount of values
  printf("Size:               %d bytes\n", ExampleA.ui32_getSize());                //Getting size, in bytes

  //Viewing the ExampleA.txt file...
  printf("\nExample A:\n\n");
  printf(" %.2f    %.2f    %.2f    %.2f\n", ExampleA.f_file[0][0], ExampleA.f_file[0][1], ExampleA.f_file[0][2], ExampleA.f_file[0][3]);
  printf(" %.2f    %.2f    %.2f    %.2f\n", ExampleA.f_file[1][0], ExampleA.f_file[1][1], ExampleA.f_file[1][2], ExampleA.f_file[1][3]);
  printf("%.2f   %.2f   %.2f    %.2f\n", ExampleA.f_file[2][0], ExampleA.f_file[2][1], ExampleA.f_file[2][2], ExampleA.f_file[2][3]);

  //Modding the file
  ExampleA.f_file[0][0] = 0;
  ExampleA.f_file[0][1] = 0;
  ExampleA.f_file[0][2] = 0;
  ExampleA.f_file[0][3] = 0;

  //Viewing the ExampleA modded...
  printf("\nExample A (modded):\n\n");
  printf(" %.2f    %.2f    %.2f    %.2f\n", ExampleA.f_file[0][0], ExampleA.f_file[0][1], ExampleA.f_file[0][2], ExampleA.f_file[0][3]);
  printf(" %.2f    %.2f    %.2f    %.2f\n", ExampleA.f_file[1][0], ExampleA.f_file[1][1], ExampleA.f_file[1][2], ExampleA.f_file[1][3]);
  printf("%.2f   %.2f   %.2f    %.2f\n", ExampleA.f_file[2][0], ExampleA.f_file[2][1], ExampleA.f_file[2][2], ExampleA.f_file[2][3]);

  //Restoring  the ExampleA...
  ExampleA.restoreFile();

  //Viewing the restored ExampleA.txt file...
  printf("\nExample A (restored):\n\n");
  printf(" %.2f    %.2f    %.2f    %.2f\n", ExampleA.f_file[0][0], ExampleA.f_file[0][1], ExampleA.f_file[0][2], ExampleA.f_file[0][3]);
  printf(" %.2f    %.2f    %.2f    %.2f\n", ExampleA.f_file[1][0], ExampleA.f_file[1][1], ExampleA.f_file[1][2], ExampleA.f_file[1][3]);
  printf("%.2f   %.2f   %.2f    %.2f\n", ExampleA.f_file[2][0], ExampleA.f_file[2][1], ExampleA.f_file[2][2], ExampleA.f_file[2][3]);
  
  return 0;
}
