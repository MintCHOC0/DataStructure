#include "header.h"
using std::cout; using std::endl;

App::App(int num) {
	this->id = num;
}

App::~App() {
	cout << "Terminate App" << endl;
}

void App::showStatus() {
	cout << id << " : " << "Runnig for " << runtime << "sec" << endl;
}

int App::getID() {
	return id;
}

App* App::getNext() {
	return next;
}

void App::setNext(App* app) {
	next = app;
}

void App::increaseRuntime() {
	runtime++;
}