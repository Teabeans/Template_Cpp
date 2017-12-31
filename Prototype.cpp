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
// This software is published under the MIT License.
// https://en.wikipedia.org/wiki/MIT_License
// https://opensource.org/licenses/MIT

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



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// Necessary for file stream operations
#include <fstream>

// Field and method declarations for the Prototype class
#include "Prototype.h"

// Optional: Recommended not to use
// using namespace std;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE STRUCTS / CLASSES (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these structs/classes in the .cpp.
// Included here only for reference
// See associated .h file for struct/class declarations



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations

// (-) --------------------------------|
// #someVar1
//-------------------------------------|
// Desc:   NULL
// Invars: NULL
// template <class typeT>
// typeT someVar1;

// (-) --------------------------------|
// #someVar2
//-------------------------------------|
// Desc:   NULL
// Invars: NULL
// string someVar2;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS (-)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (-) --------------------------------|
// #deletePostOrder()
//-------------------------------------|
// Desc:    Helper method for post-order deletion method
// Params:  None
// PreCons: None
// PosCons: All nodes have been deleted
// RetVal:  True - Signal of successful deletion traversal
//                   False - No deletion possible (empty tree)
// MetCall: deletePostOrder()
template <class typeT>
bool Prototype<typeT>::deletePostOrder() {
   // Check for empty tree
   if (rootPtr == nullptr) {
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (deletePostOrder(rootPtr));
   }
}

// (-) --------------------------------|
// #deletePostOrder(NodeGen*)
//-------------------------------------|
// Desc:    Recursive method for post-order deletion
// Params:  NodeGen* - The target node to be traversed and deleted
// PreCons: None
// PosCons: All nodes in this subtree have been deleted
// RetVal:  True - Signal of successful deletion traversal
// MetCall: deletePostOrder()
template <class typeT>
bool Prototype<typeT>::deletePostOrder(NodeGen<typeT>* thisNode) {
   // Left traverse
   if (thisNode->lPtr != nullptr) {
      deletePostOrder(thisNode->lPtr);
   }
   // Right traverse
   if (thisNode->rPtr != nullptr) {
      deletePostOrder(thisNode->rPtr);
   }
   // Visit (delete)
   delete thisNode;
   return(true);
}

// (-) --------------------------------|
// #travPreOrd()
//-------------------------------------|
// Desc:    Helper method for pre-order traversal method
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  True - Signal of successful recursive traversal
//          False - No traversal possible
// MetCall: traversePreOrder()
template <class typeT>
bool Prototype<typeT>::travPreOrd() const {
   // Check for empty tree
   if (rootPtr == nullptr) {
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (travPreOrd(rootPtr));
   }
}

// (-) --------------------------------|
// #travPreOrd(NodeGen*)
//-------------------------------------|
// Desc:    Recursive pre-order traversal method
// Params:  NodeGeneric* arg1 - Pointer to the node to traverse
// PreCons: None
// PosCons: None
// RetVal:  True - Signal of successful recursive traversal
// MetCall: traversePreOrder()
//          visit()
template <class typeT>
bool Prototype<typeT>::travPreOrd(NodeGen<typeT>* thisNode) {
   visit(thisNode);
   if (thisNode->leftPtr != nullptr) {
      travPreOrd(thisNode->leftPtr);
   }
   if (thisNode->rightPtr != nullptr) {
      travPreOrd(thisNode->rightPtr);
   }
   return(true);
}

// (-) --------------------------------|
// #travInOrd()
//-------------------------------------|
// Desc:    Helper method for in-order traversal method
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  True - Signal of successful recursive traversal
//          False - No traversal possible
// MetCall: traverseInOrder()
template <class typeT>
bool Prototype<typeT>::travInOrd() const{
   // Check for empty tree
   if (rootPtr == nullptr) {
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (travInOrd(rootPtr));
   }
}

