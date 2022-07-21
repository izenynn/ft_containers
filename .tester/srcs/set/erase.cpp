#include "common.hpp"
#include <list>

int main(void) {
	std::list<foo<int> > aux;
	for (int i = 0; i < 20; ++i) aux.push_back(i * 11 / (i + 1));

	t_set a(aux.begin(), aux.end());
	printSize("a", a);

	a.insert(1337);
	a.insert(3);
	a.erase(3);
	a.insert(42);
	a.insert(313);
	a.erase(42);
	a.erase(1337);
	printSize("a", a);

	a.insert(a.begin(), 515);
	a.insert(a.end(), 7);
	a.insert(a.end(), 725);
	printSize("a", a);

	std::list<foo<int> > aux2;
	for (int i = 0; i < 20; ++i) aux2.push_back(i * i);
	a.insert(aux2.begin(), aux2.end());
	printSize("a", a);

	a.erase(*(++a.begin()));
	printSize("a", a);

	a.insert(aux.begin(), aux.begin());
	printSize("a", a);

	a.erase(++a.begin(), --(--(--a.end())));
	printSize("a", a);

	a.erase(a.begin(), a.end());
	printSize("a", a);

	a.erase(134135);
	printSize("a", a);

	return 0;
}
