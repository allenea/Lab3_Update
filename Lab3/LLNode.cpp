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
	symbol = k;  //character
	code = "";  //empty string
	freq = 0;  //0
	//POINTERS
	next = NULL;
	prev = NULL;
	right = NULL;
	left = NULL;
}

//delete/destructor
LLNode::~LLNode() {
	if (next != NULL || prev != NULL) {
		cout << "deleting this LLNode may cause a memory leak" << endl;
	}
}


//Get Symbol-char
char LLNode::getSymbol(){
	return symbol;
}
//GET Code - string
string LLNode::getCode(){
	return code;
}

//GET Freq - int
int LLNode::getFreq(){
	return freq;
}



