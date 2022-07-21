#ifndef COMMON_HPP_
# define COMMON_HPP_

# include "../tester.hpp"
# include <iostream>

# define t_map ft::map<int, foo<int> >

template<class Pair>
void printPair(const Pair& it) {
	std::cout << "pair first: " << it->first << ", second: " << it->second << std::endl;
}

template<class Key, class T>
void printSize(const std::string& name, const ft::map<Key, T>& m) {
	std::cout << "\nvar name: " << name
		<< "\nsize: " << m.size()
		<< std::boolalpha << "is_empty: " << m.empty()
		<< "\nsize: " << m.size()
		<< "\nmax_size: " << m.max_size()
		<< "\ncontent:\n";
	for (typename ft::map<Key, T>::const_iterator it = m.begin(); it != m.end(); ++it) {
		std::cout << "- key: " << it->first << ", value: " << it->second << '\n';
	}
}

#endif
