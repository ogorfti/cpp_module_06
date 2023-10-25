/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:28:43 by ogorfti           #+#    #+#             */
/*   Updated: 2023/10/25 17:03:28 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*-------------------- Orthodox --------------------*/

Serializer::Serializer(){}

Serializer::Serializer(Serializer &other){ (void) other; }

Serializer Serializer::operator=(Serializer &other)
{
	(void) other;
	return(*this);
}

Serializer::~Serializer(){}

/*-------------------- Member functions --------------------*/

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t> (ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data*> (raw));
}
