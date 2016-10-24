/*
 * LLNode.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: ericallen
 */


#include "LLNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//make
LLNode::LLNode(char k) {//
	symbol = k; //character
	code = "";
	freq = 0;
	next = NULL;
	prev = NULL;
	right = NULL;
	left = NULL;
}

//delete
LLNode::~LLNode() {
	if (next != NULL || prev != NULL) {
		cout << "deleting this LLNode may cause a memory leak" << endl;
	}
}

char LLNode::getSymbol(){
	return symbol;
}

string LLNode::getCode(){
	return code;
}

int LLNode::getFreq(){
	return freq;
}
//


