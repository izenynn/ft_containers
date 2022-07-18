#include "common.hpp"

typedef std::vector<foo<int> > container_type;
#define t_stack ft::stack<foo<int>, container_type>

int main(void) {
	t_stack a;
	printSize("a", a);

	std::cout << "\npush: 1\n";
	a.push(1);
	printSize("a", a);

	std::cout << "\npush: 2, 3, 4, 5\n";
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	printSize("a", a);

	return 0;
}
