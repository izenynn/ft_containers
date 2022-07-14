/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:42:41 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/14 19:59:17 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP_
# define RB_TREE_HPP_

# include <memory>
# include <functional> // std::less
# include <cassert> // assert()

# include "nullptr_t.hpp"
# include "pair.hpp"
# include "rb_iterator.hpp"
# include "reverse_iterator.hpp"
# include "swap.hpp"

namespace ft {
	template<class T>
	struct rbnode {
		// typedefs
		typedef T		value_type;
		typedef bool	color_type;

		// constants
		static const bool RED = true;
		static const bool BLACK = false;

		// family
		rbnode*		parent;
		rbnode*		left;
		rbnode*		right;

		// node content
		bool		color;
		value_type	data;

		// constructors
		//node() : color(k_red) {}

		rbnode(const value_type& value)
		: parent(ft::nullptr_t),
		  left(ft::nullptr_t),
		  right(ft::nullptr_t),
		  color(rbnode::BLACK),
		  data(value) {}
		rbnode(const value_type& value, rbnode* nil)
		: parent(nil),
		  left(nil),
		  right(nil),
		  color(rbnode::BLACK),
		  data(value) {}

		rbnode(const rbnode& other)
		: parent(other.parent),
		  left(other.left),
		  right(other.right),
		  color(other.color),
		  data(other.data) {}

		~rbnode() {}

		// member functions
		inline value_type& getData() { return this->data; }

		inline bool isBlack() { return this->color == rbnode::BLACK; }
		inline bool isRed() { return this->color == rbnode::RED; }
		inline color_type getColor() { return this->color; }

		inline void setBlack() { this->color = rbnode::BLACK; return; }
		inline void setRed() { this->color = rbnode::RED; return; }
		/*inline void swapColor(rbnode& other) {
			rbnode::e_color aux = this->color;
			this->color = other.color;
			other.color = aux;
		}*/

		inline bool isLeft() {
			assert(this->parent->left == this);
			return this->parent->left == this;
		}
		inline bool isRight() {
			assert(this->parent->right == this);
			return this->parent->right == this;
		}

		/*inline void swapSide() {
			assert(this->parent->children[rbnode::e_side::LEFT] == this
					|| this->parent->children[rbnode::e_side::RIGHT] == this);
			rbnode* aux = this->parent[rbnode::e_side::LEFT];
			this->parent[rbnode::e_side::LEFT] = this->parent[rbnode::e_side::RIGHT];
			this->parent[rbnode::e_side::RIGHT] = aux;
		}*/

		inline rbnode* getBrother() {
			if (this->parent == ft::nullptr_t) return ft::nullptr_t;

			assert(this->parent->left == this
					|| this->parent->right == this);
			return (this->parent->left == this
					? this->parent->left
					: this->parent->right);
		}
		inline rbnode* getGrandParent() {
			assert(this->parent && this->parent->parent);
			return(this->parent->parent);
		}
		inline rbnode* getUncle() {
			assert(this->parent);
			if (this->parent && this->parent->isLeft()) {
				return this->getGrandParent()->right;
			}
			if (this->parent && this->parent->isRight()) {
				return this->getGrandParent()->left;
			}
			return (ft::nullptr_t);
		}

		inline void setParent() {}
		inline void setLeft() {}
		inline void setRight() {}
	};

	//template<class T, class Compare, class Allocator>
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

			typedef ft::rbnode<value_type>									node_type;
			typedef typename Allocator::template rebind<node_type>::other	node_allocator;
			typedef typename node_allocator::pointer						pointer;
			typedef typename node_allocator::const_pointer					const_pointer;
			typedef typename node_allocator::reference						reference;
			typedef typename node_allocator::const_reference				const_reference;

			typedef ft::rbiterator<pointer, T>								iterator;
			typedef ft::rbiterator<const_pointer, const T>					const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

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

				this->node_nil->setBlack();
				this->node_nil->parent = this->node_nil;

				this->node_root = this->node_nil;

				//this->node_nil->left = this->node_nil;
				this->node_nil->left = this->node_root;
				//this->node_nil->right = this->node_nil;
				this->node_nil->right = this->node_root;

