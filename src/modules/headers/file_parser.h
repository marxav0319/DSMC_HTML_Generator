/**
 * The header file for the FileParser class.  This class will handle reading the input file which
 * should contain the table of contents structure in a pre-defined way.  This doc-string will
 * be updated once a plan of action has been selected.
 */

#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>
#include <fstream>
#include <vector>

#include "entry.h"

class FileParser
{
public:
  // Constructor
  FileParser(std::string, bool);

  // Member methods
  void close();
  void getEntries(std::vector<Entry*>&);
private:
  std::string inputFileName;
  std::ifstream fileHandle;
  bool verbose;
};

#endif // FILEPARSER_H
