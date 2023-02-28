#include "header.h"

void Stack::push(int value) { this->stack_arr[(this->stack_len)++] = value; }
int Stack::pop() {
	if (this->getLen() == 0) {
		return 0x7fffffff; // if empty, return MAX
	}
	return this->stack_arr[--(this->stack_len)];
}
int Stack::getTop() { return this->stack_arr[(this->stack_len) - 1]; }
int Stack::getLen() { return this->stack_len; }

