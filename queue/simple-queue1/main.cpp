#include "header.h"

int main() {
	Queue queue;

	cout << "INIT : " << queue.getSize() << endl;
	cout << "ENQUEUE" << endl;
	
	for (int i = 0; i < 7; i++) { queue.enqueue(10 * i + 10); }
	
	
	cout << "NOW SIZE : " << queue.getSize() << endl;
	cout << "NOW FRONT : " << queue.getFront() << endl;
	cout << endl;
	
	
	cout << "DEQUEUE : " << queue.dequeue() << endl;
	cout << "NOW SIZE : " << queue.getSize() << endl;
	cout << "NOW FRONT : " << queue.getFront() << endl;
	cout << endl;
	
	
	cout << "ENQUEUE" << endl;
	queue.enqueue(100); // MAX QUEUE
	cout << "NOW SIZE : " << queue.getSize() << endl;
	cout << "NOW FRONT : " << queue.getFront() << endl;

	for (int i = 0; i < 10; i++) {
		cout << "DEQUEUE : " << queue.dequeue() << endl;
		cout << "NOW SIZE : " << queue.getSize() << endl;
		cout << "NOW FRONT : " << queue.getFront() << endl;
		cout << endl;
	}

	return 0;
} 