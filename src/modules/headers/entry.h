/**
 * The header file for a class defining an "entry" or a line item in the input file.
 *
 * Author: Mark Xavier
 */

#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry
{
public:
  // Constructor
  Entry(std::string, std::string, std::string);

  // Getters
  std::string getTitle() {return title;}
  std::string getFilePath() {return filePath;}
  std::string getName() {return name;}

private:
  std::string title;
  std::string filePath;
  std::string name;
};

#endif // ENTRY_H
