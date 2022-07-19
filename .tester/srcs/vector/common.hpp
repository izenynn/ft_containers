#ifndef COMMON_HPP_
# define COMMON_HPP_

# include "../tester.hpp"
# include <iostream>
# include <vector>

template <class T>
void printSize(const std::string& name, const ft::vector<T>& v) {
	std::cout << "\nvar name: " << name
		<< "\nsize: " << v.size()
		<< std::boolalpha << "is_empty: " << v.empty()
		<< "\ncapacity > size: " << (v.capacity() >= v.size())
		<< "\nmax_size: " << v.max_size()
		<< "\ncontent:\n";
	for (typename ft::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << "- " << *it << '\n';
	}
}

#endif
