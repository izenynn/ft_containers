/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:56:18 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/11 19:41:15 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP_
# define VECTOR_HPP_

# include <iostream> // TODO remove this

# include <memory>

# include "utils/iterator.hpp"
# include "utils/reverse_iterator.hpp"
# include "utils/iterator_traits.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/swap.hpp"

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// typedef
			typedef T				value_type;
			typedef Allocator		allocator_type;
			typedef std::size_t		size_type;
			typedef std::ptrdiff_t	difference_type;

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

			typedef ft::iterator<pointer>					iterator;
			typedef ft::iterator<const_pointer>				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			// constructors
			vector(void)
			: _begin(ft::nullptr_t), _size(0), _capacity(0), _alloc(std::allocator<T>())
			{}

			explicit
			vector(const allocator_type& alloc)
			: _begin(ft::nullptr_t), _size(0), _capacity(0), _alloc(alloc)
			{}

			explicit
			vector(size_type n, const value_type& value = value_type(), const Allocator& alloc = Allocator())
			: _size(n), _capacity(n), _alloc(alloc) {
				this->_begin = this->_alloc.allocate(n);
				this->insert(this->begin(), n, value);
			}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			: _alloc(alloc) {
				size_type cnt = 0;
				for (InputIterator it = first; it != last; ++it) ++cnt;
				this->_begin = this->_alloc.allocate(cnt);
				this->_capacity = cnt;
				this->insert(this->_begin, first, last);
			}

			vector(const vector& other)
			: _size(other._size), _capacity(other._capacity), _alloc(other._alloc) {
				this->_begin = this->_alloc.allocate(this->_capacity);
				this->insert(this->begin(), other.begin(), other.end());
			}

			~vector(void) {
				this->_alloc.deallocate(this->_begin, this->_capacity);
			}

			//vector(const base& other)
			//: base(other)
			//{}

			vector&
			operator=(const vector& other) {
				if (this != &other) {
					this->clear();
					this->_alloc.deallocate(this->_begin, this->_capacity());
					this->_alloc = other.get_allocator();
					this->_begin = this->_alloc.allocate(other._capacity);
					this->_capacity = other._capacity;
					this->insert(this->_begin, other._begin, other.end());
				}
				return *this;
			}

			// assing
			template<typename InputIterator>
			void
			assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
				this->clear();
				this->insert(this->begin(), first, last);
			}

			void
			assign(size_type n, const T& u) {
				this->clear();
				this->insert(this->begin(), n, u);
			}

			//using base::get_allocator;
			allocator_type get_allocator() const { return this->_alloc; }

			// iterators
			iterator begin(void) { return iterator(this->_begin); }
			const_iterator begin(void) const { return const_iterator(this->_begin); }

			iterator end(void) { return iterator(this->_begin + this->_size); }
			const_iterator end(void) const { return const_iterator(this->_begin + this->_size); }

			reverse_iterator rbegin(void) { return reverse_iterator(end()); }
			const_reverse_iterator rbegin(void) const { return const_reverse_iterator(end()); }

			reverse_iterator rend(void) { return reverse_iterator(begin()); }
			const_reverse_iterator rend(void) const { return const_reverse_iterator(begin()); }

			// 23.2.4.2 capacity:
			//using base::size;
			size_type size() const { return this->_size; }
			//using base::max_size;
			size_type max_size() const { return this->_alloc.max_size(); }

			void
			resize(size_type sz, T c = T()) {
				if (sz > this->_size) {
					this->insert(this->end(), sz - size(), c);
				} else {
					while (this->_size - sz != 0) { erase(this->end() - 1); }
				}
			}

			size_type capacity() const { return this->_capacity; }

			//usign base::empty
			bool empty() const { return _size == 0; }

			void
			reserve(size_type n) {
				if (n > this->max_size())
					throw std::length_error("max capacity");
				if (n > this->_capacity) {
					// METHOD 1
					//pointer oldBegin = this->_begin;
					//size_type oldCapacity = this->_capacity;
					//pointer aux = this->_alloc.allocate(n); // !!!
					//this->insert(iterator(aux), this->begin(), this->end());
					//this->_begin = aux;
					//this->_capacity = n;
					//this->_alloc.deallocate(oldBegin, oldCapacity);
					// METHOD 2
					//std::cout << "====\n" << n << std::endl;
					pointer aux = this->_alloc.allocate(n); // segfault here
					for (size_type i = 0; i < this->_size; ++i) {
						this->_alloc.construct(aux + i, *(this->_begin + i));
					}
					this->_alloc.deallocate(this->_begin, this->_capacity);
					this->_begin = aux;
					this->_capacity = n;
				}
			}

			// element access
			reference operator[](size_type n) { return *(this->_begin + n); }
			const_reference operator[](size_type n) const { return *(this->_begin + n); }

			//using base::at;
			reference at(size_type n) {
				if (n >= this->_size)
					throw std::out_of_range("out of range");
				return *(this->_begin + n);
			}
			const_reference at(size_type n) const {
				if (n < 0 || n >= this->_size)
					throw std::out_of_range("out of range");
				return *(this->_begin + n);
			}

			reference front(void) { return *(this->_begin); }
			const_reference front(void) const { return *(this->_begin); }

			reference back(void) { return *(this->_begin + this->_size - 1); }
			const_reference back(void) const { return *(this->_begin + this->_size - 1); }

			value_type* data(void) { return this->_begin; }

			// 23.2.4.3 modifiers:
			void push_back(const T& x) { this->insert(this->end(), x); }
			void pop_back() { this->erase(--end()); }

			iterator
			insert(iterator position, const T& x) {
				std::cout << "SIZE: " << this->_size << "\n";
				std::cout << "CAPACITY: " << this->_capacity << std::endl;
				if (this->_size == this->_capacity) {
					// get distance
					//size_type offset = 0;//begin, position
					//iterator aux1 = iterator(this->_begin);
					//iterator aux2 = iterator(position);
					//for (; aux1 != aux2; ++aux1) ++offset;
					//
					size_type offset = position - this->begin();
					this->reserve(this->_size + 1);
					position = this->begin() + offset;
				}
				for (iterator it = this->end(); it > position; --it) {
					this->_alloc.construct(it.base(), *(it - 1)); // [!] SEGV on unknown address
					//this->_alloc.destroy(it.base() + 1);
				}
				this->_alloc.construct(position.base(), x);
				++(this->_size);
				return (position);

				//if (this->_size == this->_capacity) {
				//	;
				//}
				//for (iterator it = this->end(); it > position; --it) {
				//	this->_alloc.construct(position.base(), *(it - 1));
				//}
				//this->_size++;
				//if (position - this->_begin())
			}

			// TODO no llamar a "insert" por cada elemento que da stack overflow xdxdxd
			void
			insert(iterator position, size_type n, const T& x) {
				for (size_type i = 0; i < n; ++i) {
					position = insert(position, x);
					++position;
				}
			}

			// TODO no llamar a "insert" por cada elemento que da stack overflow xdxdxd
			template<class InputIterator>
			void
			insert(iterator position, InputIterator first, InputIterator last) {
				while (first != last) {
					position = insert(position, *first);
					++position;
					++first;
				}
			}

			iterator
			erase(iterator position) {
				if (position != this->end()) {
					this->_alloc.destroy(position.base());
				}
				for (iterator it = position; it < this->end() - 1; ++it) {
					this->_alloc.construct(it.base(), *(it + 1));
					//this->_alloc.construct(it, *(it + 1));
				}
				--(this->_size);
				return (position);
			}
			iterator
			erase(iterator first, iterator last) {
				while (first != last) {
					erase(--last);
				}
				return (last);
			}

			void
			swap(vector& x) {
				ft::swap(this->_begin, x._begin);
				ft::swap(this->_size, x._size);
				ft::swap(this->_capacity, x._capacity);
				ft::swap(this->_alloc, x._alloc);
			}

			void clear() { erase(this->begin(), this->end()); }

			//base&
			//m_base() { return *this; }
			//const base&
			//m_base() const { return *this; }

		private:
			pointer			_begin;
			size_type		_size;
			size_type		_capacity; // end cap
			allocator_type	_alloc;
	};

	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		if (lhs._size != rhs._size) {
			return false;
		}
		iterator<T> lhsBegin = lhs._begin;
		iterator<T> lhsEnd = lhs.end();
		iterator<T> rhsBegin = rhs._begin;
		while (lhsBegin != lhsEnd) {
			if (*lhsBegin != *rhsBegin) return false;
			++lhsBegin;
			++rhsBegin;
		}
		return true;
	}
	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		iterator<T> lhsBegin = lhs->begin();
		iterator<T> lhsEnd = lhs->end();
		iterator<T> rhsBegin = rhs.begin();
		iterator<T> rhsEnd = rhs.end();
		while (lhsBegin != lhsEnd) {
			if (rhsBegin == rhsEnd || *rhsBegin < *lhsBegin) return false;
			else if (*lhsBegin < *rhsBegin) return true;
			++lhsBegin;
			++rhsBegin;
		}
		return rhsBegin != rhsEnd;
	}
	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return (rhs < lhs);
	}
	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}
	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs) {
		lhs.swap(rhs);
	}
}

#endif
