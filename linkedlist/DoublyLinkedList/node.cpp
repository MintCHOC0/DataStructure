#include "header.h"

using std::cout; using std::endl;

Node::Node(int value) {
	this->value = value;
	next = before = nullptr;
}

Node::~Node() {
	cout << "Node Destructed." << endl;
}

int Node::getValue() {
	return value;
}

void Node::setValue(int value) {
	this->value = value;
}

Node* Node::getNext() {
	return next;
}

Node* Node::getBefore() {
	return before;
}

void Node::setNext(Node* next) {
	this->next = next;
}

void Node::setBefore(Node* before) {
	this->before = before;
}