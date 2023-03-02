#include <iostream>
#define MAX_QUEUE 5

class MoveQueue {
private:
	int queue_arr[MAX_QUEUE + 1] = { 0, };
	int* rear = queue_arr;
	void moveForward();
public:
	bool isEmpty();
	int getSize();
	int getFront();
	void enqueue(int);
	int dequeue();
};
