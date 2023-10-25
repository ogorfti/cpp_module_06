/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:29:30 by ogorfti           #+#    #+#             */
/*   Updated: 2023/10/25 17:03:19 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data ptr;
    ptr.a = 13;
    
    uintptr_t t = Serializer::serialize(&ptr);
    
    Data *ptr2 = Serializer::deserialize(t);
    if (ptr2->a == ptr2->a)
        std::cout << ptr2->a << '\n';
    else
        std::cout << "Serialization Failed" << '\n';
}