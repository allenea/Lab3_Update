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
using namespace std;


class LLPQ {
	friend class LLHuff; //added
	LLNode *first;
	LLNode *last;
	int size;

public:
	LLPQ();
	~LLPQ();
	//Function Declarations
	void printLLPQ();
	void addFirst(char x, string co = "");
	void addAtFirst(char x, string co ="");
	LLNode *remFirst();
	string findCode(char k);
	void sortLL();
	void insertUnique(char c);
	void insertInOrder(LLNode *n);

};

#endif /* LLPQ_HPP_ */
