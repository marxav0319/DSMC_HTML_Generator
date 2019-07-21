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
  void writeOutput(std::vector<Entry*> entries);
private:
  std::string outputFileName;
  std::ofstream fileHandle;

  // Member methods
  void writeTableOfContents(std::vector<Entry*>);
  void writeBody(std::vector<Entry*>);
  void writeFileContents(std::string);
};

#endif // FILEWRITER_H