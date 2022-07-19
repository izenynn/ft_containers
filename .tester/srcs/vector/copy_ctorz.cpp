#include "common.hpp"

#define t_vector ft::vector<foo<int> >

int main(void) {
	t_vector a(42);
	printSize("a", a);

	for (int i = 0; i < 10; ++i) a.insert(a.end(), i);
	printSize("a", a);

	t_vector b(a.begin(), --(--a.end()));
	for (t_vector::iterator it = b.begin(); it != b.end(); ++it) *it = *it * 3;
	printSize("a", a);
	printSize("b", b);

	t_vector c(a);
	c.push_back(99);
	c.push_back(12);
	for (t_vector::iterator it = c.begin(); it != c.end(); ++it) *it = *it * 2;
	printSize("a", a);
	printSize("b", b);
	printSize("c", c);

	return 0;
}
