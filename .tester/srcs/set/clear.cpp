#include "common.hpp"
#include <list>

int main(void) {
	std::list<foo<int> > aux;
	for (int i = 0; i < 20; ++i) aux.push_back(i * 11 / (i + 1));

	t_set a(aux.begin(), aux.end());
	printSize("a", a);

	t_set b(a);
	printSize("a", a);
	printSize("b", b);

	b.insert(1337);
	b.insert(3);
	b.insert(42);
	b.insert(313);
	printSize("a", a);
	printSize("b", b);

	a.clear();
	printSize("a", a);
	printSize("b", b);

	return 0;
}
