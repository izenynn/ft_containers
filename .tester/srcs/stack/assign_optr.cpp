#include "common.hpp"

typedef std::vector<foo<int> > container_type;
#define t_stack ft::stack<foo<int>, container_type>

int main(void) {
	t_stack a;
	t_stack b;
	t_stack c;
	printSize("a", a);

	std::cout << "\na: push: 1, 2, 3, 4, 5\n";
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	printSize("a", a);

	std::cout << "\ncreate: b: copy ctorz using a\n";
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	b = a;
	printSize("a", a);
	printSize("b", a);

	std::cout << "\ncreate: c: copy ctorz using a\na: pop x2 elements\na: push: 11\nb: pop x3 elements\nb: push: 12\n";
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	a.pop();
	a.pop();
	a.push(11);
	b.pop();
	b.pop();
	b.pop();
	b.push(12);
	c = a;
	printSize("a", a);
	printSize("b", a);

	return 0;
}
