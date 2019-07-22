# DSMC_HTML_Generator

This is a little HTML generator I'm creating in my free time to help address an issue we've run into
at work.  The inspiration for this generator came from an NIH funded clinical research study being
conducted at NYU.  The statistical programmer on the trial generates html plots and tables via SAS,
but combining these into a document with a table of contents and working links was a challenge.  To
help address this challenge I'm writing this document preperation program.

**Note on use cases:**

Currently this is a proof of concept that is being expanded.  This software is most certainly not
the best way to accomplish this goal.  For instance, the choice to use C++ was entirely for my own
amusement.  I wanted to keep my C++ skills sharp while at the same time apparently causing myself as
much frustration over the simple things as possible.

Also, the method of attack here is certainly not ideal.  All this program does **for now** is pop
open the HTML resources and pipe the relevant HTML into a single file.  In the long run, this could
create some seriously huge files that load very slowly.  Especially since some HTML based plots have
**huge** amounts of code.

For our projects at work, this may not be a big problem.  Styling can be done via a single .css file
and the tables generated by the SAS software are not dynamic in nature.  However I would really like
to expand this to more use cases, which may mean creating separate modules or methods in other
languages (I'm looking at you JS) to help with the dynamic content loading.

# Requirements

To compile

+ g++ (I used gcc 6.3.0)

To test and compile

+ g++ (I used gcc 6.3.0)
+ python 3.6+
+ numpy 1.16+
+ plotly 4.0+

# Usage

```bash
>> # Compiling
>> # Run make to generate the program
>> make
>>
>> # or run make compile_and_test to also generate a test html page.
>> make compile_and_test
>>
>> # The program compiles to the bin directory
>> bin/DSMC_HTML_Generator [-h] [-v] <input-file_path> <output-file-path>
```
