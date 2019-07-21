/**
 * The implementation of the FileParser class.
 *
 * Author: Mark Xavier
 */

#include <iostream>
#include <sstream>

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

void FileParser::getEntries(std::vector<Entry*>& entriesList)
{
  std::string entry;
  int id = 0;
  std::string divName("dsmc_toc_id_");
  while(!fileHandle.eof())
  {
    if(fileHandle.eof())
      break;

    std::getline(fileHandle, entry);
    if(entry.length() == 0)
      break;

    std::size_t targetLocation = entry.find('|');
    std::string title = entry.substr(0, targetLocation - 1);
    std::string location = entry.substr(targetLocation + 2);

    std::stringstream ss;
    std::string idNumberString;
    ss << id;
    ss >> idNumberString;

    Entry* nextEntry = new Entry(title, location, divName + idNumberString);
    entriesList.push_back(nextEntry);
    id++;
  }

  fileHandle.close();
}
