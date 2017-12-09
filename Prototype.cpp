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
Copyright (c) <year>, <copyright holder>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.
*/

//-------------------------------------|
// Abbreviations
//-------------------------------------|
// Arg     == Argument
// Char    == Character
// Dbl     == Double
// Desc    == Description
// EQ      == Equals
// Info    == Information
// Int     == Integer
// Invar   == Invariant
// L       == Left
// LH      == Left-Hand
// MetCall == Method Call
// Obj     == Object
// Param   == Parameter
// PosCond == Postcondition
// Precond == Precondition
// Ptr     == Pointer
// R       == Right
// RH      == Right-Hand
// Ret     == Return
// Str     == String
// T       == Type
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

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// Necessary for file stream operations
#include <fstream>

// Field and method declarations for the Collector class
#include "Collector.h"

using namespace std;


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|
//
// Do not redeclare these variables in the .cpp.
// Included here only for reference
// See associated .h file for variable declarations

//-------------------------------------|
// #someVar1
//-------------------------------------|
// Desc:
// Invar Info:  String holding the name or identifier of this tree.
//     template <class typeT>
//     string treeData = "";

//-------------------------------------|
// #someVar2
//-------------------------------------|
// Description: The target node of this linked list
// Invariants:  String holding the name or identifier of this tree.
//     template <class typeT>
//     string treeData = "";



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|




//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #deletePostOrder()
//-------------------------------------|
// Description:      Helper method for post-order deletion method
// Parameters:       None
// Preconditions:    None
// Postconditions:   All nodes have been deleted
// Return value:     True - Signal of successful deletion traversal
//                   False - No deletion possible (empty tree)
// Functions called: deletePostOrder()
template <class typeT>
bool Collector<typeT>::deletePostOrder() {
   // Check for empty tree
   if (rootPtr == nullptr) {
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (deletePostOrder(rootPtr));
   }
}

//-------------------------------------|
// #deletePostOrder()
//-------------------------------------|
// Description:      Recursive method for post-order deletion method
// Parameters:       NodeGeneric* - The target node to be traversed and deleted
// Preconditions:    None
// Postconditions:   All nodes in this subtree have been deleted
// Return value:     True - Signal of successful deletion traversal
// Functions called: deletePostOrder()
template <class typeT>
bool Collector<typeT>::deletePostOrder(NodeGeneric<typeT>* thisNode) {
   // Left traverse
   if (thisNode->leftPtr != nullptr) {
      deletePostOrder(thisNode->leftPtr);
   }
   // Right traverse
   if (thisNode->rightPtr != nullptr) {
      deletePostOrder(thisNode->rightPtr);
   }
   // Visit (delete)
   delete thisNode;
   return(true);
}

//-------------------------------------|
// #obliviate()
//-------------------------------------|
// Description:      Deletes all nodes within the BST
// Parameters:       None
// Preconditions:    None
// Postconditions:   All tree nodes have been deleted.
//                   headNodePtr == nullptr
// Return value:     None
// Functions called: deletePostOrder()
template <class typeT>
void Collector<typeT>::obliviate() {
   deletePostOrder();
}

//-------------------------------------|
// #traversePreOrder()
//-------------------------------------|
// Description:      Helper method for pre-order traversal method
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     True - Signal of successful recursive traversal
//                   False - No traversal possible
// Functions called: traversePreOrder()
template <class typeT>
bool Collector<typeT>::traversePreOrder() {
   // Check for empty tree
   if (rootPtr == nullptr) {
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (traversePreOrder(rootPtr));
   }
}

//-------------------------------------|
// #traversePreOrder(NodeGeneric*)
//-------------------------------------|
// Description:      Recursive pre-order traversal method
// Parameters:       NodeGeneric* arg1 - Pointer to the node to traverse
// Preconditions:    None
// Postconditions:   None
// Return value:     True - Signal of successful recursive traversal
// Functions called: traversePreOrder()
//                   visit()
template <class typeT>
bool Collector<typeT>::traversePreOrder(NodeGeneric<typeT>* thisNode) {
   visit(thisNode);
   if (thisNode->leftPtr != nullptr) {
      traversePreOrder(thisNode->leftPtr);
   }
   if (thisNode->rightPtr != nullptr) {
      traversePreOrder(thisNode->rightPtr);
   }
   return(true);
}

//-------------------------------------|
// #traverseInOrder()
//-------------------------------------|
// Description:      Helper method for in-order traversal method
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     True - Signal of successful recursive traversal
//                   False - No traversal possible
// Functions called: traverseInOrder()
template <class typeT>
bool Collector<typeT>::traverseInOrder() {
   // Check for empty tree
   if (rootPtr == nullptr) {
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (traverseInOrder(rootPtr));
   }
}

