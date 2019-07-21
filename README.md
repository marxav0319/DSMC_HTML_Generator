# DSMC_HTML_Generator

This is a little HTML generator I'm creating for work.  This generator is being created for an NIH
funded clinical research study being conducted at NYU.  The statistical programmer on the trial
generates html plots via SAS, but combining these into a document with a table of contents and
working links was a challenge.  To help address this challenge I'm writing this document preperation
program.

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
>> # To run (on Windows)
>> bin/DSMC_HTML_Generator [-h] [-v] <input-file_path> <output-file-path>
```

