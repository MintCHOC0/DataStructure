#include "header.h"

using std::cout; using std::endl;

bool MoveQueue::isEmpty() { return !(rear - queue_arr); }
int MoveQueue::getSize() { return rear - queue_arr; }
int MoveQueue::getFront() { return queue_arr[0]; }

void MoveQueue::moveForward() { // move all values forward one step
	for (int i = 0; i < (rear - queue_arr); i++) {
		queue_arr[i] = queue_arr[i + 1];
	}
	rear--;
}

void MoveQueue::enqueue(int value) {
	if (rear - queue_arr >= MAX_QUEUE) { moveForward(); }
	*rear = value;
	rear++;
}

int MoveQueue::dequeue() {
	if (isEmpty()) { return INT_MIN; }
	int temp = queue_arr[0];
	moveForward();
	return temp;
}