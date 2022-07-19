#include "common.hpp"

#define t_vector ft::vector<foo<int> >

int main(void) {
	t_vector a(13);
	t_vector b;
	t_vector c;
	printSize("a", a);

	for (std::size_t i = 0; i < a.size(); ++i) {
		a[i] = i * 11;
	}
	printSize("a", a);

	b.insert(b.end(), 5);
	b.insert(b.begin(), 3, 4);
	printSize("b", b);

	b.insert(b.end() - 2, 13);
	printSize("b", b);

	b.insert(b.end(), 4, 7);
	printSize("b", b);

	for (std::size_t i = 0; i < 10; ++i) {
		c.insert(c.end(), i * 3);
	}
	c.insert(c.begin() + 3, 2, 1337);
	printSize("c", c);

	b.insert(b.begin(), a.begin(), a.begin() + 5);
	printSize("b", b);

	b.insert(b.begin(), a.begin() + 5, a.end());
	printSize("b", b);

	// return value
	std::cout << *c.insert(c.end(), 1337) << '\n';
	//std::cout << *c.insert(c.begin() + 2, b.begin(), b.begin() + 3) << '\n'; // void value
	std::cout << *c.insert(c.begin() + 4, 42) << std::endl;
	printSize("a", a);
	printSize("b", b);
	printSize("c", c);

	return 0;
}