// (-) --------------------------------|
// #travInOrd(NodeGen*)
//-------------------------------------|
// Desc:    Recursive in-order traversal method
// Params:  NodeGeneric* arg1 - Pointer to the node to traverse
// PreCons: None
// PosCons: None
// RetVal:  True - Signal of successful recursive traversal
// MetCall: travInOrd()
//          visit()
template <class typeT>
bool Prototype<typeT>::travInOrd(NodeGen<typeT>* thisNode) {
   if (thisNode->leftPtr != nullptr) {
      travInOrd(thisNode->leftPtr);
   }
   visit(thisNode);
   if (thisNode->rightPtr != nullptr) {
      travInOrd(thisNode->rightPtr);
   }
   return(true);
}

// (-) --------------------------------|
// #travPostOrd()
//-------------------------------------|
// Desc:    Helper method for post-order traversal method
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  True - Signal of successful recursive traversal
//          False - No traversal possible
// MetCall: traversePostOrder()
template <class typeT>
bool Prototype<typeT>::travPostOrd() const{
   // Check for empty tree
   if (rootPtr == nullptr) {
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (travPostOrd(rootPtr));
   }
}

// (-) --------------------------------|
// #travPostOrd(NodeGen*)
//-------------------------------------|
// Desc:    Recursive post-order traversal method
// Params:  NodeGeneric* arg1 - Pointer to the node to traverse
// PreCons: None
// PosCons: None
// RetVal:  True - Signal of successful recursive traversal
// MetCall: traversePostOrder()
//          visit()
template <class typeT>
bool Prototype<typeT>::travPostOrd(NodeGen<typeT>* thisNode) {
   if (thisNode->leftPtr != nullptr) {
      travPostOrd(thisNode->leftPtr);
   }
   if (thisNode->rightPtr != nullptr) {
      travPostOrd(thisNode->rightPtr);
   }
   visit(thisNode);
   return(true);
}

