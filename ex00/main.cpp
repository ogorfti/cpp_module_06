/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:31:25 by ogorfti           #+#    #+#             */
/*   Updated: 2023/10/25 12:41:29 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	std::string s;

	if (ac == 2)
	{
		s = av[1];
		ScalarConverter::convert(s);
	}
	else
		std::cout << "Error" << '\n';
	return 0;
}
