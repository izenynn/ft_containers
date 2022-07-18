#ifndef COMMON_HPP_
# define COMMON_HPP_

# include "../tester.hpp"
# include <iostream>
# include <vector>

template <class Stack>
void printSize(const std::string& name, Stack& stk) {
	std::cout << "var name: " << name
	<< std::boolalpha << "\nis empty: " << stk.empty()
	<< "\nsize: " << stk.size()
	<< "\ncontent:\n";
	while (stk.size() != 0) {
		std::cout << "- " << stk.top() << '\n';
		stk.pop();
	}
}
template <class Stack>
void printCopySize(const std::string& name, Stack& stk) {
	Stack* cp = new Stack(stk);

	std::cout << "var name: " << name
	<< std::boolalpha << "\nis empty: " << cp->empty()
	<< "\nsize: " << cp->size()
	<< "\ncontent:\n";
	while (cp->size() != 0) {
		std::cout << "- " << cp->top() << '\n';
		cp->pop();
	}

	delete cp;
}

#endif
