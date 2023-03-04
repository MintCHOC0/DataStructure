#include <iostream>
#include "header.h"

using std::cout; using std::endl;

int main() {
	CircularQueue cq;
	cq.showState();

	cout << "enqueue()" << endl;
	for (int i = 0; i < 7; i++) { cq.enqueue(i * 10 + 10); }
	cout << endl;

	cq.showState();

	cout << "Dequeue & Enqueue" << endl;
	cout << "dequeue() : " << cq.dequeue() << endl;
	cq.enqueue(100);
	cout << endl;

	cq.showState();

	cout << "dequeue()" << endl;
	for (int i = 0; i < 7; i++) { cout << cq.dequeue() << endl; }

	return 0;
} 