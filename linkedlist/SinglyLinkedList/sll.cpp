#include "header.h"
using std::cout; using std::endl;


SinglyLinkedList::SinglyLinkedList(Account acc) { head = new Node(acc); }
SinglyLinkedList::SinglyLinkedList() { head = new Node(); }

SinglyLinkedList::~SinglyLinkedList() {
	Node* nodeptr = head;
	for (int i = 0; i < length; i++) {
		Node* temp = nodeptr->getNext();
		delete nodeptr;
		nodeptr = temp;
	}
}

int SinglyLinkedList::getLength() { return length; }

void SinglyLinkedList::showNodeInfo(int pos) {
	Node* nodeptr = head;
	if (pos > 0 && pos < length) {
		for (int i = 0; i < pos; i++) { nodeptr = nodeptr->getNext(); }
	}
	nodeptr->getInfo();
}

void SinglyLinkedList::addRearNode(Account acc) {
	Node* nodeptr = head;
	for (int i = 0; i < length - 1; i++) { nodeptr = nodeptr->getNext(); }

	Node* node = new Node(acc);
	nodeptr->setNext(node);
	length++;
}

void SinglyLinkedList::cutRearNode() {
	Node* nodeptr = head;
	if (length == 1) {
		cout << "Linked List must have at least one Node." << endl;
		return;
	}
	for (int i = 0; i < length - 2; i++) { nodeptr = nodeptr->getNext(); }

	delete nodeptr->getNext();
	nodeptr->setNext(nullptr);
	length--;
}

void SinglyLinkedList::insertNode(Account acc, int pos) {
	if (0 > pos || pos > length) {
		cout << "Wrong Index" << endl;
		return;
	}

	Node* nodeptr = head;
	Node* new_node = new Node(acc);

	if (0 < pos && pos < length) {
		for (int i = 0; i < pos - 1; i++) { nodeptr = nodeptr->getNext(); }
		Node* temp = nodeptr->getNext();
		nodeptr->setNext(new_node);
		new_node->setNext(temp);
	}

	else if (pos == length) {
		for (int i = 0; i < length - 1; i++) { nodeptr = nodeptr->getNext(); }
		nodeptr->setNext(new_node);
	}

	else if (pos == 0) {
		new_node->setNext(head);
		head = new_node;
	}

	length++;
}

void SinglyLinkedList::deleteNode(int pos) {
	if (length == 1) {
		cout << "Linked List must have at least one Node." << endl;
	}

	if (0 > pos || pos >= length) {
		cout << "Wrong Index" << endl;
		return;
	}

	Node* nodeptr = head;

	if (0 < pos && pos < length) {
		for (int i = 0; i < pos - 1; i++) { nodeptr = nodeptr->getNext(); }
		Node* temp = nodeptr->getNext()->getNext();
		delete nodeptr->getNext();
		nodeptr->setNext(temp);
	}

	else if (pos == length) {
		for (int i = 0; i < length - 1; i++) { nodeptr = nodeptr->getNext(); }
		delete nodeptr->getNext();
		nodeptr->setNext(nullptr);
	}

	else if (pos == 0) {
		Node* temp = nodeptr->getNext();
		delete nodeptr;
		head = temp;
	}

	length--;
}

void SinglyLinkedList::traverseNode() {
	Node* nodeptr = head;
	for (int i = 0; i < length; i++) {
		nodeptr->getInfo();
		nodeptr = nodeptr->getNext();
	}
}