/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:11:43 by ogorfti           #+#    #+#             */
/*   Updated: 2023/10/26 10:37:47 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base(){}

Base* Base::generate(void)
{
	Base *pb = NULL;

	std::srand(std::time(0));
	if (std::rand() % 3 == 0)
	{
		A* da = new A;
		pb = dynamic_cast <Base* > (da);	
	}
	else if (std::rand() % 3 == 1)
	{
		C* dc = new C;
		pb = dynamic_cast <Base* > (dc);
	}
	else
	{
		B* db = new B;
		pb = dynamic_cast <Base* > (db);
	}
	return (pb);
}

void Base::identify(Base* p)
{
	A *da = dynamic_cast <A*> (p);
	B *db = dynamic_cast <B*> (p);
	C *dc = dynamic_cast <C*> (p);
	if (da)
		std::cout << "A" << '\n';
	else if (db)
		std::cout << "B" << '\n';
	else if (dc)
		std::cout << "C" << '\n';
}

void  Base::identify(Base& p)
{
	try
	{
		A& da = dynamic_cast <A&> (p);
		std::cout << "A" << '\n';
		(void)da;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& db = dynamic_cast <B&> (p);
			std::cout << "B" << '\n';
			(void)db;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& dc = dynamic_cast <C&> (p);
				std::cout << "C" << '\n';
				(void)dc;
			}
			catch(const std::exception& e){}
		}
	}
}