// (-) --------------------------------|
// #visit(NodeGen)
//-------------------------------------|
// Desc:    Private: Visits the node indicated by sending the nodeData content to cout.
// Param:   NodeGen* - The target node being visited
// PreCons: None
// PosCons: None
// RetVal:  None
// MetCall: None
template <class typeT>
void Prototype<typeT>::visit(NodeGen<typeT>* thisNodePtr) const {
   // Visit the node, but only perform an action if the node is undeleted
   if (thisNodePtr->isDeleted == false) {
      // Send the nodeData to the output stream
      // In the case of a Context, that's an iteration down the linked list
      cout << thisNodePtr->nodeData;
   }
   // Otherwise the node is "deleted", so do nothing.
   else {
   }
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PROTECTED STRUCTS / CLASSES (#)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these structs/classes in the .cpp.
// Included here only for reference
// See associated .h file for struct/class declarations



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PROTECTED FIELDS (#)
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PROTECTED METHODS (#)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC STRUCTS / CLASSES (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Do not redeclare these structs/classes in the .cpp.
// Included here only for reference
// See associated .h file for struct/class declarations



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #find(typeT)
//-------------------------------------|
// Desc:    Finds a node with an equal value of the string argument
// Param:   typeT - The data to search for
// PreCons: None
// PosCons: None
// RetVal:  True - An equivalent node was found
//          False - An equivalent node was not found
// MetCall: None
template <class typeT>
bool Prototype<typeT>::find(typeT someData) const {
   // If the tree is empty, do nothing
   if (rootPtr == nullptr) {
      // cout << "No value found. This tree is empty." << endl; // DEBUG
      return(false);
   }
   // Otherwise, start at the rootPtr
   else {
      NodeGen<typeT>* currPtr = rootPtr;
      // While we haven't run off the end of the tree...
      while (currPtr != nullptr) {
         // Found it! (And it's undeleted)
         if (currPtr->nodeData == someData && currPtr->isDeleted == false) {
            return(true);
         }
         // Found it! (But it's deleted)
         else if (currPtr->nodeData == someData && currPtr->isDeleted == true) {
            return(false);
         }
         // Otherwise, go left if someData is less than this node
         else if (someData < currPtr->nodeData) {
            currPtr = currPtr->leftPtr;
         }
         // Or right if greater
         else if (someData > currPtr->nodeData) {
            currPtr = currPtr->rightPtr;
         }
      } // Closing while loop. We've either exited (found the value above)...
      // ... or run off the tree.
      return(false);
   }
} // Closing find()

// (+) --------------------------------|
// #insert(typeT)
//-------------------------------------|
// Desc:    Attempts to insert data of typeT to the tree
// Params:  typeT arg1 - The data to insert
// PreCons: None
// PosCons: Data has been found or search has run off the tree
//          Data has been assigned to an appropriate node of the tree
// RetVal:  True - Data was not found in the tree. Assigned off a leaf.
//          False - Data found in the tree, assignment still occured
// MetCall: NodeGen()
template <class typeT>
bool Prototype<typeT>::insert(typeT& someData) { // Receiving by reference
   NodeGen<typeT>* currNodePtr = rootPtr;
   NodeGen<typeT>* prevNodePtr = nullptr;
   // Initial case: If tree is empty, insert a new node at the root
   if (rootPtr == nullptr) {
      rootPtr = new NodeGen<typeT>(someData);
      // And halt execution
      return(true);
   }
   // X------------------------X
   // |    Node Comparisons    |
   // X------------------------X
   // Otherwise, while the current node pointer is not off the end of a leaf...
   while (currNodePtr != nullptr) {
      // X-------------X
      // |    Equal    |
      // X-------------X
      if (currNodePtr->nodeData == someData) {
         // Undelete if necessary
         if (currNodePtr->isDeleted == true) {
            // Undelete it if so
            currNodePtr->isDeleted = false;
         }
         currNodePtr->nodeData = someData;
         return(false);
      }
      // X-----------------X
      // |    Less than    |
      // X-----------------X
      else if (someData < currNodePtr->nodeData) {
         // Move left
         prevNodePtr = currNodePtr;
         currNodePtr = currNodePtr->leftPtr;
      }
      // X--------------------X
      // |    Greater than    |
      // X--------------------X
      else if (someData > currNodePtr->nodeData) {
         // Move right
         prevNodePtr = currNodePtr;
         currNodePtr = currNodePtr->rightPtr;
      }
   } // Ending tree descent. Curr is now nullptr, Prev is the node pointing at Curr
   // X--------------------------X
   // |    Insertions off end    |
   // X--------------------------X
   // If insert data is less than this node data, insert left
   if (someData < prevNodePtr->nodeData) {
      prevNodePtr->leftPtr = new NodeGeneric<typeT>(someData);
   }
   // Otherwise, insert right
   else if (someData > prevNodePtr->nodeData) {
      prevNodePtr->rightPtr = new NodeGeneric<typeT>(someData);
   }
   return(true);
} // Closing insert()

// (+) --------------------------------|
// #obliviate()
//-------------------------------------|
// Desc:      Deletes all nodes within the BST
// Params:    None
// PreCons:   None
// PosCons:   All tree nodes have been deleted.
//            headNodePtr == nullptr
// RetVal:    None
// MetCall:   deletePostOrder(NodeGen<T>*)
template <class typeT>
void Prototype<typeT>::obliviate() {
   deletePostOrder(this->rootPtr);
}

// (+) --------------------------------|
// #printout()
//-------------------------------------|
// Desc:    Prints the tree to console
// Param:   None
// PreCons: None
// PosCons: None
// RetVal:  None
// MetCall: traversePreOrder() - Optional
//          traverseInOrder - Prints tree in an in-order traversal
//          traversePostOrder() - Optional
template <class typeT>
void Prototype<typeT>::printout() const {
   traversePreOrder();
   cout << endl;
   traverseInOrder();
   cout << endl;
   traversePostOrder();
   cout << endl;
} // Closing printout()

// (+) --------------------------------|
// #setDelete()
//-------------------------------------|
// Desc:    Finds a node with matching data and sets its deletion flag to true
// Params:  typeT - The target data to find
// PreCons: None
// PosCons: Target node has been set to deleted or nothing happens
// RetVal:  True - 'Deletion' successful
//          False - Node not found
// MetCall: retrieve()
template <class typeT>
bool Prototype<typeT>::setDelete(typeT someData) {
   NodeGeneric<typeT>* targetNodePtr = this->retrieve(someData);
   if (targetNodePtr != nullptr) {
      targetNodePtr->isDeleted = true;
      return(true);
   }
   return(false);
} // Closing setDelete()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #Prototype()
//-------------------------------------|
// Desc:    Default constructor for the Prototype class
// Params:  None
// PreCons: None
// PosCons: An empty binary tree has been allocated
// RetVal:  None
// MetCall: None
template <class typeT>
Prototype<typeT>::Prototype() {
   this->treeData = "NameGoesHere";
   this->rootPtr = nullptr;
}

// (+) --------------------------------|
// #Prototype(<T>)
//-------------------------------------|
// Desc:    Constructor of the Prototype class from a file address
// Params:  string arg1 - A file address (name)
// PreCons: None
// PosCons: A binary tree of strings has been generated
// RetVal:  None
// MetCall: insert()
//          ifstream.open()
//          ifstream.close()
template <class typeT>
Prototype<typeT>::Prototype(std::string fileAddress) {
   treeData = "NameGoesHere";
   rootPtr = nullptr;
   // String for storing a single word
   string aWord;
   // Generate the Input File Stream (ifstream) object
   ifstream fileInputObj;
   fileInputObj.open(fileAddress);
   // Confirm that file was opened. Report otherwise if not.
   if (!fileInputObj) {
      cout << "Unable to open file: '" << fileAddress << "'" << endl << endl;
   }
   // Read the file
   while (fileInputObj >> aWord) {
      this->insert(aWord);
   }
   // After reading from the file, close the stream
   fileInputObj.close();
}

// (+) --------------------------------|
// #~Prototype()
//-------------------------------------|
// Desc:    Default destructor of the Prototype class
// Params:  None
// PreCons: None
// PosCons: All memory allocated for BST Nodes has been deallocated
// RetVal:  None
// MetCall: obliviate()
template <class typeT>
Prototype<typeT>::~Prototype() {
   this->obliviate();
}


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #setField()
//-------------------------------------|
// Desc:    Sets value of <Some Field> to the received argument
// Param:   arg1 dataType& someData - The receiving stream
// PreCons: someField must be declared
// PosCons: someField has been assigned someData
// RetVal:  None (void)
// MetCall: None
template <class typeT>
void Prototype<typeT>::setField(const typeT& someData) {
   someField = someData;
}

// (+) --------------------------------|
// #getValue()
//-------------------------------------|
// Desc:    Custom behavior for the stream insertion operator
// Param:   arg1 ostream& ostr - The receiving stream
//          arg2 ThisClass& someObj - The object being inserted
// PreCons: NULL
// PosCons: NULL
// RetVal:  ostream& - The appended ostream object
// MetCall: NULL
template <class typeT>
std::string Prototype<typeT>::getValue() const {
   return treeData;
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATOR OVERLOADS (+)
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// (+) --------------------------------|
// #operator=()
//-------------------------------------|
// Desc:    Custom behavior for the stream insertion operator
// Param:   arg1 ostream& ostr - The receiving stream
//          arg2 ThisClass& someObj - The object being inserted
// PreCons: NULL
// PosCons: NULL
// RetVal:  Prototype& - The appended ostream object
// MetCall: NULL
template <class typeT>
Prototype<typeT>& Prototype<typeT>::operator=(const Prototype<typeT>& RHarg) {
   // Check to see if "this" and "RHarg" are the same thing (by address)
   if (this == &RHarg) {
      // If the same, bail.
      return *this;
   }
   // Else, the two linked lists are different...

   // < Assignment Implementation Goes Here >

   // Send the appended Context back
   return *this;
} // Closing operator= overload



// (+) --------------------------------|
// #operator<<()
//-------------------------------------|
// Desc:    Custom behavior for the stream insertion operator
// Param:   arg1 ostream& ostr - The receiving stream
//          arg2 ThisClass& someObj - The object being inserted
// PreCons: NULL
// PosCons: NULL
// RetVal:  ostream& - The appended ostream object
// MetCall: NULL
template <class typeT>
std::ostream& operator<< (std::ostream& ostr, const Prototype<typeT>& someObj) {

   // < Ostream<< Implementation Goes Here >

   return ostr;
} // Closing operator<< overload

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of file - Prototype.cpp
