#include "common.hpp"
#include <list>

int main(void) {
	t_map a;
	t_map b;

	a[1] = 11;
	a[2] = 12;
	a[3] = 13;
	a[4] = 14;

	b[1] = 11;
	b[2] = 12;
	b[3] = 13;
	b[4] = 14;

	a[5] = 1337;
	a[14] = 1;

	b[3] = 2431234;

	b[99] = 918413414;

	// arrow
	t_map::reverse_iterator it = a.rbegin();
	t_map::const_reverse_iterator cit = a.rbegin();

	std::cout << it->second.getValue() << '\n';
	std::cout << cit->second.getValue() << '\n';
	printPair(it);
	printPair(cit);

	++it;
	++it;
	++it;
	++it;
	++cit;
	std::cout << it->second.getValue() << '\n';
	std::cout << cit->second.getValue() << '\n';
	printPair(it);
	printPair(cit);

	--it;
	--it;
	--it;
	--cit;
	std::cout << it->second.getValue() << '\n';
	std::cout << cit->second.getValue() << '\n';
	printPair(it);
	printPair(cit);

	//
	t_map::reverse_iterator ite = --(a.rend());
	t_map::const_reverse_iterator cite = --(a.rend());

	std::cout << ite->second.getValue() << '\n';
	std::cout << cite->second.getValue() << '\n';
	printPair(ite);
	printPair(cite);

	--ite;
	--ite;
	--ite;
	--ite;
	--cite;
	std::cout << ite->second.getValue() << '\n';
	std::cout << cite->second.getValue() << '\n';
	printPair(ite);
	printPair(cite);

	++ite;
	++ite;
	++ite;
	++cite;
	std::cout << ite->second.getValue() << '\n';
	std::cout << cite->second.getValue() << '\n';
	printPair(ite);
	printPair(cite);

	return 0;
}
