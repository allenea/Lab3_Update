/*
 * LLPQ.hpp
 *
 *  Created on: Oct 5, 2016
 *      Author: ericallen
 */

#ifndef LLPQ_HPP_
#define LLPQ_HPP_
#include "LLNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;


class LLPQ {
	// friend class
	friend class LLHuff; //added
	//Pointers
	LLNode *first;
	LLNode *last;
	//attributes
	int size;

public:
	LLPQ();
	~LLPQ();
	//Function Declarations
	void printLLPQ();
	void addFirst(char x, string co = ""); // co = empty string
	void addAtFirst(char x, string co ="");// co = empty string
	LLNode *remFirst();
	string findCode(char k);
	void sortLL();
	void insertUnique(char c);
	void insertInOrder(LLNode *n);

};

#endif /* LLPQ_HPP_ */
