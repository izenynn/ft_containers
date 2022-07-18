#include "common.hpp"
#include <list>

typedef std::list<foo<int> > container_type;
#define t_stack ft::stack<foo<int>, container_type>

int main(void) {
	std::cout << "\ncreate std::list a\na: push_back: 11, 12, 13, 14, 15\n";
	container_type a;
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	a.push_back(15);

	std::cout << "\ncreate stack: b: container_type ctorz using std::list: push: 1, 2, 3, 4, 5\n";
	t_stack b(a);
	b.push(1);
	b.push(2);
	b.push(3);
	b.push(4);
	b.push(5);
	printCopySize("b", b);

	std::cout << "\nb: pop: x3 elements\n";
	b.pop();
	b.pop();
	b.pop();
	printCopySize("b", b);

	return 0;
}
