#include "header.h"
using std::cout; using std::endl;

OS::~OS() {
	App* nownode = head;
	App* nextnode = head->getNext();
	for (int i = 0; i < run_apps; i++) {
		delete nownode;
		nownode = nextnode;
		nextnode = nextnode->getNext();
	}
	cout << "Terminate OS" << endl;
}

void OS::increaseAppRuntime() {
	App* nodeptr = head;
	for (int i = 0; i < run_apps; i++) {
		nodeptr->increaseRuntime();
		nodeptr = nodeptr->getNext();
	}
}

int OS::getRunningAppCnt() {
	increaseAppRuntime();
	return run_apps;
}

void OS::showHead() {
	increaseAppRuntime();
	cout << "[HEAD]" << endl;
	head->showStatus();
}

void OS::showAppInfoByID(int id) {
	increaseAppRuntime();
	App* nodeptr = head;
	for (int i = 0; i < run_apps; i++) {
		if (nodeptr->getID() == id) {
			nodeptr->showStatus();
			break;
		}
		cout << "The app does not exist." << endl;
	}
}

void OS::traverseNode() {
	increaseAppRuntime();
	App* nodeptr = head;
	for (int i = 0; i < run_apps; i++) {
		nodeptr->showStatus();
		nodeptr = nodeptr->getNext();
	}
}

void OS::pushRearApp() {
	increaseAppRuntime();
	if (run_apps) {
		App* nodeptr = head;
		for (int i = 0; i < run_apps - 1; i++) {
			nodeptr = nodeptr->getNext();
		}
		App* app = new App(app_count);
		nodeptr->setNext(app);
		app->setNext(head);
	}

	else {
		head = new App(app_count);
		head->setNext(head);
	}
	
	app_count++;
	run_apps++;
}

void OS::removeRearApp() {
	increaseAppRuntime();
	if (run_apps) {
		App* nodeptr = head;
		for (int i = 0; i < run_apps - 1; i++) {
			nodeptr = nodeptr->getNext();
		}
		App* temp = nodeptr;
		nodeptr->setNext(head);
		delete temp;
		run_apps--;
	}

	else {
		cout << "No Apps" << endl;
	}
}

void OS::insertNode(int pos) {
	increaseAppRuntime();
	if (run_apps) {
		if (pos > run_apps || pos < 0) { // invaild
			cout << "Invaild Position" << endl;
			return;
		}
		// vaild
		App* nodeptr = head;
		App* app = new App(app_count);
		
		if (0 < pos && pos <= run_apps) {
			for (int i = 0; i < pos - 1; i++) {
				nodeptr = nodeptr->getNext();
			}
			App* temp = nodeptr->getNext();
			nodeptr->setNext(app);
			app->setNext(temp);
		}
		
		else { // pos = 0
			for (int i = 0; i < run_apps - 1; i++) {
				nodeptr = nodeptr->getNext();
			}
			app->setNext(head);
			nodeptr->setNext(app);
			head = app;
		}
	}
	else {
		cout << "Create Head Node" << endl;
		head = new App(app_count);
		head->setNext(head);
	}

	app_count++;
	run_apps++;
}

void OS::deleteNode(int pos) {
	increaseAppRuntime();
	if (run_apps) {
		if (pos < 0 || pos >= run_apps) {
			cout << "Invaild Position" << endl;
			return;
		}

		App* nodeptr = head;
		if (pos != 0) {
			for (int i = 0; i < pos - 1; i++) {
				nodeptr = nodeptr->getNext();
			}
			App* temp = nodeptr->getNext()->getNext();
			delete nodeptr->getNext();
			nodeptr->setNext(temp);
		}
		else {
			for (int i = 0; i < run_apps - 1; i++) {
				nodeptr = nodeptr->getNext();
			}
			App* temp = nodeptr->getNext()->getNext();
			delete nodeptr->getNext();
			nodeptr->setNext(temp);
			head = temp;
		}
		run_apps--;
	}
	else {
		cout << "No apps" << endl;
	}
}

void OS::removeAppByID(int id) {
	increaseAppRuntime();
	App* nodeptr = head;
	for (int idx = 0; idx < run_apps; idx++) {
		if (nodeptr->getID() == id) {
			this->deleteNode(idx);
			return;
		}
		nodeptr = nodeptr->getNext();
	}
	cout << "There is no app with that ID." << endl;
}

void OS::showRunAppIDs() {
	increaseAppRuntime();
	App* nodeptr = head;
	for (int i = 0; i < run_apps; i++) {
		cout << nodeptr->getID() << " ";
		nodeptr = nodeptr->getNext();
	}
	cout << endl;
}