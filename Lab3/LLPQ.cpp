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
	first = NULL;
	last = NULL;
	size = 0;

}

LLPQ::~LLPQ() {
	LLNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size--;
	}
	first = NULL;
	last = NULL;
}

void LLPQ::printLLPQ(){
// prints out the linked list/ priority queue
	LLNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->symbol << "->";
		tmp = tmp->next;
	}
	cout << endl;

}

void LLPQ::addFirst(char x, string co){
	/*
	 * //adds the very first character node to the linked list, along with an //original default code value set to -1.
	 *
	 */
	LLNode *node = new LLNode(x);
	first = node;
	first->code =-1;
	last = first;
	size = 1;
	first->code = co;
	delete node;
}

void LLPQ::addAtFirst(char x, string co){
/*
 * add a new node to the beginning of the linked list (modifying the first
 * pointer and the size, and setting the code field to co, (default = -1).
 *
 */
	if(size==0){
		addFirst(x, co);
	}

	LLNode *node = new LLNode(x);
	node->next = first;
	node->prev = NULL;
	first->prev = node;
	first = node;
	node->code = co;
	size++;

}

LLNode *LLPQ::remFirst(){
// removes the first node from the list (to be used in creating the Huffman code
	LLNode *node = first;
	first = first->next;
	first->prev = NULL;
	size--;
	delete node;


}


string LLPQ::findCode(char k){
// goes through the linked list, finds the character k, and returns the code associated with that node– used to
//translate a file once you have the code (Note that if we had studied hash tables/maps, this would be so much easier using them
	LLNode *tmp = first;
	while(tmp->symbol != k){
		tmp = tmp->next;
	}

	if(tmp->symbol == k){
		//tmp = tmp->code;
	}
	cout<<tmp<<endl;
}


void LLPQ::sortLL(){
// sorts your linked list, based on the counts in the nodes (so the character that occurred the least frequently
// will be at the beginning of the list, and the character that occurred most frequently will be at the end of the list.


}
void LLPQ::insertUnique(char c){
// inserts only unique characters into the linked list.  If the character is already in the linked list,
// it increases the count of that character
	LLNode newtmp = LLNode(c);
	int count = 0;
	sortLL();
	for(int i = 0; i < size; i++){
/*		while(findCode(c) != newtmp->symbol){
			newtmp = newtmp->next;
		if(findCode(c) == newtmp){
			count++;
			newtmp = newtmp->next;

		}
		else{
			last = last->prev;
			last = newtmp;
			count = 1;
		}
	}
	}

	freq = count;*/
	}
}
void LLPQ::insertInOrder(LLNode *n){
	//char char1 = *n->symbol;
	//sort(*n);
	LLNode *tmp = first;
	sortLL();
	char sym = n->symbol;
	if (size == 0){
		tmp->next = tmp;
		*tmp = sym;
	}
	/*
	for (int i = 0; i < size; i++){
		if(sym < n[i++]){
			tmp = tmp->right;

		}
		else if(sym == LLNode[i++]){
			tmp->next = tmp;
			tmp = sym;
		}

	}
	*/
}
