/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:13:37 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/15 15:04:12 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP_
# define MAP_HPP_

# include <memory>

# include "utils/pair.hpp"
# include "utils/rb_node.hpp"
# include "utils/rb_tree.hpp"
# include "utils/rb_iterator.hpp"
# include "utils/reverse_iterator.hpp"
# include "utils/swap.hpp"
# include "utils/equal.hpp"
# include "utils/lexicographical_compare.hpp"

namespace ft {
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> >
	> class map {
		public:
			// typedefs
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;

			typedef ft::rbnode<value_type>					node_type;
			typedef node_type*								node_pointer;
			typedef node_type&								node_reference;

			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			class value_compare {
				public:
					typedef key_compare comp;
					bool operator()(const value_type& lhs, const value_type& rhs) const {
						return comp()(lhs.first, rhs.first);
					}
			};

			typedef ft::rbtree<value_type, value_compare, allocator_type>	tree_type;
			typedef typename tree_type::iterator							iterator;
			typedef typename tree_type::const_iterator						const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			// constructors
			explicit
			map(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
			: _tree(), _comp(comp), _alloc(alloc), _value_comp(value_compare()) {}

			template<class InputIterator>
			map(InputIterator first,
					InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) {
				this->_comp = comp;
				this->_alloc = alloc;
				this->_value_comp = value_compare();
				for (InputIterator it = first; it != last; ++it) {
					this->_tree.insert(*it);
				}
			}

			map(const map& other) : _tree(other._tree.comp, other._tree.alloc) {
				insert(other.begin(), other.end());
			}

			~map() { this->clear(); }

			// assign operator
			map& operator=(const map& other) {
				this->clear();
				this->insert(other.begin(), other.end());
				this->_alloc = other._alloc;
				this->_comp = other._comp;
				this->_value_comp = other._value_comp;
				return (*this);
			}

			// iterators
			iterator				begin() { return this->_tree.begin(); }
			const_iterator			begin() const { return this->_tree.begin(); }
			iterator				end() { return this->_tree.end(); }
			const_iterator			end() const { return this->_tree.end(); }

			reverse_iterator		rbegin() { return this->_tree.rbegin(); }
			const_reverse_iterator	rbegin() const { return this->_tree.rbegin(); }
			reverse_iterator		rend() { return this->_tree.rend(); }
			const_reverse_iterator	rend() const { return this->_tree.rend(); }

			// capacity
			bool empty() const { return this->_tree.empty(); }
			size_type size() const { return this->_tree.getSize(); }
			size_type max_size() const { return this->_tree.getMaxSize(); }

			// operators
			mapped_type& operator[](const key_type& x) {
				iterator ret = this->find(x);
				if (ret == this->end()) {
					this->insert(ft::make_pair(x, mapped_type()));
					ret = this->find(x);
				}
				return ret->second;
			}

			// member functions
			ft::pair<iterator, bool> insert(const value_type& value) {
				return this->_tree.insert(value);
			}
			iterator insert(iterator hint, const value_type& value) {
				// don't wanna implement this, it's already quite fast >.<
				(void)hint;
				return this->_tree.insert(value).first;
			}
			template<class InputIt>
			void insert(InputIt first, InputIt last) {
				for (InputIt it = first; it != last; ++it) {
					this->_tree.insert(*it);
				}
			}

			void erase(iterator pos) {
				this->_tree.remove(*pos);
			}
			void erase(iterator first, iterator last) { // FIXME not working
				for (iterator it = first; it != last;) {
					this->_tree.remove(*(it++));
				}
			}
			size_type erase(const key_type& key) {
				iterator res = this->find(key);
				if (res != this->end()) {
					this->_tree.remove(*res);
					return 1;
				}
				return 0;
			}

			void swap(map& other) {
				this->_tree.swap(other._tree);
				ft::swap(this->_comp, other._comp);
				ft::swap(this->_alloc, other._alloc);
				ft::swap(this->_value_comp, other._value_comp);
			}

			void clear() { this->_tree.clear(); }
			key_compare key_comp() const { return this->_comp; }
			value_compare value_comp() const { return this->_value_comp; }

			iterator find(const key_type& key) {
				node_pointer res = this->_tree.find(ft::make_pair(key, mapped_type()));
				if (res != ft::nullptr_t) {
					return iterator(res, this->_tree.getNodeRoot(), this->_tree.getNodeNil());
				}
				return this->end();
			}
			const_iterator find(const key_type& key) const {
				node_pointer res = this->_tree.find(ft::make_pair(key, mapped_type()));
				if (res != ft::nullptr_t) {
					return const_iterator(res, this->_tree.getNodeRoot(), this->_tree.getNodeNil());
				}
				return this->end();
			}

			size_type count(const key_type& key) const {
				if (this->_tree.find(ft::make_pair(key, mapped_type())) != ft::nullptr_t) {
					return 1;
				}
				return 0;
			}

			iterator lower_bound(const key_type& key) {
				for (iterator it = this->begin(); it != this->end(); ++it) {
					if(this->_value_comp(ft::make_pair(key, mapped_type()), it.getCurrent()->data)
							|| !(this->_value_comp(it.getCurrent()->data, ft::make_pair(key, mapped_type()))))
						return it;
				}
				return this->end();
			}
			const_iterator lower_bound(const key_type& key) const {
				for (const_iterator it = this->begin(); it != this->end(); ++it) {
					if(this->_value_comp(ft::make_pair(key, mapped_type()), it.getCurrent()->data)
							|| !(this->_value_comp(it.getCurrent()->data, ft::make_pair(key, mapped_type()))))
						return it;
				}
				return this->end();
			}

			iterator upper_bound(const key_type& key) {
				for (iterator it = this->begin(); it != this->end(); ++it) {
					if(this->_value_comp(ft::make_pair(key, mapped_type()), it.getCurrent()->data)) {
						return it;
					}
				}
				return this->end();
			}
			const_iterator upper_bound(const key_type& key) const {
				for (const_iterator it = this->begin(); it != this->end(); ++it) {
					if(this->_value_comp(ft::make_pair(key, mapped_type()), it.getCurrent()->data)) {
						return it;
					}
				}
				return this->end();
			}

			ft::pair<iterator, iterator> equal_range(const key_type& key) {
				return ft::make_pair(this->lower_bound(key), this->upper_bound(key));
			}
			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
				return ft::make_pair(this->lower_bound(key), this->upper_bound(key));
			}

			allocator_type get_allocator() const { return this->_alloc; }

		private:
			tree_type		_tree;
			key_compare		_comp;
			allocator_type	_alloc;
			value_compare	_value_comp;
	};

	// non-member operators
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		if (lhs.size() != rhs.size()) {
			return false;
		}
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return rhs < lhs;
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return !(rhs < lhs);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ) {
		return !(lhs < rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs) {
		lhs.swap(rhs);
	}
}

#endif
