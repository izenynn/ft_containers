/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:13:37 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/14 15:09:04 by dpoveda-         ###   ########.fr       */
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

			typedef typename Allocator::size_type			size_type;
			typedef typename Allocator::difference_type		difference_type;

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

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

		private:
			tree_type		_tree;
			key_compare		_comp;
			allocator_type	_alloc;
			value_compare	_value_comp;
	};
}

#endif
