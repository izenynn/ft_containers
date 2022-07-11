/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:33:37 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/12 01:45:13 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP_
# define LEXICOGRAPHICAL_COMPARE_HPP_

namespace ft {
	template<typename InputIterator1, typename InputIterator2>
	bool
	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1) return false;
			if (*first1 < *first2) return true;
			++first1;
			++first2;
		}
		return first2 != last2;
	}
}

#endif
