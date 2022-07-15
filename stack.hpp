/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:59:50 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/15 08:46:17 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP_
# define STACK_HPP_

# include "vector.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
		public:
			// definitions
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;

			// constructors
			explicit stack(const container_type& cntr = container_type())
			: c(cntr) {}

			stack(const stack& other)
			: c(other.c) {}

			// destructors
			~stack(void) {}

			// operator
			stack& operator=(const stack& other) {
				if (this != &other) {
					this->c = other.c;
				}
				return *this;
			}

			// top
			reference top(void) {
				return this->c.back();
			}
			const_reference top(void) const {
				return this->c.back();
			}

			// empty
			bool empty(void) const {
				return this->c.empty();
			}

			// size
			size_type size(void) const {
				return this->c.size();
			}

			// operations
			void push(const value_type& value) {
				this->c.push_back(value);
			}
			void pop(void) {
				this->c.pop_back();
			}

			// operators
			template< class T1, class C1 >
			friend bool operator==(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
			template< class T1, class C1 >
			friend bool operator<(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);

		protected:
			container_type c;
	};

	// operators
	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (lhs.c == rhs.c);
	}
	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return !(lhs == rhs);
	}
	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (lhs.c < rhs.c);
	}
	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return !(rhs < lhs);
	}
	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return (rhs < lhs);
	}
	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ) {
		return !(lhs < rhs);
	}
}

#endif
