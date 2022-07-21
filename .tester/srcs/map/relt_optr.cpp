#include "common.hpp"
#include <list>

void comp(const std::string& name, const t_map& lhs, const t_map& rhs) {
	std::cout << "name: " << name
		<< std::boolalpha
		<< "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs)
		<< "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs)
		<< "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs)
		<< std::endl;
}

int main(void) {
	t_map a;
	t_map b;

	a[1] = 11;
	a[2] = 12;
	a[3] = 13;
	a[4] = 14;

	b[1] = 11;
	b[2] = 12;
	b[3] = 13;
	b[4] = 14;

	comp("a, a", a, a);
	comp("a, b", a, b);
	comp("b, a", b, a);

	a[5] = 1337;
	a[14] = 1;
	comp("a, b", a, b);
	comp("b, a", b, a);

	b[3] = 2431234;
	comp("a, b", a, b);
	comp("b, a", b, a);

	b[99] = 918413414;
	comp("a, b", a, b);
	comp("b, a", b, a);

	a.swap(b);
	comp("a, b", a, b);
	comp("b, a", b, a);

	return 0;
}
