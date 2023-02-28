#include "header.h"

int main() {
	Stack st;
	
	cout << "Init len : " << st.getLen() << endl;

	st.push(10);
	st.push(20);
	st.push(30);

	cout << "Now Top Value : " << st.getTop() << endl;
	cout << "Now len : " << st.getLen() << endl;

	cout << "POP! : " << st.pop() << endl;
	cout << "Now Top Value : " << st.getTop() << endl;
	cout << "Now len : " << st.getLen() << endl;

	st.pop();
	st.pop();
	st.pop();
	st.pop();

	cout << st.pop() << endl;

	return 0;
}