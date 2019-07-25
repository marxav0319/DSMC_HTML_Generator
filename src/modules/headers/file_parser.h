/**
 * This file is part of the DSMC_HTML_Generator package.
 *
 * The header file for the FileParser class.  This class handles reading the input file and
 * populating a vector of Entry instances, which hold both the title and filepath of the html
 * snippet for each table of contents entry.
 *
 * Author: Mark Xavier
 */

#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>
#include <fstream>
#include <deque>

#include "entry.h"

class FileParser
{
public:
  /**
   * Parameterized constructor.
   *
   * Returns an instance of the FileParser class.  This parser is meant to read-in a .txt file of
   * appripriately created "Entry" instances, then stores those in an std::vector.
   *
   * @param inputFileName_ : The name of the input file as an std::string.
   */
  FileParser(std::string inputFileName_);

  /**
   * Closes the file opened by FileParser
   *
   * @return : void
   */
  void close();

  /**
   * Populates a vector of Entry* based on the input file.
   *
   * @param entriesList : An std::vector of Entry*, expected to be emtpy.
   * @return : void
   */
  void getEntries(std::deque<Entry*>& entriesList);
private:
  // Member Data
  std::string inputFileName;
  std::ifstream fileHandle;
};

#endif // FILEPARSER_H
