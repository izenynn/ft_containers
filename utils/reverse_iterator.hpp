/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 01:10:13 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/12 00:48:42 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP_
# define REVERSE_ITERATOR_HPP_

# include "nullptr_t.hpp"
# include "iterator_traits.hpp"

namespace ft {
	template<class T>
	class reverse_iterator {
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
			reverse_iterator(void) : current(ft::nullptr_t)
			{}

			explicit reverse_iterator(const T& other)
			: current(other)
			{}

			template<class U>
			reverse_iterator(const reverse_iterator<U>& other)
			: current(other.base())
			{}

			virtual ~reverse_iterator(void)
			{}

			// assign operator
			template<class U>
			reverse_iterator& operator=(const reverse_iterator<U>& other) {
				//if (this == &other) return *this;
				this->current = other.base();
				return *this;
			}

			// getter
			T base(void) const { return this->current; }

			// access operators
			reference operator*(void) const { return *(--(T(this->current))); }
			pointer operator->(void) const { return &(operator*()); }
			reference operator[](difference_type n) const { return *(*this + n); }

			// arithmetic operators
			reverse_iterator& operator++(void) {
				--this->current;
				return *this;
			}
			reverse_iterator& operator--(void) {
				++this->current;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator ret(*this);
				--this->current;
				return ret;
			}
			reverse_iterator operator--(int) {
				reverse_iterator ret(*this);
				++this->current;
				return ret;
			}
			reverse_iterator operator+(difference_type n) const {
				return reverse_iterator(this->current + (-n));
			}
			reverse_iterator operator-(difference_type n) const {
				return reverse_iterator(this->current + n);
			}
			reverse_iterator& operator+=(difference_type n) {
				this->current += (-n);
				return *this;
			}
			reverse_iterator& operator-=(difference_type n) {
				this->current += n;
				return *this;
			}
	};

	// iterator & iterator operators
	template<class T, class U>
	bool operator>(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<U>& rhs) {
		return lhs.base() < rhs.base();
	}
	template<class T, class U>
	bool operator<(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<U>& rhs) {
		return rhs > lhs;
	}
	template<class T, class U>
	bool operator>=(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<U>& rhs) {
		return !(rhs > lhs);
	}
	template<class T, class U>
	bool operator<=(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<U>& rhs) {
		return !(lhs > rhs);
	}
	template<class T, class U>
	bool operator==(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<U>& rhs) {
		return lhs.base() == rhs.base();
	}
	template<class T, class U>
	bool operator!=(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<U>& rhs) {
		return !(lhs == rhs);
	}
	template<class T, class U>
	typename ft::reverse_iterator<T>::difference_type operator-(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<U>& rhs) {
		return rhs.base() - lhs.base();
	}
	template<class T>
	reverse_iterator<T> operator+(typename ft::reverse_iterator<T>::difference_type n, const ft::reverse_iterator<T>& other) {
		return ft::reverse_iterator<T>(other.base() - n);
	}
}

#endif
