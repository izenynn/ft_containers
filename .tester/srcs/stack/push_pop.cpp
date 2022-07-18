#include "common.hpp"

typedef std::vector<foo<int> > container_type;
#define t_stack ft::stack<foo<int>, container_type>

int main(void) {
	t_stack a;
	printSize("a", a);

	std::cout << "\npush: 1, 2, 3, 4, 5\npop: x1 element\n";
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.pop();
	printSize("a", a);

	std::cout << "\npop: x4 elements\n";
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	printSize("a", a);

	std::cout << "\npop: x5 (all) elements\n";
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	printSize("a", a);

	return 0;
}
