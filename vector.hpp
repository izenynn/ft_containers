/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:56:18 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/10 17:39:01 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP_
# define VECTOR_HPP_

# include <memory>

# include "utils/iterator.hpp"
# include "utils/reverse_iterator.hpp"
# include "utils/iterator_traits.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// typedef
			typedef T			value_type;
			typedef Allocator	allocator_type;
			typedef size_t		size_type;
			typedef ptrdiff_t	defference_type;

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

			typedef ft::iterator<pointer>					iterator;
			typedef ft::iterator<const_pointer>				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			// constructors
			vector(void) : base()
			{}

			explicit vector(const allocator_type& alloc) : base(alloc)
			{}

			explicit
			vector(size_type n, const value_type& value = value_type(), const Allocator& alloc = Allocator())
			: base(n, value, alloc)
			{}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			: base(first, last, alloc)
			{}

			vector(const vector& other)
			: base(other)
			{}

			~vector(void)
			{}

			vector(const base& other)
			: base(other)
			{}

			vector&
			operator=(const vector& other) {
				;
			}

			template<typename InputIterator, typename std::_RequireInputIter<InputIterator> >
			void
			assign(InputIterator first, InputIterator last) {
				;
			}

			void
			assign(size_type n, const T& u) {
				;
			}

			//using base::get_allocator;

			// iterators
			iterator begin() { return iterator(base::begin(), this); }
			const_iterator begin() const { return const_iterator(base::begin(), this); }

			iterator end() { return iterator(base::begin(), this); }
			const_iterator end() const { return const_iterator(base::begin(), this); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const { return reverse_iterator(end()); }

			reverse_iterator rend() { return reverse_iterator(begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			// 23.2.4.2 capacity:
			//using base::size;
			//using base::max_size;

			void
			resize(size_type sz, T c = T()) {
				;
			}

			size_type
			capacity() const {
				;
			}

			//usign base::empty

			void
			reserve(size_type n) {
				;
			}

			// element access
			reference
			operator[](size_type n) {
				;
			}
			const_reference
			operator[](size_type n) const {
				;
			}

			//using base::at;

			reference
			front() {
				;
			}
			const_reference
			front() const {
				;
			}

			reference
			back() {
				;
			}
			const_reference
			back() const {
				;
			}

			// 23.2.4.3 modifiers:
			void
			push_back(const T& x) {
				;
			}

			void
			emplace_back(Args&&... args) {
				;
			}

			void
			pop_back() {
				;
			}

			iterator
			insert(iterator position, const T& x) {
				;
			}

			void
			insert(iterator position, size_type n, const T& x) {
				;
			}

			template<class InputIterator>
			void
			insert(iterator position, InputIterator first, InputIterator last) {
				;
			}

			iterator
			erase(iterator position) {
				;
			}
			iterator
			erase(iterator first, iterator last) {
				;
			}

			void
			swap(vector& x) {
				;
			}

			void
			clear() {
				;
			}

			base&
			m_base() { return *this; }
			const base&
			m_base() const { return *this; }

		private:
			pointer			_begin;
			pointer			_end;
			size_type		_size;
			allocator_type	_alloc; // end cap
			size_type		_capacity; // end cap
	};

	template<typename T, typename Alloc>
	inline bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return lhs.m_base() == rhs.m_base();
	}

	// etc... more operators
}

#endif
