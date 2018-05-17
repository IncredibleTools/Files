#include "Files.h"
/*
The first step is to declare an object of type ProgressBar:

Parameter 1: Location of the file. A The object accepts tabbed and CSV TXT files. Carefully read the ExampleA.txt and ExampleB.csv files to learn how to create your files.
Parameter 2: To enable debug mode, type DEBUG in parameter 2. Otherwise, disregard this parameter.

Attention: The values in the table will be converted to float type!
*/
File ExampleA("ExampleA.txt");
File ExampleB("ExampleB.csv", DEBUG);

int main(){
  //Checking the existence of the file...
  if (ExampleA.b_doesFileExist() == false || ExampleB.b_doesFileExist() == false){  // If the file does not exist ...
    return 0;                                                                       // The program will be stopped!
  }

  //Viewing the ExampleA.txt file...
  printf("Example A:\n\n");
  printf(" %.2f    %.2f    %.2f    %.2f\n", ExampleA.f_file[0][0], ExampleA.f_file[0][1], ExampleA.f_file[0][2], ExampleA.f_file[0][3]);
  printf(" %.2f    %.2f    %.2f    %.2f\n", ExampleA.f_file[1][0], ExampleA.f_file[1][1], ExampleA.f_file[1][2], ExampleA.f_file[1][3]);
  printf("%.2f   %.2f   %.2f    %.2f\n", ExampleA.f_file[2][0], ExampleA.f_file[2][1], ExampleA.f_file[2][2], ExampleA.f_file[2][3]);

  //Viewing the ExampleB.csv file...
  printf("\nExample B:\n\n");
  printf(" %.2f    %.2f     %.2f    %.2f\n", ExampleB.f_file[0][0], ExampleB.f_file[0][1], ExampleB.f_file[0][2], ExampleB.f_file[0][3]);
  printf(" %.2f    %.2f    %.2f    %.2f\n", ExampleB.f_file[1][0], ExampleB.f_file[1][1], ExampleB.f_file[1][2], ExampleB.f_file[1][3]);
  printf("%.2f  %.2f    %.2f    %.2f\n", ExampleB.f_file[2][0], ExampleB.f_file[2][1], ExampleB.f_file[2][2], ExampleB.f_file[2][3]);
  return 0;
}
