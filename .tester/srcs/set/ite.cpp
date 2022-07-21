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

	// increment and decrement
	t_set::iterator it = a.begin();
	t_set::const_iterator cit = a.begin();

	{
		t_set::iterator tmp = ++it;
		std::cout << "pre increment\n";
		printPair(tmp);
	}
	{
		t_set::iterator tmp = --it;
		std::cout << "pre decrement\n";
		printPair(tmp);
	}
	{
		t_set::iterator tmp = it++;
		std::cout << "post increment\n";
		printPair(tmp);
	}
	{
		t_set::iterator tmp = it--;
		std::cout << "post decrement\n";
		printPair(tmp);
	}

	// operations
	std::cout << std::boolalpha
		<< (it == cit) << std::endl;

	return 0;
}
