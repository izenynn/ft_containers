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

	// increment and decrement
	t_map::reverse_iterator it = a.rbegin();
	t_map::const_reverse_iterator cit = a.rbegin();

	{
		t_map::reverse_iterator tmp = ++it;
		std::cout << "pre increment\n";
		printPair(tmp);
	}
	{
		t_map::reverse_iterator tmp = --it;
		std::cout << "pre decrement\n";
		printPair(tmp);
	}
	{
		t_map::reverse_iterator tmp = it++;
		std::cout << "post increment\n";
		printPair(tmp);
	}
	{
		t_map::reverse_iterator tmp = it--;
		std::cout << "post decrement\n";
		printPair(tmp);
	}

	// operations
	std::cout << std::boolalpha
		<< (it == cit) << std::endl;

	return 0;
}
