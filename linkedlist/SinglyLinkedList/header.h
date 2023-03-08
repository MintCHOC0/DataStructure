#include <iostream>
using std::string;

struct Account {
	string name;
	int id;
};

class Node {
private:
	Account account;
	Node* next = nullptr;
public:
	Node();
	Node(Account);
	~Node();
	void getInfo();
	Node* getNext();
	void setNext(Node*);
};

class SinglyLinkedList {
private:
	Node* head;
	int length = 1;
public:
	SinglyLinkedList(Account);
	SinglyLinkedList();
	~SinglyLinkedList();
	int getLength();
	void showNodeInfo(int);
	void addRearNode(Account);
	void cutRearNode();
	void insertNode(Account, int);
	void deleteNode(int);
	void traverseNode();
};