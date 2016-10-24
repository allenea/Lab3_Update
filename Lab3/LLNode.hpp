/*
 * LLNode.hpp
 *
 *  Created on: Oct 5, 2016
 *      Author: ericallen
 */

#ifndef LLNODE_HPP_
#define LLNODE_HPP_
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class LLNode {
	friend class LLPQ;
	friend class LLHuff;
	//attributes
	char symbol;
	string code;
	int freq;

	LLNode *next;
	LLNode *prev;
	LLNode *left;
	LLNode *right;

public:
	LLNode(char k); //, string code
	~LLNode();
	//getters
	char getSymbol();
	string getCode();
	int getFreq();
};




#endif /* LLNODE_HPP_ */
