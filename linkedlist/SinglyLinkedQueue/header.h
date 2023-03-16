#include <iostream>

class Node {
private:
	int value;
	Node* next;
public:
	Node(int);
	~Node();
	int getValue();
	void setValue(int);
	Node* getNext();
	void setNext(Node*);
};

// SinglyLinkedQueue
class SLQ {
private:
	Node* head;
	Node* rear;
	int node_cnt = 0;
public:
	~SLQ();
	int getNodeCnt();
	void pushRearNode(int);
	int popHeadNode();
	int getHeadValue();
	void traverseNode();
};