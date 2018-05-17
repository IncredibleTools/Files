#include "Files.h"

void getRange(FILE *F_file, uint32_t *ui32_rangeLine, uint32_t *ui32_rangeColumn);
void getFile(FILE *F_file, float **f_fileBuffer);

File::File(const char *c_fileAdress){
  FILE *F_file;
  F_file = fopen(c_fileAdress, "r");
  uint32_t ui32_lineCounter = 0;
  if (F_file == NULL){
    b_flagFileExist = false;
    delete F_file;
    return;
  }
  b_flagFileExist = true;
  getRange(F_file, &this->ui32_lines, &this->ui32_columns);
  f_file = new float* [this->ui32_lines];
  f_intactFile = new float* [this->ui32_lines];
  while(ui32_lineCounter < this->ui32_lines){
    f_file[ui32_lineCounter] = new float [this->ui32_columns];
    f_intactFile[ui32_lineCounter] = new float [this->ui32_columns];
    ui32_lineCounter++;
  }
  getFile(F_file, f_file);
  getFile(F_file, f_intactFile);
  fclose(F_file);
}

File::File(const char *c_fileAdress, bool b_flagDebug){
  FILE *F_file;
  printf("==================================================\n");
  printf("File location: %s\n", c_fileAdress);
  printf("==================================================\n");
  printf("Opening file...\n");
  printf("--------------------------------------------------\n");
  F_file = fopen(c_fileAdress, "r");
  uint32_t ui32_lineCounter = 0;
  if (F_file == NULL){
    printf("--------------------------------------------------\n");
    printf("File doesn't exist!\n");
    printf("==================================================\n\n");
    b_flagFileExist = false;
    delete F_file;
    return;
  }
  b_flagFileExist = true;
  printf("Getting table size limits...\n");
  getRange(F_file, &this->ui32_lines, &this->ui32_columns);
  printf("Allocating memory...\n");
  f_file = new float* [this->ui32_lines];
  f_intactFile = new float* [this->ui32_lines];
  while(ui32_lineCounter < this->ui32_lines){
    f_file[ui32_lineCounter] = new float [this->ui32_columns];
    f_intactFile[ui32_lineCounter] = new float [this->ui32_columns];
    ui32_lineCounter++;
  }
  printf("Importing data from file...\n");
  getFile(F_file, f_file);
  printf("Backing up...\n");
  getFile(F_file, f_intactFile);
  printf("Closing file...\n");
  fclose(F_file);
  printf("--------------------------------------------------\n");
  printf("The file was imported successfully!\n");
  printf("==================================================\n\n");
}

File::~File(){
  if (b_flagFileExist == true){
      for (uint8_t ui32_counter = 0; ui32_counter < ui32_lines; ui32_counter++){
      delete f_file[ui32_counter];
      delete f_intactFile[ui32_counter];
    }
  }
  delete f_file;
  delete f_intactFile;
}

bool File::b_doesFileExist(){
  return this->b_flagFileExist;
}

void File::restoreFile(){
  uint32_t ui32_counterLines = 0;
  uint32_t ui32_counterColumns = 0;
  while(ui32_counterLines < this->ui32_lines){
    while(ui32_counterColumns < this->ui32_columns){
      this->f_file[ui32_counterLines][ui32_counterColumns] = this->f_intactFile[ui32_counterLines][ui32_counterColumns];
      ui32_counterColumns++;
    }
    ui32_counterColumns = 0;
    ui32_counterLines++;
  }
}

uint32_t File::ui32_getAmountOfLines(){
  return this->ui32_lines;
}

uint32_t File::ui32_getAmountOfColumns(){
  return this->ui32_columns;
}

uint32_t File::ui32_getAmountOfValues(){
  return this->ui32_columns*this->ui32_lines;
}

uint32_t File::ui32_getSize(){
  return sizeof(float)*this->ui32_lines*this->ui32_columns;
}

void getRange(FILE *F_file, uint32_t *ui32_rangeLine, uint32_t *ui32_rangeColumn){
  uint8_t ui8_machineState = 0;
  bool b_flagEndFile = false;
  bool b_endLine = false;
  char c_charBuffer = 0;
  *ui32_rangeLine = 0;
  *ui32_rangeColumn = 1;
  rewind(F_file);

  while(b_flagEndFile == false){
    switch(ui8_machineState){

    case 0:
      while(fgetc(F_file) != '#');
      while(fgetc(F_file) != 10);
      ui8_machineState = 1;
      break;

    case 1:
      c_charBuffer = fgetc(F_file);
      if (c_charBuffer == 10){
        b_endLine = true;
        *ui32_rangeLine = *ui32_rangeLine + 1;
      }
      else if (SEPARATION_CHARS && b_endLine == false){
        *ui32_rangeColumn = *ui32_rangeColumn + 1;
      }
      else if (c_charBuffer == '#'){
        b_flagEndFile = true;
      }
      break;

    }
  }
}

void getFile(FILE *F_file, float **f_fileBuffer){
  uint8_t ui8_machineState = 0;
  uint32_t ui32_fileLineCounter = 0;
  uint32_t ui32_fileColumnCounter = 0;
  char c_cellBuffer[50] = "";
  char c_charBuffer = 0;
  uint8_t ui8_counterBuffer = 0;
  rewind(F_file);
  while (ui8_machineState != 5){
    switch(ui8_machineState){

    case 0:
      while(fgetc(F_file) != '#');
      while(fgetc(F_file) != 10);
      ui8_machineState = 1;
      break;

    case 1:
      c_charBuffer = fgetc(F_file);
      if (SEPARATION_CHARS){ //TAB
        ui8_machineState = 2;
      }
      else if(c_charBuffer == 10){  //ENTER
        ui8_machineState = 3;
      }
      else if(c_charBuffer == '#' || feof(F_file)){
        ui8_machineState = 5;
      }
      else{
        ui8_machineState = 4;
      }
      break;

    case 2:
      f_fileBuffer[ui32_fileLineCounter][ui32_fileColumnCounter] = atof(c_cellBuffer);
      memset(c_cellBuffer, 0, sizeof(c_cellBuffer));
      ui8_counterBuffer = 0;
      ui32_fileColumnCounter++;
      ui8_machineState = 1;
      break;

    case 3:
      f_fileBuffer[ui32_fileLineCounter][ui32_fileColumnCounter] = atof(c_cellBuffer);
      memset(c_cellBuffer, 0, sizeof(c_cellBuffer));
      ui32_fileColumnCounter = 0;
      ui8_counterBuffer = 0;
      ui32_fileLineCounter++;
      ui8_machineState = 1;
      break;

    case 4:
      c_cellBuffer[ui8_counterBuffer] = c_charBuffer;
      ui8_counterBuffer++;
      ui8_machineState = 1;
      break;

    case 5:
      break;

    }
  }
}
