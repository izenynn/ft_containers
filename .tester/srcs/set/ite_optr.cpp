#include "common.hpp"
#include <list>

int main(void) {
	t_set a;
	t_set b;

	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);

	b.insert(1);
	b.insert(2);
	b.insert(3);
	b.insert(4);

	a.insert(5);
	a.insert(14);

	b.insert(3);

	b.insert(99);

	// arrow
	t_set::iterator it = a.begin();
	t_set::const_iterator cit = a.begin();

	std::cout << (*it).getValue() << '\n';
	std::cout << (*cit).getValue() << '\n';
	printPair(it);
	printPair(cit);

	++it;
	++it;
	++it;
	++it;
	++cit;
	std::cout << (*it).getValue() << '\n';
	std::cout << (*cit).getValue() << '\n';
	printPair(it);
	printPair(cit);

	--it;
	--it;
	--it;
	--cit;
	std::cout << (*it).getValue() << '\n';
	std::cout << (*cit).getValue() << '\n';
	printPair(it);
	printPair(cit);

	//
	t_set::iterator ite = --(a.end());
	t_set::const_iterator cite = --(a.end());

	std::cout << (*it).getValue() << '\n';
	std::cout << (*cit).getValue() << '\n';
	printPair(ite);
	printPair(cite);

	--ite;
	--ite;
	--ite;
	--ite;
	--cite;
	std::cout << (*it).getValue() << '\n';
	std::cout << (*cit).getValue() << '\n';
	printPair(ite);
	printPair(cite);

	++ite;
	++ite;
	++ite;
	++cite;
	std::cout << (*it).getValue() << '\n';
	std::cout << (*cit).getValue() << '\n';
	printPair(ite);
	printPair(cite);

	return 0;
}
