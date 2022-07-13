/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:44:40 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/13 13:13:31 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP_
# define PAIR_HPP_

namespace ft {
	template<class T1, class T2>
	struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first;
		T2	second;

		// constructors
		pair() : first(), second() {}
		pair(const first_type& x, const second_type& y) : first(x), second(y) {}

		template<class U1, class U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

		virtual ~pair() {}

		// assign operator
		pair& operator=(const pair& other) {
			//if (this == &other) return *this; // this can fail when using templates
			first = other.first;
			second = other.second;
			return *this;
		}
	};

	// non-members functions
	template<class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u) {
		return ft::pair<T1, T2>(t, u);
	}

	template <class T1, class T2>
	bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
	template <class T1, class T2>
	bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return !(lhs == rhs);
	}
	template <class T1, class T2>
	bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}
	template <class T1, class T2>
	bool operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return !(rhs < lhs);
	}
	template <class T1, class T2>
	bool operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return rhs < lhs;
	}
	template <class T1, class T2>
	bool operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return !(lhs < rhs);
	}
}

#endif
