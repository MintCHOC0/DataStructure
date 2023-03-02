#include "header.h"
using std::cout; using std::endl;

int main() {
	MoveQueue mq;

	cout << "INIT : " << endl;
	cout << "isEmpty() : " << mq.isEmpty() << endl;
	cout << "Size : " << mq.getSize() << endl;
	cout << "Front : " << mq.getFront() << endl;
	cout << "Size : " << mq.getSize() << endl << endl;
	
	cout << "Enqueue 3 times" << endl << endl;

	mq.enqueue(10);
	mq.enqueue(20);
	mq.enqueue(30);

	cout << "NOW : " << endl;
	cout << "Front : " << mq.getFront() << endl;
	cout << "Size : " << mq.getSize() << endl << endl;

	cout << "Dequeue : " << mq.dequeue() << endl;
	cout << "NOW : " << endl;
	cout << "Front : " << mq.getFront() << endl;
	cout << "Size : " << mq.getSize() << endl << endl;

	cout << "Enqueue" << endl;
	for (int i = 0; i < 5; i++) { mq.enqueue(100 + i * 10); }
	cout << "NOW : " << endl;
	cout << "Front : " << mq.getFront() << endl;
	cout << "Size : " << mq.getSize() << endl << endl;

	for (int i = 0; i < 5; i++) {
		cout << "Dequeue : " << mq.dequeue() << endl;
	}

	return 0;
} 