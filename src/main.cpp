/**
 * The main entry point for the program.
 *
 * Author: Mark Xavier
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "modules/headers/file_parser.h"
#include "modules/headers/entry.h"

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

int main(int argc, char* argv[])
{
  bool verbose = false;
  int c;

  if (argc < 2)
  {
    std::cout << "[*]Error: This program expect at least 2 arguments\n";
    printUsage();
    std::cout << "Program Exiting.\n";
    return 1;
  }

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

  std::string inputFileName(argv[optind++]);
  std::string outputFileName(argv[optind]);

  std::vector<Entry*> entries;
  FileParser fileReader = FileParser(inputFileName, verbose);
  fileReader.getEntries(entries);

  return 0;
}
