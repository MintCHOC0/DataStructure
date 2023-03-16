#include "header.h"

using std::cout; using std::endl;

DLL::~DLL() {
	Node* nodeptr = head;
	Node* temp = nullptr;
	int count = node_cnt;
	for (int i = 0; i < count; i++) {
		temp = nodeptr->getNext();
		delete nodeptr;
		nodeptr = temp;
	}
	cout << "List Destructed." << endl;
}

int DLL::getNodeCnt() {
	return node_cnt;
}

void DLL::pushHeadNode(int value) {
	if (node_cnt) {
		Node* node = new Node(value);
		head->setBefore(node);
		node->setNext(head);
		head = node;
	}
	else {
		head = rear = new Node(value);
	}
	node_cnt++;
}

void DLL::removeHeadNode() {
	if (node_cnt) {
		Node* temp = head->getNext();
		delete head;
		head = temp;
		node_cnt--;
	}
	else {
		cout << "No Node!!" << endl;
	}
}

void DLL::pushRearNode(int value) {
	if (node_cnt) {
		Node* node = new Node(value);
		rear->setNext(node);
		node->setBefore(rear);
		rear = node;
	}
	else {
		head = rear = new Node(value);
	}
	node_cnt++;
}

void DLL::removeRearNode() {
	if (node_cnt) {
		Node* temp = rear->getBefore();
		delete rear;
		rear = temp;
		node_cnt--;
	}
	else {
		cout << "No Node!!" << endl;
	}
}

void DLL::insertNode(int pos, int value) {
	if (!node_cnt) {
		cout << "Create Head Node" << endl;
		head = rear = new Node(value);
		node_cnt++;
		return;
	}

	if (0 < pos && pos < node_cnt) {
		Node* nodeptr = nullptr;
		Node* temp = nullptr;

		if (pos < node_cnt / 2) {
			nodeptr = head;
			for (int i = 0; i < pos - 1; i++) {
				nodeptr = nodeptr->getNext();
			}
			temp = nodeptr->getNext();
			Node* node = new Node(value);
			nodeptr->setNext(node);
			node->setNext(temp);
			temp->setBefore(node);
			node->setBefore(nodeptr);
		}
		else {
			nodeptr = rear;
			for (int i = 0; i < node_cnt - pos - 3; i++) {
				nodeptr = nodeptr->getBefore();
			}
			temp = nodeptr->getBefore();
			Node* node = new Node(value);
			nodeptr->setBefore(node);
			node->setBefore(temp);
			temp->setNext(node);
			node->setNext(nodeptr);
		}
		node_cnt++;
	}
	else if (pos == 0) {
		pushHeadNode(value);
	}
	else if (pos == -1 || pos == node_cnt) {
		pushRearNode(value);
	}
	else {
		cout << "Wrong Index!" << endl;
	}
}

void DLL::deleteNode(int pos) {
	if (!node_cnt) {
		cout << "No Node!!" << endl;
		return;
	}

	if (0 < pos && pos < node_cnt) {
		Node* nodeptr = nullptr;
		Node* temp = nullptr;

		if (pos < node_cnt / 2) {
			nodeptr = head;
			for (int i = 0; i < pos - 1; i++) {
				nodeptr = nodeptr->getNext();
			}
			temp = nodeptr->getNext()->getNext();
			delete nodeptr->getNext();
			nodeptr->setNext(temp);
			temp->setBefore(nodeptr);

		}
		else {
			nodeptr = rear;
			for (int i = 0; i < node_cnt - pos - 3; i++) {
				nodeptr = nodeptr->getBefore();
			}
			temp = nodeptr->getBefore()->getBefore();
			delete nodeptr->getBefore();
			nodeptr->setBefore(temp);
			temp->setNext(nodeptr);
		}
		node_cnt--;
	}
	else if (pos == 0) {
		removeHeadNode();
	}
	else if (pos == -1 || pos == node_cnt) {
		removeRearNode();
	}
	else {
		cout << "Wrong Index!" << endl;
	}
}

void DLL::showInfoMsg(int idx, int value) {
	cout << "[ Node " << idx;
	cout << " : " << value << " ]" << endl;
}

void DLL::showNodeInfo(int pos) {
	Node* nodeptr = nullptr;
	if (pos < node_cnt / 2) {
		nodeptr = head;
		for (int i = 0; i < pos; i++) {
			nodeptr = nodeptr->getNext();
		}
	}
	else {
		nodeptr = rear;
		for (int i = 0; i < node_cnt - pos - 1; i++) {
			nodeptr = nodeptr->getBefore();
		}
	}
	showInfoMsg(pos, nodeptr->getValue());
}

void DLL::traverseNode(bool isFront) {
	if (isFront) {
		cout << "{ Head to Rear }" << endl;
		Node* nodeptr = head;
		for (int i = 0; i < node_cnt; i++) {
			showInfoMsg(i, nodeptr->getValue());
			nodeptr = nodeptr->getNext();
		}
	}
	else {
		cout << "{ Rear to Head }" << endl;
		Node* nodeptr = rear;
		for (int i = 0; i < node_cnt; i++) {
			showInfoMsg(node_cnt - i - 1, nodeptr->getValue());
			nodeptr = nodeptr->getBefore();
		}
	}
	
	if (node_cnt == 0) {
		cout << "No Node!!" << endl;
	}
}