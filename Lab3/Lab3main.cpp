/*
 * Lab3main.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: ericallen
 */


#include <stdio.h>
#include <iostream>
#include "LLNode.hpp"
#include "LLHuff.hpp"
#include "LLPQ.hpp"
using namespace std;

int main() {
	cout << "reading file" << endl;
	LLHuff code("tests.txt");
	code.ReadFile();
	code.pq->printLLPQ();
	code.pq->sortLL();
	code.pq->printLLPQ();
	code.MakeHuff();
	code.compressFile();
	code.ReadAscii();
	return 0;
}

