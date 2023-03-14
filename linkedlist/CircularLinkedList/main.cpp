#include "header.h"

using std::cout; using std::endl;

int OS::app_count = 0;

int main() {
	OS testOS;
	
	testOS.pushRearApp();
	testOS.pushRearApp();
	testOS.pushRearApp();
	testOS.pushRearApp();
	
	testOS.deleteNode(0);
	testOS.removeAppByID(4);
	testOS.removeAppByID(1);
	
	testOS.insertNode(2);
	testOS.insertNode(1);
	testOS.insertNode(0);

	testOS.traverseNode();

	return 0;
}