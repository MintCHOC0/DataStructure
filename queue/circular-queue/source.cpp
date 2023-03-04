#include "header.h"
using std::cout; using std::endl;

bool CircularQueue::isEmpty() { return (front == rear); }

bool CircularQueue::isFull() {
	if (front > rear) {
		if (front - rear == 1) { return true; }
		else { return false; }
	}
	else {
		if (rear - front == MAX_QUEUE) { return true; }
		else { return false; }
	}
}

int CircularQueue::getSize() {
	if (front > rear) { return (MAX_QUEUE + 1) - (front - rear); }
	else { return rear - front; }
}

int CircularQueue::getFront() { return *front; }

void CircularQueue::enqueue(int value) {
	if (isFull()) {
		cout << "Queue is Full" << endl;
		return;
	}

	*rear = value;
	rear++;
	
	// if rear reaches end of queue
	if (rear - queue_arr == MAX_QUEUE + 1) { rear = queue_arr; }
}

int CircularQueue::dequeue() {
	if (isEmpty()) { return INT_MIN; }

	int temp = *front;
	*front = NULL;
	front++;
	if (front - queue_arr == MAX_QUEUE + 1) { front = queue_arr; }
	
	return temp;
}

void CircularQueue::showState() {
	cout << "[ Now State ]" << endl;
	cout << "isEmpty() : " << this->isEmpty() << endl;
	cout << "isFull() : " << this->isFull() << endl;
	cout << "front : " << this->getFront() << endl;
	cout << "size : " << this->getSize() << endl << endl;
}