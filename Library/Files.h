#ifndef Files_H
#define Files_H

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define   SEPARATION_CHARS  (c_charBuffer == 9 || c_charBuffer == 59 || c_charBuffer == 44)
#define   DEBUG             true

class File{
private:
  uint32_t ui32_columns;
  uint32_t ui32_lines;
  float **f_intactFile;
  bool b_flagFileExist;
public:
  float **f_file;
  File(const char *c_fileAdress);
  File(const char *c_fileAdress, bool b_flagDebug);
  ~File();
  bool b_doesFileExist();
  uint32_t ui32_getAmountOfLines();
  uint32_t ui32_getAmountOfColumns();
  uint32_t ui32_getAmountOfValues();
  uint32_t ui32_getSize();
  void restoreFile();
};

#endif
