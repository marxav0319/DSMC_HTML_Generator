/**
 * This file is part of the DSMC_HTML_Generator package.
 *
 * This header file defines constants to be used across the source files included in this directory
 * (src) and below.
 *
 * Author: Mark Xavier
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

// Converter
const std::string CONVERTER = "wkhtmltopdf.exe";

// HTML tags to ignore
const std::string DOC_START = "!DOCTYPE";
const std::string HTML_START = "<html";
const std::string HTML_END = "</html";
const std::string HEAD_START = "<head";
const std::string HEAD_END = "</head";
const std::string BODY_START = "<body";
const std::string BODY_END = "</body";
const std::string TITLE_START = "<title";
const std::string TITLE_END = "</title";
const std::string SAS_SYSTEM = "The SAS System";

// File Extensions
const std::string HTML_FILE_EXTENSION = ".html";
const std::string PDF_FILE_EXTENSION = ".pdf";

#endif // CONSTANTS_H
