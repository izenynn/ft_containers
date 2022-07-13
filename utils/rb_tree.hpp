/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:42:41 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/13 22:59:32 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP_
# define RB_TREE_HPP_

# include <memory>

# include "nullptr_t.hpp"

namespace ft {
	template<class T>
	struct rbnode {
		// constants
		enum e_color {
			RED = true,
			BLACK = false
		};
		enum e_side {
			LEFT = 0,
			RIGHT = 1
		};

		// typedefs
		typedef T	value_type;

		// family
		rbnode*		parent, children[2];

		// node content
		bool		color;
		value_type	data;

		// constructors
		//node() : color(k_red) {}

		rbnode(const value_type& value, rbnode* nil)
		: color(rbnode::e_color::RED),
		  data(value),
		  parent(nil) {}

		rbnode(const rbnode& other)
		: parent(other.parent),
		  children(other.children),
		  color(other.color),
		  data(other.data) {}

		~rbnode() {}

		// member functions
		inline value_type& getData() { return this->data; }

		inline bool isBlack() { return this->color == rbnode::e_color::BLACK; }
		inline bool isRed() { return this->color == rbnode::e_color::RED; }
		inline rbnode::e_color getColor() { return this->color; }

		inline void setBlack() { this->color = rbnode::e_color::BLACK; return; }
		inline void setRed() { this->color = rbnode::e_color::RED; return; }
		/*inline void swapColor(rbnode& other) {
			rbnode::e_color aux = this->color;
			this->color = other.color;
			other.color = aux;
		}

		inline bool isLeft() {
			assert(this->parent->children[rbnode::e_side::LEFT] == this);
			return this->parent->children[rbnode::e_side::LEFT] == this;
		}
		inline bool isRight() {
			assert(this->parent->children[rbnode::e_side::LEFT] == this);
			return this->parent->children[rbnode::e_side::LEFT] == this;
		}

		inline void swapSide() {
			assert(this->parent->children[rbnode::e_side::LEFT] == this
					|| this->parent->children[rbnode::e_side::RIGHT] == this);
			rbnode* aux = this->parent[rbnode::e_side::LEFT];
			this->parent[rbnode::e_side::LEFT] = this->parent[rbnode::e_side::RIGHT];
			this->parent[rbnode::e_side::RIGHT] = aux;
		}

		inline rbnode* getBrother() {
			if (this->parent == ft::nullptr_t) return ft::nullptr_t;

			assert(this->parent->children[rbnode::e_side::LEFT] == this
					|| this->parent->children[rbnode::e_side::RIGHT] == this);
			return (this->parent->children[rbnode::e_side::LEFT] == this
					? this->parent->children[rbnode::e_side::LEFT]
					: this->parent->children[rbnode::e_side::RIGHT]);
		}*/
	};

	template<class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class rbtree {
		public:
			// typedefs
			typedef T				value_type;
			typedef Allocator		allocator_type;
			typedef std::size_t		size_type;
			typedef std::ptrdiff_t	difference_type;

			typedef Compare		compare;

			//typedef typename Allocator::reference			reference;
			//typedef typename Allocator::const_reference		const_reference;
			//typedef typename Allocator::pointer				pointer;
			//typedef typename Allocator::const_pointer		const_pointer;

			typedef ft::rbnode<T>											node_type;
			typedef typename Allocator::template rebind<node_type>::other	node_allocator;
			typedef typename node_allocator::pointer						pointer;
			typedef typename node_allocator::const_pointer					const_pointer;
			typedef typename node_allocator::reference						reference;
			typedef typename node_allocator::const_reference				const_reference;

			//typedef ft::rbtree_iterator<pointer>					iterator;
			//typedef ft::rbtree_iterator<const_pointer>				const_iterator;
			//typedef ft::rbtree_reverse_iterator<iterator>			reverse_iterator;
			//typedef ft::rbtree_reverse_iterator<const_iterator>	const_reverse_iterator;

			// variables
			pointer 	node_root;
			pointer		node_nil;
			size_type	size;

			Compare		comp;

			allocator_type	alloc;
			node_allocator	node_alloc;

			//rbtree() : ;

		private:
	};
}

#endif