//-------------------------------------|
// #traverseInOrder(NodeGeneric*)
//-------------------------------------|
// Description:      Recursive in-order traversal method
// Parameters:       NodeGeneric* arg1 - Pointer to the node to traverse
// Preconditions:    None
// Postconditions:   None
// Return value:     True - Signal of successful recursive traversal
// Functions called: traverseInOrder()
//                   visit()
template <class typeT>
bool Collector<typeT>::traverseInOrder(NodeGeneric<typeT>* thisNode) {
   if (thisNode->leftPtr != nullptr) {
      traverseInOrder(thisNode->leftPtr);
   }
   visit(thisNode);
   if (thisNode->rightPtr != nullptr) {
      traverseInOrder(thisNode->rightPtr);
   }
   return(true);
}

//-------------------------------------|
// #traversePostOrder()
//-------------------------------------|
// Description:      Helper method for post-order traversal method
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     True - Signal of successful recursive traversal
//                   False - No traversal possible
// Functions called: traversePostOrder()
template <class typeT>
bool Collector<typeT>::traversePostOrder() {
   // Check for empty tree
   if (rootPtr == nullptr) {
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (traversePostOrder(rootPtr));
   }
}

//-------------------------------------|
// #traversePostOrder(NodeGeneric*)
//-------------------------------------|
// Description:      Recursive post-order traversal method
// Parameters:       NodeGeneric* arg1 - Pointer to the node to traverse
// Preconditions:    None
// Postconditions:   None
// Return value:     True - Signal of successful recursive traversal
// Functions called: traversePostOrder()
//                   visit()
template <class typeT>
bool Collector<typeT>::traversePostOrder(NodeGeneric<typeT>* thisNode) {
   if (thisNode->leftPtr != nullptr) {
      traversePostOrder(thisNode->leftPtr);
   }

   if (thisNode->rightPtr != nullptr) {
      traversePostOrder(thisNode->rightPtr);
   }

   visit(thisNode);
   return(true);
}

