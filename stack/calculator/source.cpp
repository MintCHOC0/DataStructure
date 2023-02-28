#include "header.h"

Calculator::Calculator(string input_equation, int size) {
	this->equation = new char[size];
	this->postfix = new char[size];
	this->equation_size = size;
	this->postfix_size = 0;
	for (int i = 0; i < size; i++) {
		this->equation[i] = input_equation[i];
	}
}

Calculator::~Calculator() {
	delete[] this->equation;
	delete[] this->postfix;
}

void Calculator::showEquation() {
	for (int i = 0; i < this->equation_size; i++) {
		std::cout << equation[i];
	}
	std::cout << endl;
}

void Calculator::setPostfix() {
	Stack<char> stack;
	for (int i = 0; i < this->equation_size; i++) {
		if (isOperator(this->equation[i])) {
			if (getPriority(this->equation[i]) >= getPriority(stack.getTop())) {
				while (stack.getLen()) {
					this->postfix[postfix_size++] = stack.pop();
				}
			}
			stack.push(this->equation[i]);
		}
		else {
			this->postfix[postfix_size++] = this->equation[i];
		}
	}
	while (stack.getLen()) {
		this->postfix[postfix_size++] = stack.pop();
	}
}

void Calculator::showPostfix() {
	for (int i = 0; i < this->postfix_size; i++) {
		std::cout << this->postfix[i];
	}
	cout << endl;
}

double Calculator::calcEquation() {
	Stack<double> stack;
	for (int i = 0; i < this->postfix_size; i++) {
		if (isOperator(this->postfix[i])) { stack.push(calcTwoPops(stack.pop(), stack.pop(), this->postfix[i])); }
		else { stack.push(this->postfix[i] - '0'); }
	}
	return stack.getTop();
}


bool isOperator(char target) {
	switch (target)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

int getPriority(char opr) {
	if (opr == '+' || opr == '-') {
		return 2;
	}
	else if (opr == '*' || opr == '/') {
		return 1;
	}
}

double calcTwoPops(double a, double b, char opr) {
	if (opr == '+') { return a + b; }
	else if (opr == '-') { return a - b; }
	else if (opr == '*') { return a * b; }
	else if (opr == '/') { return a / b; }
	else { return -99999999; }
}