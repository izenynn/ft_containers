/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:59:08 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/11 13:09:58 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP_
# define IS_INTEGRAL_HPP_

/* integral_constant */
namespace ft {
	template< class T, T val>
	struct integral_constant {
		static const T value = val;
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;
}

/* is_integral */
namespace ft {
	template< class T > struct is_integral : public ft::false_type {};
	template< class T > struct is_integral<const T> : public is_integral<T> {};
	template< class T > struct is_integral<volatile T> : public is_integral<T> {};
	template< class T > struct is_integral<const volatile T> : public is_integral<T> {};

	template<> struct is_integral<unsigned char> : public ft::true_type {};
	template<> struct is_integral<unsigned short> : public ft::true_type {};
	template<> struct is_integral<unsigned int> : public ft::true_type {};
	template<> struct is_integral<unsigned long> : public ft::true_type {};
	//template<> struct is_integral<unsigned long long> : public ft::true_type {};

	template<> struct is_integral<signed char> : public ft::true_type {};
	template<> struct is_integral<short> : public ft::true_type {};
	template<> struct is_integral<int> : public ft::true_type {};
	template<> struct is_integral<long> : public ft::true_type {};
	//template<> struct is_integral<long long> : public ft::true_type {};

	template<> struct is_integral<char> : public ft::true_type {};
	template<> struct is_integral<bool> : public ft::true_type {};
}

#endif
