#include <iostream>
#define MAX_QUEUE 5

class CircularQueue {
private:
	int queue_arr[MAX_QUEUE + 1] = { NULL, };
	int* front = queue_arr;
	int* rear = queue_arr;
public:
	bool isEmpty();
	bool isFull();
	int getSize();
	int getFront();
	void enqueue(int);
	int dequeue();

	void showState();
};