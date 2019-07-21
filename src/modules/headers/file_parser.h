/**
 * The header file for the FileParser class.  This class will handle reading the input file which
 * should contain the table of contents structure in a pre-defined way.  This doc-string will
 * be updated once a plan of action has been selected.
 */

#include <string>
#include <fstream>

class FileParser
{
public:
  // Constructor
  FileParser(std::string, bool);

  // Member methods
  void close();
private:
  std::string inputFileName;
  std::ifstream fileHandle;
  verbose;
};