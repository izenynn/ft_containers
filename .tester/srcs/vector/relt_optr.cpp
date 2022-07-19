#include "common.hpp"

#define t_vector ft::vector<foo<int> >

void comp(const std::string& name, const t_vector& lhs, const t_vector& rhs) {
	std::cout << "name: " << name
		<< std::boolalpha
		<< "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs)
		<< "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs)
		<< "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs)
		<< std::endl;
}

int main(void) {
	t_vector a(13);
	t_vector b(13);
	t_vector c(5);

	comp("a, a", a, a);
	comp("a, b", a, b);
	comp("b, a", b, a);
	comp("a, c", a, c);
	comp("c, a", c, a);

	b.resize(23);
	comp("a, b", a, b);
	comp("b, a", b, a);

	a[3] = 1337;
	a[6] = -11;
	comp("a, b", a, b);
	comp("b, a", b, a);

	t_vector aux = a;
	a = b;
	b = aux;
	comp("a, b", a, b);
	comp("b, a", b, a);

	return 0;
}
