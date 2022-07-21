#include "common.hpp"
#include <list>

void comp(const std::string& name, const t_map& m, const t_map::const_iterator& lhs, const t_map::const_iterator& rhs) {
	std::cout << std::boolalpha << "\nname: " << name
		<< "\nlhs first: " << lhs->first << ", rhs first: " << rhs->first
		<< "\nlhs second: " << lhs->second << ", rhs second: " << rhs->second
		<< "\nkey_comp(): " << m.key_comp()(lhs->first, rhs->first)
		<< "\nvalue_comp(): " << m.value_comp()(*lhs, *rhs)
		<< std::endl;
}

int main(void) {
	t_map a;

	a[1] = 11;
	a[2] = 12;
	a[3] = 13;
	a[4] = 14;
	a[5] = 11;
	a[6] = 12;
	a[7] = 13;
	a[8] = 14;

	a[13] = 1337;
	a[14] = 1;
	a[3] = 2431234;
	a[99] = 918413414;

	// increment and decrement
	for (t_map::const_iterator it1 = a.begin(); it1 != a.end(); ++it1) {
		for (t_map::const_iterator it2 = a.begin(); it2 != a.end(); ++it2) {
			comp("a", a, it1, it2);
		}
	}
	printSize("a", a);

	return 0;
}
