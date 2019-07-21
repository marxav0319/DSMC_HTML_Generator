/**
 * The implementation file for a class defining an "entry" or a line item in the input file.
 *
 * Author: Mark Xavier
 */

#include "../headers/entry.h"

Entry::Entry(std::string title_, std::string filePath_) : title(title_), filePath(filePath_)
{
  return;
}