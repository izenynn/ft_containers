#include "common.hpp"

typedef std::vector<foo<int> > container_type;
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
	t_stack a;
	printSize("a", a);

	;

	return 0;
}
