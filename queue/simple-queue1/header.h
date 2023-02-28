#include <iostream>
#define MAX_QUEUE 5

using namespace std;

class Queue {
private:
	int queue_arr[MAX_QUEUE] = { 0, };
	int* front = queue_arr;
	int* rear = queue_arr;
	int size = 0;
public:
	void enqueue(int);
	int dequeue();
	bool isEmpty();
	int getSize();
	int getFront();
};