//-------------------------------------|
// #visit(NodeGeneric)
//-------------------------------------|
// Description:      Visits the node indicated by sending the nodeData content to cout.
// Parameters:       NodeGeneric* - The target node being visited
// Preconditions:    None
// Postconditions:   None
// Return value:     None
// Functions called: None
template <class typeT>
void Collector<typeT>::visit(NodeGeneric<typeT>* thisNodePtr) const {
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
//       PUBLIC FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #find(typeT)
//-------------------------------------|
// Finds a node with an equal value of the string argument
// Parameters:       typeT - The data to search for
// Preconditions:    None
// Postconditions:   None
// Return value:     True - An equivalent node was found
//                   False - An equivalent node was not found
// Functions called: None
template <class typeT>
bool Collector<typeT>::find(typeT someData) const {
   // If the tree is empty, do nothing
   if (rootPtr == nullptr) {
      // cout << "No value found. This tree is empty." << endl; // DEBUG
      return(false);
   }
   // Otherwise, start at the rootPtr
   else {
      NodeGeneric<typeT>* currPtr = rootPtr;
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

//-------------------------------------|
// #insert(typeT)
//-------------------------------------|
// Description:      Attempts to insert data of typeT to the tree
// Parameters:       typeT arg1 - The data to insert
// Preconditions:    None
// Postconditions:   Data has been found or search has run off the tree
//                   Data has been assigned to an appropriate node of the tree
// Return value:     True - Data was not found in the tree. Assigned off a leaf.
//                   False - Data found in the tree, assignment still occured
// Functions called: NodeGeneric()
template <class typeT>
bool Collector<typeT>::insert(typeT& someData) { // Receiving by reference
   NodeGeneric<typeT>* currNodePtr = rootPtr;
   NodeGeneric<typeT>* prevNodePtr = nullptr;
   // Initial case: If tree is empty, insert a new node at the root
   if (rootPtr == nullptr) {
      rootPtr = new NodeGeneric<typeT>(someData);
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

//-------------------------------------|
// #printout()
//-------------------------------------|
// Description:      Prints the tree to console
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     None
// Functions called: traversePreOrder() - Optional
//                   traverseInOrder - Prints tree in an in-order traversal
//                   traversePostOrder() - Optional
template <class typeT>
void Collector<typeT>::printout() {
   // traversePreOrder();
   // cout << endl;
   traverseInOrder();
   cout << endl;
   // traversePostOrder();
   // cout << endl;
} // Closing ptintout()

//-------------------------------------|
// #setDelete()
//-------------------------------------|
// Description:      Finds a node with matching data and sets its deletion flag to true
// Parameters:       typeT - The target data to find
// Preconditions:    None
// Postconditions:   Target node has been set to deleted or nothing happens
// Return value:     True - 'Deletion' successful
//                   False - Node not found
// Functions called: retrieve()
template <class typeT>
bool Collector<typeT>::setDelete(typeT someData) {
   NodeGeneric<typeT>* targetNodePtr = this->retrieve(someData);
   if (targetNodePtr != nullptr) {
      targetNodePtr->isDeleted = true;
      return(true);
   }
   return(false);
} // Closing setDelete()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #Collector()
//-------------------------------------|
// Default constructor for the Collector class
// Parameters:       None
// Preconditions:    None
// Postconditions:   An empty binary tree has been allocated
// Return value:     None
// Functions called: None
template <class typeT>
Collector<typeT>::Collector() {
   treeData = "NameGoesHere";
   this->rootPtr = nullptr;
}

//-------------------------------------|
// #Collector(string)
//-------------------------------------|
// Constructor of the Collector class from a file address
// Parameters:       string arg1 - A file address (name)
// Preconditions:    None
// Postconditions:   A binary tree of strings has been generated
// Return value:     None
// Functions called: insert()
//                   ifstream.open()
//                   ifstream.close()
template <class typeT>
Collector<typeT>::Collector(string fileAddress) {
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

//-------------------------------------|
// #~Collector()
//-------------------------------------|
// Default destructor of the Collector class
// Parameters:       None
// Preconditions:    None
// Postconditions:   All memory allocated for BST Nodes has been deallocated
// Return value:     None
// Functions called: obliviate()
template <class typeT>
Collector<typeT>::~Collector() {
   this->obliviate();
}


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #setField()
//-------------------------------------|
// Desc:    Sets value of <Some Field> to the received argument
// Param:   arg1 dataType& someData - The receiving stream
// PreCons: someField must be declared
// PosCons: someField has been assigned someData
// RetVal:  None (void)
// MetCall: None
void Prototype::setField(const dataType& someData) {
   someField = someData;
}

//-------------------------------------|
// #setField(<templated>)
//-------------------------------------|
// Desc:    Custom behavior for the stream insertion operator
// Param:   arg1 ostream& ostr - The receiving stream
//          arg2 ThisClass& someObj - The object being inserted
// PreCons: NULL
// PosCons: NULL
// RetVal:  ostream& - The appended ostream object
// MetCall: NULL
template <class typeT>
string Collector<typeT>::getValue() const {
   return treeData;
}

//-------------------------------------|
// #setField()
//-------------------------------------|
// Desc:    Custom behavior for the stream insertion operator
// Param:   arg1 ostream& ostr - The receiving stream
//          arg2 ThisClass& someObj - The object being inserted
// PreCons: NULL
// PosCons: NULL
// RetVal:  ostream& - The appended ostream object
// MetCall: NULL
template <class typeT>
string Collector<typeT>::getValue() const {
   return treeData;
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATOR OVERLOADS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #operator=()
//-------------------------------------|
// Desc:    Custom behavior for the stream insertion operator
// Param:   arg1 ostream& ostr - The receiving stream
//          arg2 ThisClass& someObj - The object being inserted
// PreCons: NULL
// PosCons: NULL
// RetVal:  Prototype& - The appended ostream object
// MetCall: NULL
Prototype& Prototype::operator=(const Prototype& RHarg) {
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



//-------------------------------------|
// #operator<<()
//-------------------------------------|
// Desc:    Custom behavior for the stream insertion operator
// Param:   arg1 ostream& ostr - The receiving stream
//          arg2 ThisClass& someObj - The object being inserted
// PreCons: NULL
// PosCons: NULL
// RetVal:  ostream& - The appended ostream object
// MetCall: NULL
ostream& operator<< (ostream& ostr, const Prototype& someObj) {

   // < Ostream<< Implementation Goes Here >

   return ostr;
} // Closing operator<< overload



//-------------------------------------|
// #operator<<(<templated>)
//-------------------------------------|
// Desc:    Custom behavior for the stream insertion operator (templated)
// Param:   arg1 ostream& ostr - The receiving stream
//          arg2 ThisClass& someObj - The object being inserted
// PreCons: NULL
// PosCons: NULL
// RetVal:  ostream& - The appended ostream object
// MetCall: NULL
template <typename T>
ostream& operator<< (ostream& ostr, ThisClass<T>& someObj const) {

   // < Ostream<< Implementation Goes Here >

   return ostr;
} // Closing operator<< overload (templated)

//-------------------------------------|
// End Student Code
//-------------------------------------|

// End of Template.cpp
