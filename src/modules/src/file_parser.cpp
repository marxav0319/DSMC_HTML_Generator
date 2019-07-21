/**
 * The implementation of the FileParser class.
 *
 * Author: Mark Xavier
 */

#include <iostream>

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

void FileParser::getEntries(std::vector<Entry*> entriesList)
{
  std::string entry;
  while(!fileHandle.eof())
  {
    if(fileHandle.eof())
      break;

    std::getline(fileHandle, entry);
    std::size_t targetLocation = entry.find('|');
    std::string title = entry.substr(0, targetLocation - 2);
    std::string location = entry.substr(targetLocation + 1);
    Entry* nextEntry = new Entry(title, location);
    entriesList.push_back(nextEntry);

    if(verbose)
      std::cout << "Reading Entry - Title: " << " Filepath: " << location << std::endl;
  }

  fileHandle.close();
}
