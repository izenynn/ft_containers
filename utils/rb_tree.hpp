/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:42:41 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/14 10:59:21 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP_
# define RB_TREE_HPP_

# include <memory>

# include "nullptr_t.hpp"
# include "pair.hpp"

namespace ft {
	template<class T>
	struct rbnode {
		// typedefs
		typedef T		value_type;
		typedef bool	color_type;

		// constants
		enum e_color {
			RED = true,
			BLACK = false
		};

		// family
		rbnode*		parent, left, right;

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
		  left(other.left),
		  right(other.right),
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

		inline void setParent() {}
		inline void setLeft() {}
		inline void setRight() {}
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

			// constructors
			rbtree() : size(0), comp(compare()) {
				// TODO use nodeCreate instead?
				this->node_nil = this->node_alloc.allocate(1);
				this->node_alloc.construct(this->node_nil, value_type());

				this->node_nil->setBlack;
				this->node_nil->parent = this->node_nil;
				this->node_nil->left = this->node_nil;
				this->node_nil->right = this->node_nil;

				this->node_root = this->node_nil;
			}
			rbtree(const rbtree& other) {
				*this = other;
			}
			~rbtree() {
				this->clear();
				this->node_alloc.destroy(this->node_nil);
				this->node_alloc.deallocate(this->node_nil, 1);
			}

			// generic functions
			size_type getSize() const { return this->size; }
			size_type getMaxSize() const { return this->node_alloc.max_size(); }

			pointer getNodeRoot() const { return this->node_root; }
			pointer getNodeNil() const { return this->node_nil; }

			// red-black tree functions
			void clear() {
				if (this->node_root != this->node_nil) {
					recursiveRemove(this->node_root);
					this->size = 0;
					this->node_root = this->node_nil;
				}
			}
			ft::pair<iterator, bool> insert(const value_type& content) {
				;
			}
			//TODO remove
			//TODO empty
			//TODO swap ???
			pointer min() const {
				pointer it = this->node_root;
				if (it == this->node_nil) return it;
				for(pointer it = this->node_root; it->left != this->node_nil ; it = it->left) {
					return it;
				}
			}
			pointer max() const {
				pointer it = this->node_root;
				if (it == this->node_nil) return it;
				for(pointer it = this->node_root; it->right != this->node_nil ; it = it->right) {
					return it;
				}
			}
			pointer find(const value_type& x) const {
				for (pointer it = this->node_root; it != this->node_nil; ) {
					if (this->comp(x, it->data)) {
						it = it->left;
					} else if (this->comp(it->data, x)) {
						it = it->right;
					} else {
						return it;
					}
				}
				return ft::nullptr_t;
			}

			// algos
			void recursiveRemove(pointer x) {
				pointer aux;
				while (x != this->node_nil) {
					this->recursiveRemove(x->right);
					aux = x->left;
					this->nodeRemove(x);
					x = aux;
				}
			}
			pointer nodeCreate(const value_type& content, pointer parent) {
				pointer node = this->node_alloc.allocate(1);
				this->node_alloc.construct(node, content);
				node->parent = parent;
				node->left = this->node_nil;
				node->right = this->node_nil;
				node->setRed();
				return node;
			}
			//TODO nodeRemove ???
			void rotateLeft(pointer node) {
				pointer aux = node->right;
				node->right = aux->left;
				if (aux->left != this->node_nil) {
					aux->left->parent = node;
				}
				aux->parent = node->parent;
				if (node->parent == this->node_nil) this->node_root = aux;
				else if (node->isLeft()) node->parent->left = aux;
				else node->parent->right = aux;
				aux->left = node;
				node->parent = aux;
			}
			void rotateRight(pointer node) {
				pointer aux = node->left;
				node->left = aux->right;
				if (aux->right != this->node_nil) {
					aux->right->parent = node;
				}
				aux->parent = node->parent;
				if (node->parent == this->node_nil) this->node_root = aux;
				else if (node->isLeft()) node->parent->left = aux;
				else node->parent->right = aux;
				aux->right = node;
				node->parent = aux;
			}
			inline void swapColor(node_type& n1, node_type& n2) {
				typename node_type::color_type aux = n1.color;
				n1->color = n2->color;
				n2->color = aux;
			}
			//TODO replace ???

			// iterator
			//TODO begin
			//TODO end
			//TODO rbegin
			//TODO rend

			//TODO debug (print all tree)

		private:
			// i mean, no, i don't need this and i don't wanna implement it
			rbtree& operator=(const rbtree& other) {}
	};
}

#endif
