/**
 * The implementation of the FileParser class.
 */

#include "../headers/file_parser.h"

FileParser::FileParser(std::string inputFileName_, bool verbose_) : inputFileName(inputFileName_),
                                                                    verbose(verbose_)
{
  if(verbose)
    std::cout << "Opening Input File\n";
  fileHandle.open(inputFileName);
}

void FileParser::close()
{
  fileHandle.close();
}
