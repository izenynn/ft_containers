/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbnode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:06:50 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/15 15:21:51 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP_
# define RBNODE_HPP_

# include "nullptr_t.hpp"

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
		rbnode*		left;
		rbnode*		right;
		rbnode*		parent;

		// node content
		value_type	data;
		bool		color;

		// constructors
		//node() : color(k_red) {}

		rbnode(const value_type& value)
		: left(ft::nullptr_t),
		  right(ft::nullptr_t),
		  parent(ft::nullptr_t),
		  data(value),
		  color(rbnode::BLACK) {}
		//rbnode(const value_type& value, rbnode* nil)
		//: left(nil),
		//  right(nil),
		//  parent(nil),
		//  data(value),
		//  color(rbnode::BLACK) {}

		//rbnode(const rbnode& other)
		//: left(other.left),
		//  right(other.right),
		//  parent(other.parent),
		//  data(other.data),
		//  color(other.color) {}

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
			return this->parent->left == this;
		}
		inline bool isRight() {
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
			return (this->parent->left == this
					? this->parent->left
					: this->parent->right);
		}
		inline rbnode* getGrandParent() {
			if (this->parent != ft::nullptr_t && this->parent->parent != ft::nullptr_t) {
				return(this->parent->parent);
			}
			return ft::nullptr_t;
		}
		inline rbnode* getUncle() {
			if (this->parent != ft::nullptr_t && this->parent->isLeft()) {
				return this->getGrandParent()->right;
			}
			if (this->parent != ft::nullptr_t && this->parent->isRight()) {
				return this->getGrandParent()->left;
			}
			return ft::nullptr_t;
		}
	};

}

#endif
