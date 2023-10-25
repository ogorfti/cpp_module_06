/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:37:47 by ogorfti           #+#    #+#             */
/*   Updated: 2023/10/25 13:18:25 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*-------------------- Orthodox --------------------*/

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter &other){ (void) other; }

ScalarConverter ScalarConverter::operator=(ScalarConverter &other)
{
	(void) other;
	return(*this);
}

ScalarConverter::~ScalarConverter(){}

/*-------------------- Member functions --------------------*/

int	isFloat(std::string s)
{
	int dig = 0;
	int point = 0;
	int suf = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		char ch(s[i]);
		if (std::isdigit(ch))
			dig = 1;
		else if (ch  == '.')
		{
			if (point || suf)
				return (0);
			point = 1;
		}
		else if (ch == 'f')
		{
			if (suf || !dig || !point)
				return (0);
			suf = 1;
		}
		else if (!(i == 0 && (s[i] == '+' || s[i] == '-')))
			return (0);
	}
	return (1);
}

void castChar(std::string s)
{
	std::cout << "char: ";
	if (s.size() == 1)
	{
		char c(s[0]);
		if (c >= '0' && c <= '9')
				std::cout << "Non displayable" << '\n';
		else
			std::cout << static_cast<char> (c) << '\n';	
	}
	else if (isFloat(s))
	{
		int as = std::atoi(s.c_str());
		if (std::isprint(as))
			std::cout << '\'' << static_cast<char> (as) << '\'' << '\n';	
		else
			std::cout << "impossible" << '\n';
			
	}
	else
		std::cout << "impossible" << '\n';
}

int getPrecision(std::string s)
{
	int i = s.size() - 1, count = 0;
	if (s[i] == 'f')
		i--;
	for (; i >= 0; i--)
	{
		if (s[i] != '0' || s[i] == '.')
			break ;
		count++;
	}
	if (s.find('.') != std::string::npos)
		return (i - s.find('.') > 0 ? i - s.find('.') : 1);
	return (1);
}

void castFloat(std::string s, std::string type, char suff)
{
	std::cout << type;
	if (isFloat(s) || !s.compare("nan"))
		std::cout << std::fixed << std::setprecision(getPrecision(s)) << static_cast<float> (std::strtod(s.c_str(), 0)) << suff <<'\n';
	else if (s.size() == 1 && std::isprint(s[0]))
		std::cout << std::fixed << std::setprecision(1) << static_cast<float> (char(s[0])) << suff << '\n';
	else
		std::cout << "impossible" << '\n';		
}

void castInt(std::string s)
{
	std::cout << "int: ";
	int check = 0;
	for (int i = 0; s[i]; i++)
	{
		if (!(s[i] >= '0' && s[i] <= '9' && s[i] == '-' && s[i] == '+'))
			check++;
	}
	if ((check > 1 && !isFloat(s)) || std::strtod(s.c_str(), 0) > INT_MAX || std::strtod(s.c_str(), 0) < INT_MIN)
		std::cout << "impossible" << '\n';
	else if (check == 1 && std::isprint(s[0] - '0'))
		std::cout << static_cast<int> (char(s[0])) << '\n';
	else
		std::cout << static_cast<int> (std::atoi(s.c_str())) << '\n';
}

void ScalarConverter::convert(std::string s)
{
	castChar(s);
	castInt(s);
	castFloat(s, "float: ", 'f');
	castFloat(s, "double: ", '\0');
}
