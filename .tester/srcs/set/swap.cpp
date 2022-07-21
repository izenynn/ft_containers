#include "common.hpp"
#include <list>

int main(void) {
	std::list<foo<int> > aux;
	for (int i = 0; i < 20; ++i) aux.push_back(i * 11 / (i + 1));

	t_set a(aux.begin(), aux.end());
	printSize("a", a);

	t_set b(a);

	b.insert(1337);
	b.insert(3);
	b.insert(42);
	b.insert(313);
	printSize("a", a);
	printSize("b", b);

	// swap
	t_set::const_iterator it_a = a.begin();
	t_set::const_iterator it_b = b.begin();

	t_set c(b);
	printSize("a", a);
	printSize("b", b);
	printSize("c", c);

	a.swap(b);
	printSize("a", a);
	printSize("b", b);
	printSize("c", c);

	c.swap(a);
	printSize("a", a);
	printSize("b", b);
	printSize("c", c);

	b.swap(a);
	printSize("a", a);
	printSize("b", b);
	printSize("c", c);

	// check iterators
	std::cout << std::boolalpha
		<< (it_a == b.begin()) << '\n'
		<< (it_b == a.begin()) << std::endl;


	return 0;
}
