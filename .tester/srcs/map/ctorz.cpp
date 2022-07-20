#include "common.hpp"

#define t_map ft::map<int, foo<int> >

int main(void) {
	t_map a;
	printSize("a", a);

	return 0;
}
