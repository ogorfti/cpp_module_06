/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:17:38 by ogorfti           #+#    #+#             */
/*   Updated: 2023/10/25 12:44:28 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip> 

//* Utility/Static classes are often used to group related helper functions,
//* math functions, conversion functions and don't contain any member variables
//* cuz its work with their input parameters, producing results based on those inputs.

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		ScalarConverter(ScalarConverter &other);
		ScalarConverter operator=(ScalarConverter &other);
		~ScalarConverter();
		static void convert(std::string s);
};
