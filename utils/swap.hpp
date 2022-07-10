/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:34:54 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/10 23:56:45 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP_
# define SWAP_HPP_

namespace ft {
	template< typename T >
	void
	swap(T& lhs, T& rhs) {
		T aux;
		aux = lhs;
		lhs = rhs;
		rhs = aux;
	}
};

#endif
