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
	printSize("a", a);

	t_map b(a);
	printSize("a", a);
	printSize("b", b);

	a[1337] = 12;
	a[3] = 13;
	a[32] = a[3];
	a[313] = 7;
	printSize("a", a);
	printSize("b", b);

	b[15415] = a[1337];
	printSize("a", a);
	printSize("b", b);

	std::cout << "insert using operator[]: " << a[87] << std::endl;
	std::cout << "insert using operator[]: " << b[31] << std::endl;
	printSize("a", a);
	printSize("b", b);

	return 0;
}
