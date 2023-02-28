#include "header.h"

void Queue::enqueue(int value) {
	if (rear - queue_arr < MAX_QUEUE ) {
		*rear = value;
		rear++;
		size++;
	}
	else {
		cout << "MAX QUQUE" << endl;
	}
}

int Queue::dequeue() {
	if (size) {
		int temp = *front;
		front++;
		size--;
		return temp;
	}
	else {
		return INT_MIN;
	}
}

bool Queue::isEmpty() { return size; }
int Queue::getSize() { return size; }
int Queue::getFront() { return *front; }