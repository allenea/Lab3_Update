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

void LLHuff::ReadFile(){
	ifstream infile(file.c_str(),ios::in);
	cerr << "file read" << endl;
	char k;
	while(infile.get(k)){
		cerr << "got " << k << "\t";
		pq->insertUnique(k);
		cerr << "inserted" << endl;
	}
	infile.close();
}


void LLHuff::ReadAscii() {
	cout << file << endl;
	ifstream infile("asciitable.txt",ios::in);     // open file
	char ch;
	string asciicode;
	if (!infile.is_open()) {
		return;
	}
	infile >> asciicode;
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
			cout << k << ":" << comp << endl;
			outfile << comp << " ";
		}
	}
	cout << endl;
	infile2.close();
	outfile.close();
}



void LLHuff::MakeHuff(){

	while(pq->size > 1){
		LLNode *tmp = pq->remFirst();
		LLNode *tmp2 = pq->remFirst();
		LLNode *c = new LLNode('*');
		c->freq = tmp->freq +tmp2->freq;
		c->left = tmp;
		c->right = tmp2;
		pq->insertInOrder(c);


	}
	root = pq->first;
}


void LLHuff::compressFile(){

	ReadFile();
	ofstream compressed;
	compressed.open("compressed.txt");
	ifstream infile(file.c_str(), ios::in);
	char k;
	while (infile.get(k)){//while implementing find code
		string path;

		FindCode(root, path);

	}

}

void LLHuff::FindCode(LLNode* root, string path){

	LLNode* tmp = pq->first;
	while(tmp->code == "-1"){
		tmp = tmp->next;
	}

	path = path + string(tmp->code);
	tmp->code = path;
	if (root->left != NULL){
		FindCode(root->left, path);
	}
	if (root->right != NULL){
		FindCode(root->right, path);
	}

}


