#ifndef COMMON_HPP_
# define COMMON_HPP_

# include "../tester.hpp"
# include <iostream>

# define t_set ft::set<foo<int> >

template<class Pair>
void printPair(const Pair& it) {
	std::cout << "key: " << *it << std::endl;
}

template<class Key>
void printSize(const std::string& name, const ft::set<Key>& s) {
	std::cout << "\nvar name: " << name
		<< "\nsize: " << s.size()
		<< std::boolalpha << "is_empty: " << s.empty()
		<< "\nsize: " << s.size()
		<< "\nmax_size: " << s.max_size()
		<< "\ncontent:\n";
	for (typename ft::set<Key>::const_iterator it = s.begin(); it != s.end(); ++it) {
		std::cout << "- key: " << *it << '\n';
	}
}

#endif
