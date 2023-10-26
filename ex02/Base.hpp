/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:10:41 by ogorfti           #+#    #+#             */
/*   Updated: 2023/10/26 11:55:24 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

//* If there is a surety we will never cast to wrong object
//* then always avoid dynamic_cast and use static_cast. 
class Base
{
	public:
		Base* generate(void);
		void identify(Base* p);
		void identify(Base& p);
		virtual ~Base();
};