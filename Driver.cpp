//-------------------------------------|
// Project Name
//-------------------------------------|
// <FirstName> <LastName>
// <EmailAddress>
// <YYYY.MM.DD>
// For the University of Washington Bothell CSS 501A
// Winter 2017, Graduate Certificate in Software Design & Development (GCSDD)

//-------------------------------------|
// File Description
//-------------------------------------|
// This file is the <File Description> file for the <Project Name>.
// <Generalized Description of Program Function>

//-------------------------------------|
// Package Files
//-------------------------------------|
// Driver.cpp
// Class1.h
// Class1.cpp
// Class2.h
// Class2.cpp
// UtilityFile1.txt
// UtilityFile2.txt

//-------------------------------------|
// Acknowledgements
//-------------------------------------|

// Template author:
// Tim Lum (twhlum@gmail.com)

//-------------------------------------|
// License
//-------------------------------------|
// This software is published under the The 2-Clause BSD License
// https://en.wikipedia.org/wiki/BSD_licenses

/*
MIT License

Copyright (c) 2017 Timothy W. Lum (twhlum@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

//-------------------------------------|
// Abbreviations
//-------------------------------------|
// (-)      == (UML) Private
// (#)      == (UML) Protected
// (+)      == (UML) Public
// !        == Not
// @        == At
// #b2c     == #-Bit 2's Complement
// Arg      == Argument
// Alloc    == Allocate(d)
// Char     == Character
// Curr     == Current
// DB       == Database
// Dbl      == Double
// Desc     == Description
// deQ      == Dequeue
// enQ      == Enqueue
// EoF      == End of File
// EoL      == End of Line
// EQ       == Equals
// Exts     == Extends
// FIFO     == First In, First Out (Queue)
// Gen      == Generic
// Info     == Information
// Inhrt    == Inherit
// Int      == Integer
// Invar    == Invariant
// L        == Left
// LIFO     == Last In, First Out (Stack)
// LH       == Left-Hand
// LL       == Linked List
// LSB      == Least Significant Bit
// LSD      == Least Significant Digit
// Malloc   == Memory Allocate(d)
// MetCall  == Method Call
// Mo3      == Median of Three
// MSB      == Most Significant Bit
// MSD      == Most Significant Digit
// NaN      == Not a Number
// NaV      == Not a Value
// Obj      == Object
// Param    == Parameter
// PosCond  == Postcondition
// PreCond  == Precondition
// Prev     == Previous
// Ptr      == Pointer
// Q        == Queue
// R        == Right
// Ret      == Return
// RetVal   == Return Value
// RGB      == Red Green Blue
// (R)GB    == Red
// R(G)B    == Green
// RG(B)    == Blue
// RH       == Right-Hand
// RT       == Runtime
// RtL      == Right to Left
// Str      == String
// T        == Type
// Trav     == Traverse / Traversal
 // PreOrd  == Pre-Order
 // InOrd   == In-Order
 // PostOrd == Post-Order
// TtB      == Top to Bottom
// Ur-      == Originator, foremost (ie. Ur-Node)
// Val      == Value
// Var      == Variable

//-------------------------------------|
// Code Standards
//-------------------------------------|
// Source material from:
// University of Washington Bothell
// CSS 501A Data Structures And Object-Oriented Programming I
// "Design and Coding Standards"
// c. Michael Stiber
//
// I. Comment at beginning of file (above) stating (at a minimum):
//    A. File Name
//    B. Author Name
//    C. Date
//    D. Description of code purpose 
// II. Indentation:
//    A. 3 whitespaces ("   ")
//    B. May vary depending on language and instructor
// III. Variables:
//    A. Descriptive, legible name
//    B. Comment over any variable declaration describing:
//       0. Its use in the algorithm
//       1. Invariant information such as legal ranges of values
// IV. Class Files:
//    A. Separate *.cpp and *.h files should be used for each class.
//    B. Files names must exactly match class names (case-sensitive)
// V. Includes:
//    A. Calls for content ("#include") from the Standard Template Library (STL) should be formatted as follows:
//       0. DO type:     #include <vector>
//       1. Do NOT type: #include <vector.h>
//    B. You may use the directive "using namespace std;"
//       0. ??? (?CONFIRM?)
// VI. Classes:
//    A. Return values:
//       0. Do NOT return references to internal class structures.
//       1. Do NOT return pointers to internal class structures.
//    B. Do NOT expose any details of the internal implementation.
// VII. Functions + Methods:
//    A. Functions should be used for appropriate operations.
//    B. Reference arguments should be used only when necessary.
//    C. The (return?CONFIRM?) type of each function must be declared
//       0. Use 'void' when necessary
//    D. Declare as 'const' (unalterable) when no modification is made to the object state
//       0. UML 'query' property (?CONFIRM?)
// VIII. Function Comments:
//    A. DO include a comment prior to each function which includes the function's:
//       0. Purpose - Why does the function exist?
//       1. Parameters - What fields does the function contain?
//       2. Preconditions - What conditions must be true prior to the function call?
//       3. Postconditions - What conditions must be true after the function call?
//       4. Return value - What is the nature and range of the value returned by the function?
//       5. Functions called - What other functions are called by this function?
// IX. Loop invariants
//    A. Each loop should be commented with 'invariant' information (?CONFIRM?)
// X. Assertions:
//    A. May be comments or the 'assert()' feature.
//    B. Insert where useful to explain important features or subtle logic.
//    C. What, exactly, is an assertion (?CONFIRM?)
// XI. Prohibited (unless justified):
//    A. Global variables
//    B. "Gotos" (?CONFIRM?)

//-------------------------------------|
// Special Instructions
//-------------------------------------|
// To install G++:
// sudo apt install g++

// To update Linux:
// sudo apt-get update && sudo apt-get install
// sudo apt-get update

// To make a new .cpp file in Linux:
// nano <file name>.cpp

// To make a new .h file in Linux:
// nano <file name>.h

// To make a new .txt file in Linux:
// nano <file name>.txt

// To compile in g++:
// g++ -std=c++11 *.cpp

// To run with test input:
// ./a.out < TestInput.txt

// To run Valgrind:
// Install Valgrind:
// sudo apt install valgrind
//
// Run with:
// valgrind --leak-check=full <file folder path>/<file name, usually a.out>
// OR
// valgrind --leak-check=full --show-leak-kinds=all <file path>/a.out
//
// ie.
// valgrind --leak-check=full /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out < /Sudoku.txt

// To load a text file as cin input in Visual Studios:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. "< <Filepath>/<Filename>.txt" ie. "< /Sudoku.txt"
// ie. < /Sudoku.txt

// To pass a command argument:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. Enter the file address and name
// ie. corpus.txt
// 3. Alter main() method signature as follows: main( int argc, char* argv[] ) {
// 4. The variable "argv[1]" now refers to the first command argument passed
//
// To run in Linux with Valgrind and a command argument
// valgrind --leak-check=full --show-leak-kinds=all ./a.out corpus.txt

// To declare a templated operator overload
// .h file
// template <class T>
// class someClass
// {
//    template <class T>
//    friend ostream& operator << (ostream& someStream, someClass<T>& someObject);
// };
//
// .cpp file
// template <typename someDataType>
// ostream& operator << (ostream& ostr, BinarySearchTree<someDataType>& treeObject)
// {
//    <Code Implementation Goes Here>
//    return ostr;
// }

//-------------------------------------|
// Index
//-------------------------------------|
// I. Include Statements
//
// II. Private
//    A. Structs / Classes
//    B. Fields
//    C. Methods
//
// III. Protected
//    A. Structs / Classes
//    B. Fields
//    C. Methods
//
// IV. Public
//    A. Structs / Classes
//    B. Fields
//    C. Methods
//    D. Constructors / Destructor
//    E. Getters / Setters
//
// V. Operator Overloads

//-------------------------------------|
// Begin Student Code
//-------------------------------------|
// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// The Collector class - Used to create a stopword list and a concordance tree.
#include "Prototype.h"
#include "Prototype.cpp" // .cpp required here due to generic/template functionality of this class

// Methods not found in the current namespace are directed to check the 'std' namespace
// using namespace std;

int main( int argc, char* argv[] ) {  // Array of command-line arguments strings

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       UNIT TESTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       ASSIGNMENT DRIVER
//
//-------|---------|---------|---------|---------|---------|---------|---------|
   std::cout << "This is a test!" << std::endl;

   Prototype<int> intProto;

   return(0);

}
