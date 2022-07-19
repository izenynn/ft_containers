#ifndef COMMON_HPP_
# define COMMON_HPP_

# include "../tester.hpp"
# include <iostream>
# include <vector>

template <class T>
void printSize(const std::string& name, const ft::vector<T>& v) {
	std::cout << "var name: " << name
		<< "size: " << v.size()
		<< std::boolalpha << "capacity > size: " << (v.capacity() >= v.size())
		<< "max_size: " << v.max_size()
		<< "\ncontent:\n";
	for (typename ft::vector<T>::const_iterator it = v.begin(); it < v.end(); ++it) {
		std::cout << "- " << *it << '\n';
	}
}

#endif
