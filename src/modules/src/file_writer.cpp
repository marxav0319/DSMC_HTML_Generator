/**
 * This file is part of the DSMC_HTML_Generator package.
 *
 * This file implements the FileWriter class.
 *
 * Author: Mark Xavier
 *
 */

#include <iostream>
#include <sstream>

#include "../headers/file_writer.h"
#include "../../constants.h"

// Write some boiler plate HTML
FileWriter::FileWriter(std::string outputFileName_) : outputFileName(outputFileName_)
{
  std::cout << "File Writer Created\n";
  fileHandle.open(outputFileName);
  fileHandle << "<!DOCTYPE html>\n\n<head>\n"
             << "<meta content=\"text/html; charset=ISO-8859-1\"\n"
             << "http-equiv=\"content-type\">\n"
             << "<title>test</title>\n"
             << "</head>\n<body>\n\n<ul class=\"table_of_contents\">";
}

// Write out the table of contents
void FileWriter::writeTableOfContents(std::deque<Entry*> entries)
{
  // Variable setup
  std::deque<Entry*>::iterator it;
  int id = 0;

  // For each entry, write the entry as a list-item with it's associated id
  for(it = entries.begin(); it != entries.end(); ++it)
  {
    std::cout << (*it)->getTitle() << std::endl;
    std::stringstream ss;
    std::string idNumberString;
    ss << id;
    ss >> idNumberString;
    fileHandle << "\n<li>\n    <a href=\"#" << (*it)->getName() << "\">" << (*it)->getTitle()
               << "</a>\n</li>\n";
  }
  fileHandle << "</ul>\n\n";
}

bool FileWriter::isSkippableTag(const std::string line)
{
  bool isDocStart = line.find(DOC_START) != std::string::npos;
  bool isHTMLStart = line.find(HTML_START) != std::string::npos;
  bool isHTMLEnd = line.find(HTML_END) != std::string::npos;
  bool isBodyStart = line.find(BODY_START) != std::string::npos;
  bool isBodyEnd = line.find(BODY_END) != std::string::npos;
  bool isTitleStart = line.find(TITLE_START) != std::string::npos;
  bool isTitleEnd = line.find(TITLE_END) != std::string::npos;
  bool isSASString = line.find(SAS_SYSTEM) != std::string::npos;
  bool result = (isHTMLStart || isHTMLEnd || isBodyStart || isBodyEnd || isTitleStart || isTitleEnd
                 || isSASString);

  return result;
}

// Open a file and write it's contents to the output file
void FileWriter::writeFileContents(const std::string filePath)
{
  // Variable setup
  htmlFileHandle.open(filePath);
  std::string line;

  // For each line in the file, write the line to the output file if it doesn't include certain keys
  while(std::getline(htmlFileHandle, line))
  {
    if(htmlFileHandle.eof())
      break;

    if(line.find(HEAD_START) != std::string::npos)
      while(line.find(HEAD_END) == std::string::npos)
        std::getline(htmlFileHandle, line);
    else if(!isSkippableTag(line))
      fileHandle << line << std::endl;
  }
  htmlFileHandle.close();
}

// Writes the entries the body of the HTML file outside of the table of contents
void FileWriter::writeBody(std::deque<Entry*> entries)
{
  std::deque<Entry*>::iterator it;

  // For each entry create a <div> and write file contents if applicable
  while(entries.size() > 0)
  {
    // Get the first entry
    Entry* entry = entries.front();
    std::cout << "Writing File " << entry->getTitle() << std::endl;

    // Write the appropriate <div>
    fileHandle << "\n<div class=\"section\" id=\"" << entry->getName() << "\">" << std::endl;
    fileHandle << entry->getTitle() << std::endl;

    // If this is an html file, write contents to file
    if(entry->getFilePath().compare("None") != 0)
      writeFileContents(entry->getFilePath());
    fileHandle << "\n</div>\n";

    // Delete the entry
    entries.pop_front();
    delete entry;
  }
}

// Wraps the other writer methods and writes the entire output file
void FileWriter::writeOutput(std::deque<Entry*> entries)
{
  writeTableOfContents(entries);
  writeBody(entries);
  fileHandle << "</body>\n";
  fileHandle.close();
}
