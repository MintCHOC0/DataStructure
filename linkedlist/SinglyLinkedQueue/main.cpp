#include "header.h"

using std::cout; using std::endl;

int main() {
	SLQ slq;
	slq.pushRearNode(10);
	slq.popHeadNode();
	slq.pushRearNode(20);
	slq.pushRearNode(30);
	cout << "POP : " << slq.popHeadNode() << endl;
	slq.pushRearNode(40);
	slq.traverseNode();
	cout << slq.getNodeCnt() << " / " << slq.getHeadValue() << endl;

	return 0;
}