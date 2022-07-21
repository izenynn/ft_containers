#include "common.hpp"
#include <list>

int main(void) {
	std::list<ft::pair<int, foo<int> > > aux;
	for (int i = 0; i < 20; ++i) aux.push_back(ft::make_pair(i * 11 / (i + 1), i * i));

	t_map a(aux.begin(), aux.end());
	printSize("a", a);
	for (t_map::iterator it = a.begin(); it != a.end(); ++it) {
		it->second = it->first * 5 / 3;
	}

	t_map b(a);

	b.insert(ft::make_pair(1337, 12));
	b.insert(ft::make_pair(3, 12));
	b.insert(ft::make_pair(42, 12));
	b.insert(ft::make_pair(313, 12));
	printSize("a", a);
	printSize("b", b);

	// swap
	t_map::const_iterator it_a = a.begin();
	t_map::const_iterator it_b = b.begin();

	t_map c(b);
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
