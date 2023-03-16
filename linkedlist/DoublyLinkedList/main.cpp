#include "header.h"

using std::cout; using std::endl;

int main() {
	DLL dlist;
	dlist.pushRearNode(10);
	dlist.pushRearNode(20);
	dlist.pushRearNode(30);
	dlist.pushHeadNode(0);
	dlist.insertNode(-1, 40);
	dlist.pushRearNode(1000);
	dlist.deleteNode(-1);

	int cnt = dlist.getNodeCnt();
	
	for (int i = 0; i < cnt; i++) {
		dlist.showNodeInfo(i);
	}

	return 0;
}