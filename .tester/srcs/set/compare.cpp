#include "common.hpp"
#include <list>

void comp(const std::string& name, const t_set& m, const t_set::const_iterator& lhs, const t_set::const_iterator& rhs) {
	std::cout << std::boolalpha << "\nname: " << name
		<< "\nlhs first: " << *lhs << ", rhs first: " << *rhs
		<< "\nlhs second: " << *lhs << ", rhs second: " << *rhs
		<< "\nkey_comp(): " << m.key_comp()(*lhs, *rhs)
		<< "\nvalue_comp(): " << m.value_comp()(*lhs, *rhs)
		<< std::endl;
}

int main(void) {
	t_set a;

	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(8);

	a.insert(13);
	a.insert(14);
	a.insert(3);
	a.insert(99);

	// increment and decrement
	for (t_set::const_iterator it1 = a.begin(); it1 != a.end(); ++it1) {
		for (t_set::const_iterator it2 = a.begin(); it2 != a.end(); ++it2) {
			comp("a", a, it1, it2);
		}
	}
	printSize("a", a);

	return 0;
}
