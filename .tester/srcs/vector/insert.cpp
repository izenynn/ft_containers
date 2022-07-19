#include "common.hpp"

#define t_vector ft::vector<foo<int> >

int main(void) {
	t_vector a(13);
	printSize("a", a);

	for (std::size_t i = 0; i < a.size(); ++i) {
		a.at(i) = i * 11;
		std::cout << "at(): " << a.at(i)
			<< "\n[]: " << a[i] << '\n';
	}
	printSize("a", a);

	try {
		a.at(1337) = 113;
	} catch (std::out_of_range& e) {
		std::cout << "catched out_of_range exception\n";
	} catch (std::exception& e) {
		std::cout << "catched " << e.what() << " exception\n";
	}
	printSize("a", a);

	return 0;
}
