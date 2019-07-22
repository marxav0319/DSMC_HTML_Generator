/**
 * This file is part of the DSMC_HTML_Generator package.
 *
 * This file outlines a class that is responsible for writing the output to file.  This class walks
 * through an std::vector of "Entry" instances, writes a table of contents, links the entries in
 * that table to the appropriate section, and loads the html resource associated with that section
 * in the document.
 *
 * Author: Mark Xavier
 *
 */

#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <fstream>
#include <deque>

#include "entry.h"

class FileWriter
{
public:
  /**
   * Parameterized constructor.
   *
   * Returns an instance of the FileWriter class.
   *
   * @param outputFileName_ : The filepath and full name for the output file.
   * @return : An instance of the FileWriter class.
   */
  FileWriter(std::string outputFileName_);

  /**
   * Writes the output file to the location passed to the constructor.
   *
   * @parm entries : An std::vector<Entry*> of the entries to write.
   * @return : void
   */
  void writeOutput(std::deque<Entry*> entries);
private:
  std::string outputFileName;
  std::ofstream fileHandle;

  /**
   * Writes the table of contents to the output HTML file given the vector of entries.
   *
   * @param entries : The std::vector<Enry*> to write to file.
   * @return : void
   */
  void writeTableOfContents(std::deque<Entry*> entries);

  /**
   * Writes the entries and the associated HTML snippets to the file after the table of contents.
   *
   * @param entries : The std::vector<Enry*> to write to file.
   * @return : void
   */
  void writeBody(std::deque<Entry*> entries);

  /**
   * Opens the resource file containing the source HTML and writes it to the output file.
   *
   * @param entries : The filePath of the file with the HTML snippet.
   * @return : void
   */
  void writeFileContents(std::string filePath);
};

#endif // FILEWRITER_H