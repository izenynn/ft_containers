#include "common.hpp"

#define t_vector ft::vector<foo<int> >

int main(void) {
	t_vector a(13);

	for (std::size_t i = 0; i < a.size(); ++i) {
		a.at(i) = i * 11;
	}
	printSize("a", a);

	t_vector::iterator it = a.begin();
	t_vector::const_iterator cit = a.begin();

	it = it + 7;
	it = 2 + it;
	it = it - 3;
	std::cout
		<< *(it += 2) << '\n'
		<< *(it -= 1) << std::endl;
	std::cout << "it value: " << it->getValue()
		<< "\ncit value: " << cit->getValue();
	std::cout << "it value: " << (*it).getValue()
		<< "\ncit value: " << (*cit).getValue();
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
	std::cout << "it value: " << it->getValue()
		<< "\ncit value: " << cit->getValue();
	std::cout << "it value: " << (*it).getValue()
		<< "\ncit value: " << (*cit).getValue();
	printSize("a", a);

	return 0;
}
