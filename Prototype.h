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
// This file is the <File Description> file for the Concordance Assignment.
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

//
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
// Arg     == Argument
// Char    == Character
// Dbl     == Double
// Desc    == Description
// EQ      == Equals
// Gen     == Generic
// Info    == Information
// Int     == Integer
// Invar   == Invariant
// L       == Left
// LH      == Left-Hand
// MetCall == Method Call
// Obj     == Object
// Ord     == Order
// Param   == Parameter
// PosCond == Postcondition
// PreCond == Precondition
// Prev    == Previous
// Ptr     == Pointer
// R       == Right
// RH      == Right-Hand
// Ret     == Return
// Str     == String
// T       == Type
// Trav    == Traverse
// Val     == Value
// Var     == Variable

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



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Requisite in the .h file
#pragma once

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// Necessary for file stream operations
#include <fstream>

// Optional: Recommended not to use
// using namespace std;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       #Prototype{}
//
//-------|---------|---------|---------|---------|---------|---------|---------|
// Description: Prototype class (templated)
template <class T>
class Prototype {

//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       STRUCTS (?)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (?) --------------------------------|
// #NodeInt{ }
//-------------------------------------|
// Desc:   A bi-directional 'int' node
// Invars: NULL
   // NOTE: Template type must be named differently from parent type
   struct NodeInt {

//---------------------------|
// Fields
//---------------------------|
// NOTE: All fields must be in an initialized state at runtime to compile in Linux.

//-----------------|
// #data
//-----------------|
// Desc:   Data field of the NodeInt
// Invars: NULL
      int data;

//-----------------|
// #isDeleted
//-----------------|
// Desc:   Field representing the NodeInt deletion state
// Invars: NULL
      bool isDeleted;

//-----------------|
// #lPtr
//-----------------|
// Desc:   "Left" pointer to another NodeInt
// Invars: NULL
      NodeInt* lPtr;

//-----------------|
// #rPtr
//-----------------|
// Desc:   "Right" pointer to another NodeInt
// Invars: NULL
      NodeInt* rPtr;

//---------------------------|
// Methods
//---------------------------|

// None for this struct

//---------------------------|
// Constructors / Destructor
//---------------------------|

//-----------------|
// #NodeInt()
//-----------------|
// Desc:   Default NodeInt constructor
// Invars: NULL
      NodeInt() {
         data = NULL;
         isDeleted = 1;
         lPtr = nullptr;
         rPtr = nullptr;
      } // Closing Node() constructor

//-----------------|
// #NodeInt(int)
//-----------------|
// Desc:   NodeInt constructor by int data
// Invars: NULL
      NodeInt(int someData) {
         Data = someData;
         isDeleted = 0;
         leftPtr = nullptr;
         rightPtr = nullptr;
      }// Closing NodeInt(int) constructor

//-----------------|
// #~NodeInt()
//-----------------|
// Desc:   Default NodeInt destructor
// Invars: NULL
      ~NodeInt() {
         Data = NULL;
         isDeleted = NULL;
         leftPtr = nullptr;
         rightPtr = nullptr;
      } // Closing ~NodeInt() destructor
   };
//-------------------------------------|
// Closing struct NodeInt{ }
//-------------------------------------|



// (?) --------------------------------|
// #NodeGen{ <templated> }
//-------------------------------------|
// Desc:   A bi-directional node (templated)
// Invars: NULL
   // NOTE: Template class must be named differently from parent class
   template<class nodeType>
   struct NodeGen {

//-|-------------------------|
// Fields (NodeGen{ })
//-|-------------------------|
// NOTE: All fields must be in an initialized state at runtime to compile in Linux.

//----|------------|
//    #data (NodeGen{ })
//----|------------|
// Desc:   Data field of the NodeGen
// Invars: NULL
      nodeType data;

//----|------------|
//    #isDeleted (NodeGen{ })
//----|------------|
// Desc:   Field representing the node deletion state
// Invars: NULL
      bool isDeleted;

//----|------------|
//    #lPtr (NodeGen{ })
//----|------------|
// Desc:   "Left" pointer to another NodeGen
// Invars: NULL
      NodeGen<nodeType>* lPtr;

//----|------------|
//    #rPtr (NodeGen{ })
//----|------------|
// Desc:   "Right" pointer to another NodeGen
// Invars: NULL
      NodeGen<nodeType>* rPtr;

//-|-------------------------|
// Methods (NodeGen{ })
//-|-------------------------|

// None for this struct

//-|-------------------------|
// Constructors / Destructor (NodeGen{ })
//-|-------------------------|

//----|------------|
//    #NodeGen() (NodeGen)
//----|------------|
// Desc:   Default NodeGen constructor
// Invars: NULL
      NodeGen() {
         data = NULL;
         isDeleted = 1;
         lPtr = nullptr;
         rPtr = nullptr;
      } // Closing NodeGen() constructor

//----|------------|
//    #NodeGen(nodeType&) (NodeGen{ })
//----|------------|
// Desc:   NodeGen constructor by data
// Invars: NULL
      NodeGen(nodeType& someData) {
         data = someData;
         isDeleted = 0;
         lPtr = nullptr;
         rPtr = nullptr;
      } // Closing Node(nodeType&) constructor

//----|------------|
//    #~NodeGen() (NodeGen{ })
//----|------------|
// Desc:   Default Node destructor
// Invars: NULL
      ~NodeGen() {
         data = NULL;
         // Note: Deletions (if applicable) go here
         isDeleted = NULL;
         lPtr = nullptr;
         rPtr = nullptr;
      } // Closing ~NodeGen() destructor
   };
//-------------------------------------|
// Closing struct NodeGen{ <templated> }
//-------------------------------------|



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CLASSES
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (-) --------------------------------|
// #privVar1
//-------------------------------------|
   std::string privVar1;
   std::string treeData;

// (-) --------------------------------|
// #privVar2
//-------------------------------------|
   T privVar2;
   T someField;

// (-) --------------------------------|
// #privNode
//-------------------------------------|
   NodeGen<T> privNode;

// (-) --------------------------------|
// #privNodePtr
//-------------------------------------|
   NodeGen<T>* rootPtr;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (-) --------------------------------|
// #deletePostOrder()
//-------------------------------------|
   bool deletePostOrder();

// (-) --------------------------------|
// #deletePostOrder(Node<T>*)
//-------------------------------------|
   bool deletePostOrder(NodeGen<T>* nodePtr);

// (-) --------------------------------|
// #travPreOrd(Node<T>*)
//-------------------------------------|
   bool travPreOrd(NodeGen<T>* nodePtr);

// (-) --------------------------------|
// #travInOrd(Node<T>*)
//-------------------------------------|
   bool travInOrd(NodeGen<T>* nodePtr);

// (-) --------------------------------|
// #travPostOrd(Node<T>*)
//-------------------------------------|
   bool travPostOrd(NodeGen<T>* nodePtr);

// (-) --------------------------------|
// #visit(Node<T>*)
//-------------------------------------|
   void visit(NodeGen<T>* nodePtr) const;


