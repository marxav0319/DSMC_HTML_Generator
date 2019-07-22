/**
 * This file is part of the DSMC_HTML_Generator package.
 *
 * The main entry point for the program.  This program serves to gather html resources and
 * accumulate them into one static HTML document.  The document can then be further edited to
 * include any other info needed.
 *
 * Author: Mark Xavier
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <deque>

#include "modules/headers/file_parser.h"
#include "modules/headers/entry.h"
#include "modules/headers/file_writer.h"

/**
 * Prints help message and usage information to the console.
 */
void printUsage()
{
  std::cout << "\n##################################################################\n"
            << "USAGE:\n\n"
            << "This program generates a bare-bones HTML document based on an\n"
            << "input file notating the table of contents structure.  The\n"
            << "program must be called as follows:\n\n"
            << "DSMC_HTML_Generator [-h] [-v] <toc_structure_file> <output_filepath>\n\n"
            << "For information on the file structure of the two required arguments\n"
            << "refer to the included README.\n\n"
            << "-h : Help, prints this usage information.\n"
            << "-v : Verbose, increased logging to console.\n"
            << "##################################################################\n\n";
}

/**
 * The main entry-point of the program.
 *
 * This function requires to command line arguments, the input_file and the output_filepath.
 * Further information on the input file can be found in the included README.md.
 */
int main(int argc, char* argv[])
{
  bool verbose = false;
  int c;

  // Make sure that we have at least 2 arguments.
  if (argc < 2)
  {
    std::cout << "[*]Error: This program expect at least 2 arguments\n";
    printUsage();
    std::cout << "Program Exiting.\n";
    return 1;
  }

  // Case switch to deal with optional arguments.
  while((c = getopt(argc, argv, "hv")) != -1)
  {
    switch(c)
    {
      case 'h':
        printUsage();
        return 0;
      case 'v':
        verbose = true;
        break;
      case '?':
        std::cerr << "Unknown argument " << optopt << " passed.\n";
        return 1;
      default:
        std::abort();
    }
  }

  // Read in required arguments
  std::string inputFileName(argv[optind++]);
  std::string outputFileName(argv[optind]);

  // Read input file
  std::deque<Entry*> entries;
  FileParser fileReader = FileParser(inputFileName, verbose);
  fileReader.getEntries(entries);

  // Write output file
  FileWriter fileWriter = FileWriter(outputFileName);
  fileWriter.writeOutput(entries);

  return 0;
}
