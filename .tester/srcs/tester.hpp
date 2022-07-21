/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:51:37 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/21 13:27:38 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP_
# define TESTER_HPP_

/* includes */

# include <iostream>
# include <string>
# include <deque>

# ifndef FT //CREATE A REAL STL EXAMPLE
	#include <stack>
	#include <vector>
	#include <map>
	#include <set>
	namespace ft = std;
# else
	#include "../../stack.hpp"
	#include "../../vector.hpp"
	#include "../../map.hpp"
	#include "../../set.hpp"
# endif

# include <stdlib.h>

/* foo class */

template<class T>
class foo {
	public:
		typedef T value_type;

		foo() : _value() {}
		foo(value_type value) : _value(value) {}
		foo(const foo& other) : _value(other._value) {}
		~foo() {}

		foo& operator=(value_type other) {
			this->_value = other; return *this;
		}
		foo& operator=(const foo& other) {
			this->_value = other._value;
			return *this;
		}

		value_type getValue() const { return this->_value; }

		operator value_type() const {
			return value_type(this->_value);
		}
	private:
		value_type _value;
};

template<class T>
std::ostream& operator<<(std::ostream& o, const foo<T>& x) {
	o << x.getValue();
	return o;
}

/* useful functions */

template<class T>
T nincrease(T it, int n) {
	while(n > 0) ++it, --n;
	return it;
}

template<class T>
T ndecrease(T it, int n) {
	while(n > 0) --it, --n;
	return it;
}

#endif
