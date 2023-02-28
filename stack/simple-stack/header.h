#include <iostream>
#define MAX_STACK 20

using namespace std;

class Stack {
private:
	int stack_arr[MAX_STACK] = { 0, };
	int stack_len = 0;
public:
	void push(int);
	int pop();
	int getTop();
	int getLen();
};