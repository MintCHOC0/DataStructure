#include <iostream>
#include <string>
#define MAX_LENGTH 30

using namespace std;

template <typename TYPE>
class Stack{
private:
	TYPE arr[MAX_LENGTH] = { 0, };
	int stack_len = 0;
public:
	void push(TYPE input_value) { this->arr[this->stack_len++] = input_value; }
	TYPE pop() { return this->arr[--stack_len]; }
	TYPE getTop() { return this->arr[this->stack_len - 1]; }
	int getLen() { return this->stack_len; }
};


class Calculator{
private:
	char* equation;
	int equation_size;
	int postfix_size;
	char* postfix;
public:
	Calculator(string, int);
	~Calculator();
	void showEquation();
	void setPostfix();
	void showPostfix();
	double calcEquation();
};

bool isOperator(char);
int getPriority(char);
double calcTwoPops(double, double, char);