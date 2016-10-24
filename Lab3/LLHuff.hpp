/*
 * LLHuff.hpp
 *
 *  Created on: Oct 19, 2016
 *      Author: ericallen
 */

#ifndef LLHuff_HPP_
#define LLHuff_HPP_
#include "LLNode.hpp" //had commented out
#include "LLPQ.hpp"


#include <fstream>      // std::ifstream
#include <iostream>
#include <stdlib.h>
using namespace std;

class LLHuff {
	string file;
	LLNode *root;
	int size;

public:
	LLPQ *pq;  //priority queue list of character nodes, made in first part
	LLPQ *ascii;  //linked list of characters and their corresponding asci codes, read in from the asci.txt file
	LLHuff(string f);  //f is the name of the file you’ll be creating a Huffman code for
	~LLHuff();

	void ReadFile();
	//Opens, reads in a file character by character, and creates the priority queue


	void MakeHuff();//takes the priority queue and makes the Huffman tree out of it as shown above,
	//setting the root to the last remaining node created.

	void FindCode(LLNode *root, string path);
//finds the code for each leaf node in the tree.  A few notes about this one:  first, the path starts at 1,
//and is multiplied by 10 each iteration through to get an accurate integer representation of the path.
//I wrote this function as a recursive one, and I STRONGLY recommend you do as well.  All codes for every leaf can
//be found in one pass of the tree with recursion.
//One final note:  I made a new linked list (assigned to pq, since I was done with the old pq, with each leaf node
//and its code being added to the linked list.  This linked list of characters and codes will be used to create the
//compressed version of the file, in which each character is replaced with its corresponding code.  This would be a
//lot easier with a hash table/map, but we haven’t worked with them yet.  If you want to make a new field and create
//a hash table for this part, I am fine with that.



	void compressFile();
//Opens the original file for reading and a new, compressed file for writing.
//Looks up each character read in from the original file and writes out its corresponding
//code in the compressed file.

	void ReadAscii() ;
//reads in the asci code from the asci.txt file, and then takes the regular file
//and converts it to the ascii code and saves that file.
//I’m including the ReadFile method (which should be in your LLHuff.cpp file) below:


};

#endif /* LLHuff_HPP_ */