				this->node_root->parent = this->node_nil;
			}
			rbtree(const compare& lcomp, const allocator_type& lalloc)
			: size(0), comp(lcomp), alloc(lalloc) {
				this->node_nil = this->node_alloc.allocate(1);
				this->node_alloc.construct(this->node_nil, value_type());

				this->node_nil->setBlack();
				this->node_nil->parent = this->node_nil;

				this->node_root = this->node_nil;

				//this->node_nil->left = this->node_nil;
				this->node_nil->left = this->node_root;
				//this->node_nil->right = this->node_nil;
				this->node_nil->right = this->node_root;

				this->node_root->parent = this->node_nil;
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

			// insert
			ft::pair<iterator, bool> insert(const value_type& content) {
				if (this->node_root == this->node_nil) {
					this->node_root = nodeCreate(content, this->node_nil);
					++this->size;
					this->node_root->parent = this->node_nil;
					this->node_nil->left = this->node_root;
					this->node_nil->right = this->node_root;
					return ft::make_pair(iterator(this->node_root, this->node_root, this->node_nil), true);
				}
				pointer it = this->node_root;
				while (it != this->node_nil) {
					if (this->comp(it->data, content)) {
						if (it->right == this->node_nil) break;
						it = it->right;
					} else if (this->comp(content, it->data)) {
						if (it->left == this->node_nil) break;
						it = it->left;
					} else {
						this->node_root->parent = this->node_nil;
						this->node_nil->left = this->node_root;
						this->node_nil->right = this->node_root;

						return ft::make_pair(iterator(it, this->node_root, this->node_nil), false);
					}
				}
				if (this->comp(it->data, content)) {
					it->right = nodeCreate(content, it);
					it = it->right;
				} else if (this->comp(content, it->data)) {
					it->left = nodeCreate(content, it);
					it = it->left;
				}
				// nearby nodes
				this->insertFix(it);
				++this->size;
				this->node_root->parent = this->node_nil;
				this->node_nil->left = this->node_root;
				this->node_nil->right = this->node_root;

				return ft::make_pair(iterator(it, this->node_root, this->node_nil), true);
			}
			void insertFix(pointer node) {
				if (node != this->node_root && node->isRed() && node->parent->isRed()) {
					if (node->getUncle() && node->getUncle()->isRed()) {
						// color
						node->getUncle()->setBlack();
						node->parent->setBlack();
						node->getGrandParent()->setRed();
						insertFix(node->getGrandParent());
					} else if (node->parent != this->node_root && node->parent->isLeft()) {
						// left
						if (node->isRight()) {
							this->rotateLeft(node->parent);
							this->rotateRight(node->getGrandParent()); // ???
							this->insertFix(node->getGrandParent()); // ???
						} else {
							this->rotateRight(node->getGrandParent());
							this->swapColor(node->parent, node->getGrandParent());
							insertFix(node->parent);
						}
					} else if (node->parent != this->node_root && node->parent->isRight()) {
						// right
						if (node->isLeft()) {
							this->rotateRight(node->parent);
							this->rotateLeft(node->getGrandParent()); // ???
							this->insertFix(node->getGrandParent()); // ???
						} else {
							this->rotateLeft(node->getGrandParent());
							this->swapColor(node->parent, node->getGrandParent());
							this->insertFix(node->parent);
						}
					}
				}
				this->node_root->setBlack();
				this->node_root->parent = this->node_nil;
				this->node_nil->left = this->node_root;
				this->node_nil->right = this->node_root;
			}

			void remove(const value_type& content) {
				nodeRemove(content);
				this->node_root->parent = this->node_nil;
				this->node_nil->left = this->node_root;
				this->node_nil->right = this->node_root;

			}

			void nodeRemove(const value_type& content) {
				pointer it = this->node_root;
				pointer save;
				while (it != this->node_nil
						&& (this->comp(it->data, content) || this->comp(content, it->data))) {
					if (this->comp(it->data, content)) {
						it = it->right;
					} else if (this->comp(content, it->data)) {
						it = it->left;
					}
				}
				if (it == this->node_nil) return;

				bool color = it->color;
				if (it->left == this->node_nil) {
					save = it->right;
					this->nodeReplace(it, it->right);
				} else if (it->right == this->node_nil) {
					save = it->left;
					this->nodeReplace(it, it->left);
				} else {
					pointer aux = it->right;
					while (aux->left != this->node_nil) {
						aux = aux->left;
					}
					color = aux->color;
					save = aux->right;
					if (aux->parent == it) {
						aux->right->parent = aux;
					} else {
						this->nodeReplace(aux, aux->right);
						aux->right = it->right;
						aux->right->parent = aux;
					}
					this->nodeReplace(it, aux);
					aux->left = it->left;
					aux->left->parent = aux;
					aux->color = it->color;
				}
				--this->size;
				this->node_alloc.destroy(it);
				this->node_alloc.deallocate(it, 1);
				//if (color == node_type::e_color::BLACK) removeFix(save);
				if (color == node_type::BLACK) {
					pointer aux;
					while (save->parent != this->node_nil && save->isBlack()) {
						if (save->isLeft()) {
							aux = save->parent->right;
							if (aux->isRed()) {
								aux->setBlack();
								save->parent->setRed();
								this->rotateLeft(save->parent);
								aux = save->parent->right;
							}

							if (aux->right->isBlack() && aux->left->isBlack()) {
								aux->setRed();
								save = save->parent;
							} else {
								if (aux->right->isBlack()) {
									aux->left->setBlack();
									aux->setRed();
									this->rotateRight(aux);
									aux = save->parent->right;
								}
								aux->color = save->parent->color;
								save->parent->setBlack();
								aux->right->setBlack();
								this->rotateLeft(save->parent);
								save = this->node_root;
							}
						} else {
							aux = save->parent->left;
							if (aux->isRed()) {
								aux->setBlack();
								save->parent->setRed();
								this->rotateRight(save->parent);
								aux = save->parent->left;
							}

							if (aux->right->isBlack() && aux->left->isBlack()) {
								aux->setRed();
								save = save->parent;
							} else {
								if (aux->left->isBlack()) {
									aux->right->setBlack();
									aux->setRed();
									this->rotateLeft(aux);
									aux = save->parent->left;
								}
								aux->color = save->parent->color;
								save->parent->setBlack();
								aux->left->setBlack();
								this->rotateRight(save->parent);
								save = this->node_root;
							}
						}
					}
					save->setBlack();
				}
			}
			void nodeReplace(pointer oldNode, pointer newNode) {
				if (oldNode->parent == this->node_nil) this->node_root = newNode;
				else if (oldNode->isLeft()) oldNode->parent->left = newNode;
				else oldNode->parent->right = newNode;
				newNode->parent = oldNode->parent;
			}

			bool empty() const { return this->size == 0; }

			void swap(rbtree& other) {
				ft::swap(this->node_root, other.node_root);
				ft::swap(this->node_nil, other.node_nil);
				ft::swap(this->size, other.size);
				ft::swap(this->node_alloc, other.node_alloc);
				ft::swap(this->comp, other.comp);
			}

			pointer min() const {
				pointer it = this->node_root;
				if (it == this->node_nil) return it;
				while (it->left != this->node_nil) it = it->left;
				return it;
			}
			pointer max() const {
				pointer it = this->node_root;
				if (it == this->node_nil) return it;
				while (it->right != this->node_nil) it = it->right;
				return it;
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
					this->node_alloc.destroy(x);
					this->node_alloc.deallocate(x, 1);
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
			inline void swapColor(pointer n1, pointer n2) {
				typename node_type::color_type aux = n1->color;
				n1->color = n2->color;
				n2->color = aux;
			}
			//TODO replace ???

			// iterator
			iterator		begin() { return iterator(this->min(), this->node_root, this->node_nil); }
			iterator		end() { return iterator(this->node_nil, this->node_root, this->node_nil); }
			const_iterator	begin() const { return const_iterator(this->min(), this->node_root, this->node_nil); }
			const_iterator	end() const { return const_iterator(this->node_nil, this->node_root, this->node_nil); }

			reverse_iterator		rbegin() { return reverse_iterator(end()); }
			reverse_iterator		rend() { return reverse_iterator(begin()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

			//TODO debug (print all tree)

		private:
			// i mean, no, i don't need this and i don't wanna implement it
			rbtree& operator=(const rbtree& other) {
				(void)other;
			}
	};
}

#endif
