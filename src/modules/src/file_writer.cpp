/**
 * To do
 *
 */

#include <iostream>
#include <sstream>

#include "../headers/file_writer.h"

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

void FileWriter::writeTableOfContents(std::vector<Entry*> entries)
{
  std::vector<Entry*>::iterator it;
  int id = 0;
  std::cout << "\n\nWriting Table of Contents\n";
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

void FileWriter::writeFileContents(std::string filePath)
{
  std::ifstream plotFileHandle;
  plotFileHandle.open(filePath);
  std::string line;
  std::cout << filePath << std::endl;
  while(std::getline(plotFileHandle, line))
  {
    if(plotFileHandle.eof())
      break;

    if(line.find("<html>") == std::string::npos && line.find("</html>") == std::string::npos
       && line.find("<body>") == std::string::npos && line.find("</body>") == std::string::npos
       && line.find("<head>") == std::string::npos && line.find("</head>") == std::string::npos)
      fileHandle << line << std::endl;
  }
  plotFileHandle.close();
}

void FileWriter::writeBody(std::vector<Entry*> entries)
{
  std::vector<Entry*>::iterator it;
  for(it = entries.begin(); it != entries.end(); ++it)
  {
    std::cout << "Writing File " << (*it)->getTitle() << std::endl;
    fileHandle << "\n<div class=\"section\" id=\"" << (*it)->getName() << "\">" << std::endl
               << "    " << (*it)->getTitle() << std::endl;
    writeFileContents((*it)->getFilePath());
    fileHandle << "\n</div>\n"; 
  }
}

void FileWriter::writeOutput(std::vector<Entry*> entries)
{
  writeTableOfContents(entries);
  writeBody(entries);
  fileHandle << "</body>\n";
  fileHandle.close();
}
