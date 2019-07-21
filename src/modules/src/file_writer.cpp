/**
 * To do
 *
 */

#include "../headers/file_writer.h"

FileWriter::FileWriter(std::string outputFileName_) : outputFileName(outputFileName_)
{
  fileHandle.open(outputFileName);
  fileHandle << "<!DOCTYPE html>\n\n<head>\n"
             << "<meta content=\"text/html; charset=ISO-8859-1\"\n"
             << "http-equiv=\"content-type\">\n"
             << "<title>test</title>\n"
             << "<script src=\"http://www.w3schools.com/lib/w3data.js\"></script>\n\n"
             << "</head>\n<body></body>\n\n";

  fileHandle.close();
}

void FileWriter::writeEntriesToFile(std::vector<Entry*> entries)
{
  // To do

  return;
}
