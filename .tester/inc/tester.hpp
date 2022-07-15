/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:51:37 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/07/15 20:53:32 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP_
# define TESTER_HPP_

# include <iostream>
# include <string>
# include <deque>

# ifndef FT //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
# else
	#include "../../map.hpp"
	#include "../../stack.hpp"
	#include "../../vector.hpp"
# endif

# include <stdlib.h>

#endif
