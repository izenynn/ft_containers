#include "common.hpp"

#define t_vector ft::vector<foo<int> >

int main(void) {
	t_vector a(13);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	printSize("a", a);

	t_vector b(a);
	b.push_back(42);

	std::cout << "front: " << a.front()
		<< "back: " << a.back();
	std::cout << "front: " << b.front()
		<< "back: " << b.back();

	return 0;
}
