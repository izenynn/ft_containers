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
	a.erase(a.begin() + 3);
	printSize("a", a);

	b.insert(b.end(), 5);
	b.erase(a.end() - 1);
	b.insert(b.begin(), 3, 4);
	b.erase(a.begin());
	b.erase(a.end() - 1);
	a.erase(a.end() - 1);
	printSize("a", a);
	printSize("b", b);

	b.insert(b.begin(), 9, 2);
	b.insert(b.end() - 2, 13);
	b.erase(b.begin(), b.begin() + 2);
	b.erase(b.end() - 3, b.end() - 1);
	printSize("b", b);

	b.insert(b.end(), 4, 7);
	b.erase(b.end() - 3, b.end());
	printSize("b", b);

	for (std::size_t i = 0; i < 10; ++i) {
		c.insert(c.end(), i * 3);
	}
	c.insert(c.begin() + 3, 2, 1337);
	c.erase(c.begin() + 1);
	printSize("c", c);

	b.insert(b.begin(), a.begin(), a.begin() + 5);
	b.erase(b.begin(), b.begin() + 2);
	printSize("b", b);

	b.insert(b.begin(), a.begin() + 5, a.end());
	b.erase(b.end());
	printSize("b", b);

	// return value
	std::cout << *c.erase(c.end() - 2) << '\n';
	std::cout << *c.erase(c.begin() + 4, c.begin() + 7) << std::endl;
	printSize("a", a);
	printSize("b", b);
	printSize("c", c);

	return 0;
}
