#include "common.hpp"
#include <list>

typedef std::list<foo<int> > container_type;
#define t_stack ft::stack<foo<int>, container_type>

void comp(const std::string& name, const t_stack& lhs, const t_stack& rhs) {
	std::cout << "name: " << name
		<< std::boolalpha
		<< "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs)
		<< "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs)
		<< "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs)
		<< std::endl;
}

int main(void) {
	container_type a;

	std::cout << "\na: push: 1234, 1983, 12, 1337, -2003, 0, 313\n";
	a.push_back(1234);
	a.push_back(1983);
	a.push_back(13);
	a.push_back(1337);
	a.push_back(-2003);
	a.push_back(0);
	a.push_back(313);

	std::cout << "\ncreate: b: copy ctorz using a\n";
	t_stack b(a);
	std::cout << "\ncreate: c: copy ctorz using a\n";
	t_stack c(a);

	std::cout << "\ncompare: b, b\n";
	comp("b, b", b, b);
	std::cout << "\ncompare: b, c\n";
	comp("b, c", b, c);

	std::cout << "\nc: push: 54, 123, 12\n";
	c.push(54);
	c.push(123);
	c.push(12);

	std::cout << "\ncompare: b, c\n";
	comp("b, c", b, c);
	std::cout << "\ncompare: c, b\n";
	comp("c, b", c, b);

	std::cout << "\nc: push: 23521\n";
	c.push(23521);

	std::cout << "\ncompare: b, c\n";
	comp("b, c", b, c);
	std::cout << "\ncompare: c, b\n";
	comp("c, b", c, b);

	return 0;
}

