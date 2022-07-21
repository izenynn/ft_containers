#include "common.hpp"
#include <list>

#define t_map ft::map<int, foo<int> >

int main(void) {
	std::list<ft::pair<int, foo<int> > > aux;
	for (int i = 0; i < 20; ++i) aux.push_back(ft::make_pair(i * 11 / (i + 1), i * i));

	t_map a(aux.begin(), aux.end());
	printSize("a", a);
	for (t_map::iterator it = a.begin(); it != a.end(); ++it) {
		it->second = it->first * 5 / 3;
	}
	printSize("a", a);

	t_map b(a);
	printSize("a", a);
	printSize("b", b);

	b.insert(ft::make_pair(1337, 12));
	b.insert(ft::make_pair(3, 12));
	b.insert(ft::make_pair(42, 12));
	b.insert(ft::make_pair(313, 12));
	printSize("a", a);
	printSize("b", b);

	t_map c;
	c = b;
	printSize("a", a);
	printSize("b", b);
	printSize("c", c);

	return 0;
}
