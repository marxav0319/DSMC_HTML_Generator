/**
 * To do
 *
 */

#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <fstream>
#include <vector>

#include "entry.h"

class FileWriter
{
public:
  // Constructor
  FileWriter(std::string);

  // Member methods
  void writeEntriesToFile(std::vector<Entry*>);
private:
  std::string outputFileName;
  std::ofstream fileHandle;
};

#endif // FILEWRITER_H