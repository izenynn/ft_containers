#include "common.hpp"

#define t_vector ft::vector<foo<int> >

int main(void) {
	t_vector a(13);
	t_vector b;

	for (std::size_t i = 0; i < a.size(); ++i) {
		a[i] = i * 11;
	}
	printSize("a", a);

	a.resize(15, 1337);
	printSize("a", a);

	a.resize(21);
	a.reserve(5);
	printSize("a", a);

	a.resize(9);
	a.reserve(41);
	a.reserve(3);
	printSize("a", a);

	a.resize(99, 15);
	a.reserve(123);
	a.reserve(2);
	a.reserve(21);
	printSize("a", a);

	b = a;
	b.resize(0);
	printSize("a", a);
	printSize("b", b);

	a.resize(0);
	b.resize(12, 5);
	printSize("a", a);
	printSize("b", b);

	a.reserve(12);
	b.reserve(6);
	printSize("a", a);
	printSize("b", b);

	return 0;
}
