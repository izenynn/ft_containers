/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 01:10:13 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/11 11:24:36 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP_
# define ITERATOR_HPP_

# include "nullptr_t.hpp"
# include "iterator_traits.hpp"

namespace ft {
	template<class T>
	class iterator {
		protected:
			T	current;

		public:
			// typedefs
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

			// constructors
			iterator(void) : current(ft::nullptr_t)
			{}

			explicit iterator(const T& other)
			: current(other)
			{}

			template<class U>
			iterator(const iterator<U>& other)
			: current(other.base())
			{}

			virtual ~iterator(void)
			{}

			// assign operator
			template<class U>
			iterator& operator=(const iterator<U>& other) {
				if (this == &other) return *this;
				this->current = other.base();
				return *this;
			}

			// getter
			T base(void) const { return this->current; }

			// access operators
			reference operator*(void) const { return *(this->current); }
			pointer operator->(void) const { return this->current; }
			reference operator[](difference_type n) const { return *(this->current + n); }

			// arithmetic operators
			iterator& operator++(void) {
				++this->current;
				return *this;
			}
			iterator& operator--(void) {
				--this->current;
				return *this;
			}
			iterator operator++(int) {
				iterator ret(*this);
				++this->current;
				return ret;
			}
			iterator operator--(int) {
				iterator ret(*this);
				--this->current;
				return ret;
			}
			iterator operator+(difference_type n) const {
				return iterator(this->current + n);
			}
			iterator operator-(difference_type n) const {
				return iterator(this->current + (-n));
			}
			iterator& operator+=(difference_type n) const {
				*this = *this + n;
				return *this;
			}
			iterator& operator-=(difference_type n) const {
				*this = *this + (-n);
				return *this;
			}
	};

	// iterator & iterator operators
	template<class T, class U>
	bool operator>(const ft::iterator<T>& lhs, const ft::iterator<U>& rhs) {
		return lhs.base() > rhs.base();
	}
	template<class T, class U>
	bool operator<(const ft::iterator<T>& lhs, const ft::iterator<U>& rhs) {
		return rhs > lhs;
	}
	template<class T, class U>
	bool operator>=(const ft::iterator<T>& lhs, const ft::iterator<U>& rhs) {
		return !(rhs > lhs);
	}
	template<class T, class U>
	bool operator<=(const ft::iterator<T>& lhs, const ft::iterator<U>& rhs) {
		return !(lhs > rhs);
	}
	template<class T, class U>
	bool operator==(const ft::iterator<T>& lhs, const ft::iterator<U>& rhs) {
		return lhs.base() == rhs.base();
	}
	template<class T, class U>
	bool operator!=(const ft::iterator<T>& lhs, const ft::iterator<U>& rhs) {
		return !(lhs == rhs);
	}
	template<class T, class U>
	typename ft::iterator<T>::difference_type operator-(const ft::iterator<T>& lhs, const ft::iterator<U>& rhs) {
		return lhs.base() - rhs.base();
	}
	template<class T>
	iterator<T> operator+(typename ft::iterator<T>::difference_type n, const ft::iterator<T>& other) {
		return ft::iterator<T>(other.base() + n);
	}
}

#endif
