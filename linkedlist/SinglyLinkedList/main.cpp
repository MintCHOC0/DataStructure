#include "header.h"

using std::cout; using std::endl;

int main() {
	SinglyLinkedList sll({ "p1", 100 });
	sll.addRearNode({ "p2", 200 });
	sll.addRearNode({ "p5", 300 });
	sll.insertNode({ "p3", 400 }, 2);
	sll.insertNode({ "p4", 500 }, 3);
	sll.insertNode({ "p0", 600}, 0);
	sll.insertNode({ "t0", 700 }, 0);
	sll.addRearNode({ "p6", 800 });
	sll.insertNode({ "p7", 900 }, sll.getLength());
	sll.insertNode({ "t1", 1000 }, sll.getLength());
	sll.insertNode({ "t2", 1100 }, 3);
	sll.deleteNode(sll.getLength() - 1);
	sll.deleteNode(3);
	sll.deleteNode(0);
	sll.addRearNode({ "p8", 1200 });
	sll.traverseNode();
	
	// it works well!

	return 0;
}