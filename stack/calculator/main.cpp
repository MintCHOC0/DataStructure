#include "header.h"

int main() {
	string input_equation = "5/3+7/3";
	Calculator cal(input_equation, input_equation.size());
	cal.showEquation();
	cal.setPostfix();
	cal.showPostfix();
	cout << cal.calcEquation() << endl;
	return 0;
}