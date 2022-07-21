#include <iostream>
#include <list>
#include <set>

#include "set.hpp"

#define NAMESPACE ft

#define T1 std::string


template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "value: " << *iterator;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_SET>
void	printSize(T_SET const &st, bool print_content = 1)
{
	std::cout << "size: " << st.size() << std::endl;
	std::cout << "max_size: " << st.max_size() << std::endl;
	if (print_content)
	{
		typename T_SET::const_iterator it = st.begin(), ite = st.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//static int iter = 0;

template <typename SET, typename U>
void	ft_erase(SET &st, U param)
{
	//std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param);
	//printSize(st);
}

template <typename SET, typename U, typename V>
void	ft_erase(SET &st, U param, V param2)
{
	//std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param, param2);
	//printSize(st);
}

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(std::string((lst_size - i), i + 65));
	NAMESPACE::set<T1> st(lst.begin(), lst.end());
	//printSize(st);

	ft_erase(st, ++st.begin());

	ft_erase(st, st.begin());
	ft_erase(st, --st.end());

	ft_erase(st, st.begin(), ++(++(++st.begin())));
	ft_erase(st, --(--(--st.end())), --st.end());

	std::cout << "TREE:" << std::endl; st._tree.print(); // [!]
	st.insert("Hello");
	std::cout << "=================================\n" << std::endl;
	//std::cout << "TREE:" << std::endl; st._tree.print(); // [!]
	st.insert("Hi there");
	//printSize(st);
	//std::cout << "TREE:" << std::endl; st._tree.print(); // [!]
	ft_erase(st, --(--(--st.end())), st.end()); // head-use-after-free here
	//std::cout << *st.end() << std::endl;
	//std::cout << *(--st.end()) << std::endl;
	//std::cout << *(--(--st.end())) << std::endl;
	//std::cout << *(--(--(--st.end()))) << std::endl;
	//std::cout << *(--(--(--(--st.end())))) << std::endl;
	return 0;

	st.insert("ONE");
	st.insert("TWO");
	st.insert("THREE");
	st.insert("FOUR");
	//printSize(st);
	ft_erase(st, st.begin(), st.end());

	return (0);
}
