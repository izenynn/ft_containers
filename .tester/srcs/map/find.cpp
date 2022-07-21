#include "common.hpp"
#include <list>

int main(void) {
	std::list<ft::pair<int, foo<int> > > aux;
	for (int i = 0; i < 20; ++i) aux.push_back(ft::make_pair(i * 11 / (i + 1), i * i));

	t_map a(aux.begin(), aux.end());
	for (t_map::iterator it = a.begin(); it != a.end(); ++it) {
		it->second = it->first * 5 / 3;
	}

	a.insert(ft::make_pair(1337, 12));
	a.insert(ft::make_pair(3, 12));
	a.insert(ft::make_pair(42, 12));
	a.insert(ft::make_pair(313, 12));

	a.insert(a.begin(), ft::make_pair(515, 123));
	a.insert(a.end(), ft::make_pair(7, 123));
	a.insert(a.end(), ft::make_pair(725, 123));

	std::list<ft::pair<int, foo<int> > > aux2;
	for (int i = 0; i < 15; ++i) aux2.push_back(ft::make_pair(i * 11 / (i + 1), i * i));
	a.insert(aux2.begin(), aux2.end());
	a.insert(aux.begin(), aux.begin());

	// find
	{
		t_map::iterator ret = a.find(1337);
		if (ret == a.end()) std::cout << "find returned end()\n";
		else printPair(ret);
	}
	{
		t_map::iterator ret = a.find(12314);
		if (ret == a.end()) std::cout << "find returned end()\n";
		else printPair(ret);
	}
	{
		t_map::iterator ret = a.find(42);
		if (ret == a.end()) std::cout << "find returned end()\n";
		else printPair(ret);
	}
	{
		t_map::iterator ret = a.find(11);
		if (ret == a.end()) std::cout << "find returned end()\n";
		else printPair(ret);
	}

	printSize("a", a);

	a.find(7)->second = 13423;
	printSize("a", a);

	a.find(42)->second = 1337;
	printSize("a", a);

	a.find(725)->second = 515;
	printSize("a", a);

	return 0;
}
