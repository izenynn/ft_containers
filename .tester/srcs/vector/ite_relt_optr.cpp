#include "common.hpp"

#define t_vector ft::vector<foo<int> >

template <typename It1, typename It2>
void comp(const std::string& name, const It1& lhs, const It2& rhs) {
	std::cout << "name: " << name
		<< std::boolalpha
		<< "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs)
		<< "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs)
		<< "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs)
		<< std::endl;
}

int main(void) {
	t_vector a(13);

	for (std::size_t i = 0; i < a.size(); ++i) {
		a.at(i) = i * 11;
	}
	printSize("a", a);

	t_vector::iterator it1 = a.begin();
	t_vector::iterator it2 = a.begin();
	t_vector::const_iterator cit1 = a.begin();
	t_vector::const_iterator cit2 = a.begin();

	comp("it1, it2", it1, it2);
	comp("cit1, cit2", cit1, cit2);

	comp("it1, it2", it1, it2 + 3);
	comp("cit1, cit2", cit1 + 4, cit2);

	it2 = a.end();
	cit2 = a.end();
	comp("it1, it2", it1, it2);
	comp("cit1, cit2", cit1, cit2);

	comp("it1, it2", it1 + 3, it2 - 3);
	comp("it1, it2", it1 + 11, it2 - 3);

	comp("cit1, cit2", cit1 + 3, cit2 - 3);
	comp("cit1, cit2", cit1 + 11, cit2 - 3);

	printSize("a", a);

	return 0;
}
