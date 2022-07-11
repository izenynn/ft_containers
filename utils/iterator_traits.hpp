/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 00:22:59 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/12 00:54:37 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP_
# define ITERATOR_TRAITS_HPP_

# include <iterator>

namespace ft {
	template<class Iter>
	struct iterator_traits {
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::reference			reference;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*> {
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T&								reference;
		typedef T*								pointer;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*> {
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T&						reference;
		typedef const T*						pointer;
		typedef std::random_access_iterator_tag	iterator_category;
	};
}

#endif
