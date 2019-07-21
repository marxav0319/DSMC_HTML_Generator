/**
 * This file is part of the DSMC_HTML_Generator package.
 *
 * This file defines the structure of the Entry class.  An entry is a line-item in the input file
 * documenting the structure of the table of contents.  A line item includes the title of the
 * section and the filepath to the html snippet (or 'NONE' if this is simply a section change).
 *
 * Author: Mark Xavier
 */

#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry
{
public:
  
  /**
   * Parameterized constructor for Entry
   *
   * @param title_ : The title of the table of contents entry.
   * @param filePath_ : The filepath to the HTML resource.
   * @param name_ : The id of the HTML element to be created.
   * @return : New Entry instance.
   */
  Entry(std::string title_, std::string filePath_, std::string name_);

  // Getters

  /**
   * Returns the title of the entry.
   *
   * @return : Title as an std::string
   */
  std::string getTitle() {return title;}

  /**
   * Returns the filepath of the associated HTML resource.
   *
   * @return : Filepath as an std::string
   */
  std::string getFilePath() {return filePath;}

  /**
   * Returns the auto-generated name (id) of the html content.
   *
   * @return : Name as an std::string
   */
  std::string getName() {return name;}

private:
  // Member Data
  std::string title;
  std::string filePath;
  std::string name;
};

#endif // ENTRY_H
