/*
 * LLHuff.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: ericallen
 */
#include <iostream>
#include <stdlib.h>
#include "LLHuff.hpp"
#include "LLPQ.hpp"
#include "LLNode.hpp"
#include <fstream>

using namespace std;

LLHuff::LLHuff(string f){
	file = f;
	size = 0;
	root = NULL;
	ascii = NULL;
	pq = NULL;
}

LLHuff::~LLHuff(){
	//write code
}
void LLHuff::ReadFile() {
	ifstream infile(file.c_str(),ios::in);     // open file
	cerr << "file read" << endl;
	char k;
	while (infile.get(k)) {          // loop getting single characters
		cerr << "got " << k << "\t";
		pq->insertUnique(k);
		cerr << "inserted" << endl;

	}
	infile.close();
}



void LLHuff::ReadAscii() {
	cout << file << endl; //file name
	ifstream infile("asciitable.txt",ios::in);     // open file
	char ch;
	string asciicode;
	if (!infile.is_open()) {
		return;
	}
	infile >> asciicode; //input file
	pq->addFirst(' ',asciicode);
	infile >> asciicode;
	while (infile>>ch) {          // loop getting single characters
		cout << ch;
		infile>>asciicode; // gets entire word (code)
		cout << asciicode << endl;
		pq->addAtFirst(ch,asciicode);
	}
	cout << endl;
	infile.close();

	/////////////////////////////////////
	ifstream infile2(file.c_str(),ios::in); // open file for reading
	ofstream outfile("asciivsn.txt",ios::out);
	char k;
	string comp;
	while (infile2.get(k)) {          // loop getting single characters
		cout << k;
		comp = pq->findCode(k);
		if (comp == "") {
			cout << "ERROR WITH " << k << endl;
		}
		else {
			cout << k << ":" << comp << endl; // output file character :comp (code)
			outfile << comp << " ";
		}
	}
	cout << endl;
	infile2.close();//close input file
	outfile.close();//close output file
}



void LLHuff::MakeHuff(){

	while(pq->size > 1){ //while size is greater than 1
		LLNode *tmp = pq->remFirst();//remove
		LLNode *tmp2 = pq->remFirst();//remove
		LLNode *c = new LLNode('*');//string
		c->freq = tmp->freq +tmp2->freq; //gets frequency
		c->left = tmp; //to left
		c->right = tmp2;//to right
		pq->insertInOrder(c);//insertInOrder


	}
	root = pq->first;
}


void LLHuff::compressFile(){

	ReadFile();// read in file
	ofstream compressed;
	compressed.open("compressed.txt"); //open compressed
	ifstream infile(file.c_str(), ios::in);
	char k;
	while (infile.get(k)){//while implementing find code
		string path;

		FindCode(root, path);//FindCode

	}

}

void LLHuff::FindCode(LLNode* root, string path){

	LLNode* tmp = pq->first;
	while(tmp->code == "-1"){ //while code string  "-1"
		tmp = tmp->next; //move to next, set tmp = to that.
	}

	path = path + string(tmp->code); //increase path
	tmp->code = path;
	if (root->left != NULL){ //if left not NULL
		FindCode(root->left, path);//FindCode
	}
	if (root->right != NULL){ //If right not NULL
		FindCode(root->right, path);//FindCode
	}

}


