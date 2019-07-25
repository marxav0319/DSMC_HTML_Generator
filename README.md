# DSMC_HTML_Generator

This is a little HTML generator I'm creating in my free time to help address an inconvenience a
co-worker has run into.  The idea is to grab a whole bunch of separate HTML files (holding tables of
statistical data) and combine them into one webpage with a table of contents [TOC] linking to each
respective table.  The created webpage will also need to be able to display images (plots in our
case), hold authorship data, and provide some minimal formatting (most of this will probably be
custom css).  I'm mostly doing this for fun, my co-worker has other solutions to her problem, but
I'm sure seeing a slightly more custom solution would be nice.

This is currently in development and subject to major overhaul (I'm updating multiple times a week),
so I wouldn't advise using it except experimentally.  Here's what the program currently does:

+ Read in an input file
  + One line per entry
  + Entry consists of `Title [for TOC] | <filepath_to_html>` or `Title | None`
    + Where `None` is literally the string "None", which simply creates a parent header with no
      associated html.
+ Create an html file
  + Output file consists of table of contents linking sections holding the text located between the
    `<body></body>` tags in each `<filepath_to_html>` in the input file

Eventually the program will also be able to:

+ Reference images
+ Accept authorship information and a title
+ Generate some css (?)
+ Allow for more flexible TOC formatting
+ Convert to PDF (???? - This is the last step, we'll see how we get there)

## Requirements

To compile

+ `g++` (I used `gcc 6.3.0`)

To test and compile

+ `g++` (I used `gcc 6.3.0`)
+ `python 3.6+`
+ `numpy 1.16+`
+ `plotly 4.0+`

## Usage

```bash
>> # Compiling
>> # Run make to generate the program
>> make
>>
>> # or run make verbose to also generate a test html page.
>> make verbose
>>
>> # The program compiles to the bin directory
>> bin/DSMC_HTML_Generator [-h] [-v] <input-file_path> <output-file-path>
```

The `v` option is inconsistent and hasn't helped me much, I'll likely abandon it until the end when
I want to provide diagnositics for a more finished product.

## The Input and Output Files

The input file is formatted as mentioned above.  I'll provide a visual here of what I picture the
input file to look like:

```
1. Title of First Section | <filepath_to_img_or_html>
1.1. Title of First Subsection | <filepath_to_img_or_html>
1.2. Title of Second Subsection | <filepath_to_img_or_html>
2. Title of Second Section | <filepath_to_img_or_html>
...
8.10. Last subsection | <filepath_to_img_or_html>
```

And the goal is to get a TOC looking like this:

```
1. Title of First Section
   1.1. Title of First Subsection
   1.2. Title of Second Subsection
2. Title of Second Section
...
   8.10. Last subsection
```

With links to each section (holding each table/plot).
