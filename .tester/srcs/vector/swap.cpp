#include "common.hpp"

#define t_vector ft::vector<foo<int> >

int main(void) {
	t_vector a(13, 15);
	t_vector b(3, 1337);

	for (std::size_t i = 0; i < a.size(); ++i) {
		a[i] = i * 11 / (i + 1);
	}
	for (std::size_t i = 0; i < b.size(); ++i) {
		b[i] = i * (i + 1) / -3;
	}
	a.resize(15, 1337);
	printSize("a", a);
	printSize("b", b);

	t_vector::const_iterator it_a = a.begin();
	t_vector::const_iterator it_b = b.begin();

	a.swap(b);
	printSize("a", a);
	printSize("b", b);

	b.swap(b);
	printSize("a", a);
	printSize("b", b);

	// check iterators
	std::cout << std::boolalpha
		<< (it_a == b.begin()) << '\n'
		<< (it_b == a.begin()) << std::endl;

	return 0;
}
