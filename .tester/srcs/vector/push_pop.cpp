#include "common.hpp"

#define t_vector ft::vector<foo<int> >

int main(void) {
	{
	t_vector a;
	printSize("a", a);
	}

	{
	t_vector a;
	std::cout << "\npush: 1, 2, 3, 4, 5\npop: x1 element\n";
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.pop_back();
	printSize("a", a);
	}

	{
	t_vector a;
	std::cout << "\npop: x4 elements\n";
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	printSize("a", a);
	}

	{
	t_vector a;
	std::cout << "\npop: x5 (all) elements\n";
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	printSize("a", a);
	}

	return 0;
}
