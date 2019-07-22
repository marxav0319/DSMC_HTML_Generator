/**
 * This file is part of the DSMC_HTML_Generator package.
 *
 * This file holds the implementation of the FileParser class.
 *
 * Author: Mark Xavier
 */

#include <iostream>
#include <sstream>

#include "../headers/file_parser.h"

// Open the input file
FileParser::FileParser(std::string inputFileName_, bool verbose_) : inputFileName(inputFileName_),
                                                                    verbose(verbose_)
{
  if(verbose)
    std::cout << "Opening Input File\n";
  fileHandle.open(inputFileName);
}

// Utility function to close the input file
void FileParser::close()
{
  fileHandle.close();
}

// This is where the heavy-lifting gets done
void FileParser::getEntries(std::deque<Entry*>& entriesList)
{
  // Variable setup
  std::string entry;
  int id = 0;
  std::string divName("dsmc_toc_id_");

  // Read in the file one line at a time
  while(!fileHandle.eof())
  {
    // Deal wih a few end of file conditions
    if(fileHandle.eof())
      break;

    std::getline(fileHandle, entry);
    if(entry.length() == 0)
      break;

    // Search for the PIPE delimiter and break the string apart
    std::size_t targetLocation = entry.find('|');
    std::string title = entry.substr(0, targetLocation - 1);
    std::string location = entry.substr(targetLocation + 2);

    // Convert the id number to an std::string
    std::stringstream ss;
    std::string idNumberString;
    ss << id;
    ss >> idNumberString;

    // Add the entry to the std::vector
    Entry* nextEntry = new Entry(title, location, divName + idNumberString);
    entriesList.push_back(nextEntry);
    id++;
  }

  fileHandle.close();
}
