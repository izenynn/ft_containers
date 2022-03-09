/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr_t.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:03:18 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/03/09 09:07:34 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULLPTR_T_HPP_
# define NULLPTR_T_HPP_

namespace ft {
	const class nullptr_t {
		public:
			template<class T>
			operator T*() const {
				return 0;
			}
			template<class C, class T>
			operator T C::*() const {
				return 0;
			}
		private:
			void operator&() const;
	} nullptr_t = {};
}

#endif
