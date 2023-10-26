/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:00:02 by ogorfti           #+#    #+#             */
/*   Updated: 2023/10/26 10:36:25 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void test0()
{
	A a;
	B b;
	C c;

	Base* pa = &a;
	Base* pb = &b;
	Base* pc = &c;

	pa->identify(*pa);
	pb->identify(*pb);
	pc->identify(*pc);
}

void test1()
{
	Base *ptr = NULL;

	ptr = ptr->generate();
	ptr->identify(ptr);
	delete ptr;
}

int main()
{
	test0();
}