   protected:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PROTECTED STRUCTS / CLASSES
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PROTECTED FIELDS (#)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PROTECTED METHODS (#)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None



   public:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC STRUCTS / CLASSES (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #find(<T>)
//-------------------------------------|
   bool find(T someData) const;

// (+) --------------------------------|
// #insert(<T>)
//-------------------------------------|
   bool insert(T& someData);

// (+) --------------------------------|
// #obliviate()
//-------------------------------------|
   void obliviate();

// (+) --------------------------------|
// #printout()
//-------------------------------------|
   void printout() const;

// (+) --------------------------------|
// #setDelete(<T>)
//-------------------------------------|
   bool setDelete(T someData);

// (+) --------------------------------|
// #toString()
//-------------------------------------|
   std::string toString() const;

// (+) --------------------------------|
// #travPreOrd()
//-------------------------------------|
   bool travPreOrd() const;

// (+) --------------------------------|
// #travInOrd()
//-------------------------------------|
   bool travInOrd() const;

// (+) --------------------------------|
// #travPostOrd()
//-------------------------------------|
   bool travPostOrd() const;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Prototype()
//-------------------------------------|
   Prototype();

// (+) --------------------------------|
// #Prototype(string)
//-------------------------------------|
   Prototype(std::string fileAddress);

// (+) --------------------------------|
// #~Prototype()
//-------------------------------------|
   ~Prototype();



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) -------------------------------|
// #setField()
//-------------------------------------|
   void setField(const T& someData);

// (+) --------------------------------|
// #getValue()
//-------------------------------------|
   std::string getValue() const;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATOR OVERLOADS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #operator=()
//-------------------------------------|
   Prototype<T>& operator=(const Prototype<T>& RHarg);

// (+) --------------------------------|
// #operator<<()
//-------------------------------------|
// Defined in .cpp file


}; // Closing Class Prototype

// End of file - Prototype.h
