/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:28:41 by ogorfti           #+#    #+#             */
/*   Updated: 2023/10/25 17:01:36 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

struct Data
{
	int a;
};

//* static function can call without needing to create an object
class Serializer
{
	private:
		Serializer();
	public:
		Serializer(Serializer& other);
		Serializer operator=(Serializer& other);
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
}; 