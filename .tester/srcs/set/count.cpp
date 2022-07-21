#include "common.hpp"
#include <list>

int main(void) {
	std::list<foo<int> > aux;
	for (int i = 0; i < 20; ++i) aux.push_back(i * 11 / (i + 1));

	t_set a(aux.begin(), aux.end());

	a.insert(1337);
	a.insert(3);
	a.insert(42);
	a.insert(313);

	a.insert(a.begin(), 515);
	a.insert(a.end(), 7);
	a.insert(a.end(), 725);

	std::list<foo<int> > aux2;
	for (int i = 0; i < 20; ++i) aux2.push_back(i * i);
	a.insert(aux2.begin(), aux2.end());
	a.insert(aux.begin(), aux.begin());

	// count
	{ std::cout << "count: " << a.count(1337) << '\n'; }
	{ std::cout << "count: " << a.count(12314) << '\n'; }
	{ std::cout << "count: " << a.count(11) << '\n'; }
	printSize("a", a);

	return 0;
}
