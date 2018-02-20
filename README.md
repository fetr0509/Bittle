# Bittle

A little bit-manipulation library that focuses on offering compiler independent behavior for common bit operations.

This library was written using C11 and compiled using gcc.  
Tests created using the cmocka test harness and built using Cmake.

## Library Architecture

### How to include the Library
This library is a single header library and is therefore completely self contained within the header file **"bittle.h"**

### Common Patterns
Many functions in this library come in 4 different variants depending on the desired length you want your operations truncated to. 

Some compilers choose to bit extend any bit manipulations operations to the largest width primitive type on the target architecture. This can cause operations that would normally result in a 0 when all bits are shifted out, to return values that would not logically result from these operations.  
  
functions with a b(n) suffix will adhere to the width designated by the width following the b.


##### Logical Left Shift - LS_b(n) (value, num_shifts)
These macros will shift the value given by num_shifts left while also adhering to the width denoted by n.   

##### Logical Right Shift - LRS_b(n) (value, num_shifts)
These macros will shift the value given by num_shifts right while concatenating a 0 to the leftmost bit while also adhering to the width denoted by n.



## Compiling the tests

In order to compile and run the tests you must have several components installed.

  * You must have cmake installed in order to compile the tests
  * You must have cmocka version 1.1.0 or later installed.

If compiling on windows there are 2 .dll files need to run the tests. These files are included with the source and will be automatically copied into the executable directory if not present there already.

When all of these things are present simply run "**make check**" in the outermost directory and the tests should automatically build and run.

