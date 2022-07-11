/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:34:54 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/12 01:29:35 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP_
# define EQUAL_HPP_

namespace ft {
	template< typename InputIterator1, typename InputIterator2 >
	bool
	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while(first1 != last1) {
			if (*first1 != *first2) {
				return false;
			}
			++first1;
			++first2;
		}
		return true;
	}
}

#endif
