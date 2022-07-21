#include "common.hpp"

#define t_vector ft::vector<foo<int> >

int main(void) {
	t_vector a(13);

	for (std::size_t i = 0; i < a.size(); ++i) {
		a.at(i) = i * 11;
	}
	printSize("a", a);

	t_vector::reverse_iterator it = a.rbegin();
	t_vector::const_reverse_iterator cit = a.rbegin();

	// more constructors
	{
		t_vector::iterator aux1 = a.begin();
		t_vector::const_iterator aux2 = a.begin();

		t_vector::reverse_iterator aux3(aux1);
		t_vector::const_reverse_iterator aux4(aux1);
		t_vector::const_reverse_iterator aux5(aux2);
		t_vector::const_reverse_iterator aux6(aux4);
		(void)aux5;
		(void)aux6;
	}

	// increment and decrement
	{
		t_vector::reverse_iterator tmp = ++it;
		std::cout << "pre increment\ntmp: " << *tmp << ", it: " << *it << '\n';
	}
	{
		t_vector::reverse_iterator tmp = --it;
		std::cout << "pre decrement\ntmp: " << *tmp << ", it: " << *it << '\n';
	}
	{
		t_vector::reverse_iterator tmp = it++;
		std::cout << "post increment\ntmp: " << *tmp << ", it: " << *it << '\n';
	}
	{
		t_vector::reverse_iterator tmp = it--;
		std::cout << "post decrement\ntmp: " << *tmp << ", it: " << *it << '\n';
	}

	// operations
	it = it + 7;
	it = 2 + it;
	it = it - 3;
	std::cout
		<< *(it += 2) << '\n'
		<< *(it -= 1) << std::endl;
	printSize("a", a);

	*(it -= 3) = 1337;
	*(it += 2) = 12;
	std::cout << *it << std::endl;
	printSize("a", a);

	std::cout
		<< *(cit += 3) << '\n'
		<< *(cit -= 3) << '\n'
		<< (cit == it) << '\n'
		<< (cit - it) << '\n'
		<< (cit + 6 == it) << std::endl;
	printSize("a", a);

	return 0;
}
