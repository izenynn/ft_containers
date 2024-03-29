/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 08:56:18 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/26 17:20:02 by dpoveda-         ###   ########.fr       */
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
# include "utils/swap.hpp"
# include "utils/equal.hpp"
# include "utils/lexicographical_compare.hpp"

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
			: _size(0), _capacity(n), _alloc(alloc) {
				this->_begin = this->_alloc.allocate(n);
				this->insert(this->begin(), n, value);
			}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			: _size(0), _alloc(alloc) {
				size_type cnt = 0;
				for (InputIterator it = first; it != last; ++it) ++cnt;
				this->_begin = this->_alloc.allocate(cnt);
				this->_capacity = cnt;
				this->insert(this->begin(), first, last);
			}

			vector(const vector& other)
			: _size(0), _capacity(other._capacity), _alloc(other._alloc) {
				this->_begin = this->_alloc.allocate(this->_capacity);
				this->insert(this->begin(), other.begin(), other.end());
			}

			~vector(void) {
				this->_alloc.deallocate(this->_begin, this->_capacity);
			}

			vector&
			operator=(const vector& other) {
				if (this != &other) {
					this->clear();
					this->_alloc.deallocate(this->_begin, this->capacity());
					this->_alloc = other.get_allocator();
					this->_begin = this->_alloc.allocate(other._capacity);
					this->_capacity = other._capacity;
					this->insert(this->begin(), other.begin(), other.end());
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

			allocator_type get_allocator() const { return this->_alloc; }

			// iterators
			iterator begin(void) { return iterator(this->_begin); }
			const_iterator begin(void) const { return const_iterator(this->_begin); }

			iterator end(void) { return iterator(this->_begin + this->_size); }
			const_iterator end(void) const { return const_iterator(this->_begin + this->_size); }

			reverse_iterator rbegin(void) { return reverse_iterator(this->end()); }
			const_reverse_iterator rbegin(void) const { return const_reverse_iterator(this->end()); }

			reverse_iterator rend(void) { return reverse_iterator(this->begin()); }
			const_reverse_iterator rend(void) const { return const_reverse_iterator(this->begin()); }

			size_type size() const { return this->_size; }
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

			bool empty() const { return _size == 0; }

			void
			reserve(size_type n) {
				if (n > this->max_size())
					throw std::length_error("max capacity");
				if (n > this->_capacity) {
					pointer aux = this->_alloc.allocate(n);
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

			reference at(size_type n) {
				if (n >= this->_size)
					throw std::out_of_range("out of range");
				return *(this->_begin + n);
			}
			const_reference at(size_type n) const {
				if (n >= this->_size)
					throw std::out_of_range("out of range");
				return *(this->_begin + n);
			}

			reference front(void) { return *(this->_begin); }
			const_reference front(void) const { return *(this->_begin); }

			reference back(void) { return *(this->_begin + this->_size - 1); }
			const_reference back(void) const { return *(this->_begin + this->_size - 1); }

			value_type* data(void) { return this->_begin; }

			void push_back(const T& x) { this->insert(this->end(), x); }
			void pop_back() { this->erase(--end()); }

			iterator
			insert(iterator position, const T& x) {
				if (this->_size == this->_capacity) {
					size_type offset = position - this->begin();
					this->reserve((this->_size + 1) * 2);
					position = this->begin() + offset;
				}
				for (iterator it = this->end(); it > position; --it) {
					this->_alloc.construct(it.base(), *(it - 1));
				}
				this->_alloc.construct(position.base(), x);
				++(this->_size);
				return (position);
			}

			void
			insert(iterator position, size_type n, const T& x) {
				for (size_type i = 0; i < n; ++i) {
					position = insert(position, x);
					++position;
				}

			}

			template<class InputIterator>
			void
			insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
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

		private:
			pointer			_begin;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
	};

	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		if (lhs.size() != rhs.size()) {
			return false;
		}
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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
