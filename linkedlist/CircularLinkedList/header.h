#include <iostream>

class App {
private:
	int id;
	int runtime = 0;
	App* next = nullptr;
public:
	App(int);
	~App();
	void showStatus();
	int getID();
	App* getNext();
	void setNext(App*);
	void increaseRuntime();
};

class OS {
private:
	static int app_count;
	App* head = nullptr;
	int run_apps = 0;
	void increaseAppRuntime();

public:
	~OS();
	int getRunningAppCnt();
	void showHead();
	void showAppInfoByID(int);
	void showRunAppIDs();
	void traverseNode();
	
	void pushRearApp();
	void removeRearApp();
	void insertNode(int);
	void deleteNode(int);
	void removeAppByID(int);
};