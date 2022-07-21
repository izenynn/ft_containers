#include "common.hpp"
#include <list>

void comp(const std::string& name, const t_set& lhs, const t_set& rhs) {
	std::cout << "name: " << name
		<< std::boolalpha
		<< "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs)
		<< "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs)
		<< "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs)
		<< std::endl;
}

int main(void) {
	t_set a;
	t_set b;

	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);

	b.insert(1);
	b.insert(2);
	b.insert(3);
	b.insert(4);

	comp("a, a", a, a);
	comp("a, b", a, b);
	comp("b, a", b, a);

	a.insert(5);
	a.insert(14);
	comp("a, b", a, b);
	comp("b, a", b, a);

	b.insert(3);
	comp("a, b", a, b);
	comp("b, a", b, a);

	b.insert(99);
	comp("a, b", a, b);
	comp("b, a", b, a);

	a.swap(b);
	comp("a, b", a, b);
	comp("b, a", b, a);

	return 0;
}
