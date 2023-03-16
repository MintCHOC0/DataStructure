#include <iostream>

class Node {
private:
	int value;
	Node* next;
	Node* before;
public:
	Node(int);
	~Node();
	int getValue();
	void setValue(int);
	Node* getNext();
	Node* getBefore();
	void setNext(Node*);
	void setBefore(Node*);
};

// DoublyLinkedList
class DLL {
private:
	Node* head;
	Node* rear;
	int node_cnt = 0;
	void showInfoMsg(int, int);
public:
	~DLL();
	int getNodeCnt();
	void pushHeadNode(int);
	void removeHeadNode();
	void pushRearNode(int);
	void removeRearNode();
	void insertNode(int, int);
	void deleteNode(int);
	void showNodeInfo(int);
	void traverseNode(bool);
};