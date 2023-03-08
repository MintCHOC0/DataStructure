#include "header.h"
using std::cout; using std::endl;

Node::Node() { this->account = { "Anonymous", 0 }; }
Node::Node(Account acc) { this->account = acc; }
Node::~Node() { cout << "Node of " << this->account.name << " is destructed." << endl; }

void Node::getInfo() {
	cout << "Name : " << this->account.name <<
	" / ID : " << this->account.id << endl;
}

Node* Node::getNext() { return this->next; }

void Node::setNext(Node* node) { this->next = node; }