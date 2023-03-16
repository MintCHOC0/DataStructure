#include "header.h"

using std::cout; using std::endl;

SLQ::~SLQ() {
	Node* nodeptr = head;
	Node* temp = head->getNext();
	int cnt = node_cnt;
	while(nodeptr->getNext()) {
		delete nodeptr;
		nodeptr = temp;
		temp = nodeptr->getNext();
		node_cnt--;
	}
	delete nodeptr; // delete last node
	cout << "Queue Destructed." << endl;
}

int SLQ::getNodeCnt() {
	return node_cnt;
}

int SLQ::popHeadNode() {
	if (node_cnt) {
		int temp_value = head->getValue();
		Node* temp_next = head->getNext();

		delete head;
		head = temp_next;
		node_cnt--;
		
		return temp_value;
	}
	else {
		cout << "No Node!!" << endl;
		return INT_MIN;
	}
}

void SLQ::pushRearNode(int value) {
	if (node_cnt) {
		Node* node = new Node(value);
		rear->setNext(node);
		rear = node;
	}
	else {
		head = rear = new Node(value);
	}
	node_cnt++;
}

int SLQ::getHeadValue() {
	return head->getValue();
}

void SLQ::traverseNode() {
	if (node_cnt) {
		cout << "Traverse Nodes" << endl;
		Node* nodeptr = head;
		for (int i = 0; i < node_cnt; i++) {
			cout << nodeptr->getValue() << " ";
			nodeptr = nodeptr->getNext();
		}
		cout << endl;
	}
	else {
		cout << "No Node!!" << endl;
	}
}