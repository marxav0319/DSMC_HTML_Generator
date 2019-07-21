/**
 * This file is part of the DSMC_HTML_Generator package.
 *
 * This file holds the implementation of the Entry class.
 *
 * Author: Mark Xavier
 */

#include "../headers/entry.h"

Entry::Entry(std::string title_, std::string filePath_, std::string name_) : title(title_),
  filePath(filePath_), name(name_)
{
  return;
}