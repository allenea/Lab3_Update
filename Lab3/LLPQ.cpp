/*
 * LLPQ.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: ericallen
 */

#include "LLPQ.hpp"
#include "LLNode.hpp"
#include <string>
#include <iostream>
using namespace std;

LLPQ::LLPQ() {
	//define pointers
	first = NULL;
	last = NULL;
	size = 0;	//set size to 0

}

LLPQ::~LLPQ() { //destructor LLPQ
	LLNode *tmp = first;
	while (first != NULL) { //while not null
		tmp = first->next;
		delete first; //delete
		first = tmp;
		size--; //decrease size as you remove.
	}
	first = NULL; //set to null
	last = NULL; //set to null
}

void LLPQ::printLLPQ(){
// prints out the linked list/ priority queue
	LLNode *tmp = first; //set a tmp node to first value
	while (tmp != NULL) { //while not null
		cout << tmp->symbol << "->"; //add arrow between symbols
		tmp = tmp->next; //index through to next.
	}
	cout << endl;

}

void LLPQ::addFirst(char x, string co){
	/*
	 * //adds the very first character node to the linked list, along with an //original default code value set to -1.
	 *
	 */

	LLNode *node = new LLNode(x); // create a node
	first = node; //set nod to first
	first->code = co; // set the value of code (in stringL) from input parameter to the code of first node.
	last = first; //set first to last since only node in list
	size = 1; //set size =1
	//delete node;
}

void LLPQ::addAtFirst(char x, string co){
/*
 * add a new node to the beginning of the linked list (modifying the first
 * pointer and the size, and setting the code field to co, (default = -1).
 *
 */
	if(size==0){// if no linked list
		addFirst(x, co); // call function to addFirst and pass in the char and string
	}
	else{ // if not empty linked list
		LLNode *node = new LLNode(x);
		node->next = first;
		node->prev = NULL;
		first->prev = node;
		first = node;
		first->code = co; // set the value of code (in string) from input parameter to the code of first node.
		size++;
		//delete node;
	}

}

LLNode* LLPQ::remFirst(){
// removes the first node from the list (to be used in creating the Huffman code
	if(size == 0){
		return NULL;
	}
	LLNode *node = first; //points to first
	first = first->next;

	first->prev = NULL;

	size--;// decrease size

	//test to see if node == null... IF NULL... BAD WRONG.

	return node;
}


string LLPQ::findCode(char k){
// goes through the linked list, finds the character k, and returns the code associated with that node– used to
//translate a file once you have the code (Note that if we had studied hash tables/maps, this would be so much easier using them
	LLNode *tmp = first;
	while(tmp->symbol != k){
		tmp = tmp->next;
	}

	if(tmp->symbol == k){
		string fCode = tmp->code;
		return fCode;

	}

	cout<<tmp<<endl;
	// see if it works under normal circumstances.. then check if character not found


	return NULL;
};


void LLPQ::sortLL(){
// sorts your linked list, based on the counts in the nodes (so the character that occurred the least frequently
// will be at the beginning of the list, and the character that occurred most frequently will be at the end of the list.
	LLNode *tmp = first;
	LLNode *tmp2;
	LLNode *tmp3;
	int count;
	while(tmp->next != NULL){
		count = tmp->getFreq();
		tmp3 = tmp;
		tmp2 = tmp->next;
		while(tmp2 != NULL){
			if(tmp2->getFreq() < count){
				count = tmp2->getFreq();
				tmp3 = tmp2;
			}//if
			tmp2 = tmp2->next;
		}//innerWhile
		tmp = tmp->next;

	}//outerWhile
//sortLL

}
void LLPQ::insertUnique(char c){
// inserts only unique characters into the linked list.  If the character is already in the linked list,
// it increases the count of that character
	LLNode *tmp = first;

	for(int num = 0; num<size;num++){
		if(tmp->getSymbol() == c){ // try tmp->symbol
			//tmp->code = "c";
			tmp->freq++;
			return;
		}
		tmp = tmp->next;
	}
	addAtFirst(c,"");
	//LLNode *node = new LLNode(c);
	//insertInOrder(node);
}

void LLPQ::insertInOrder(LLNode *n){
	//char char1 = n->symbol;
	//sortLL(); //assuming sort is already being called in main (Yarrington gave us)
	LLNode *tmp = first;
	//char sym = n->symbol; //unused
	int freqT = n->freq;
	if (freqT == 0){
		addAtFirst(n->getSymbol(), n->getCode());
	}
	if(freqT >0){ // if there is more than 1.
		while(tmp->next->getFreq() <= freqT){
			tmp = tmp->next;
		}
		LLNode *tmp2 = tmp->next;
		tmp->next = new LLNode(n->getSymbol());
		tmp->next->next = tmp2;
		size ++;
	}
}
