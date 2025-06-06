/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:57:24 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/18 14:23:37 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(void)
{
	std::cout << "constructor for contact called" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "destructor for Contact called" << std::endl;
	return ;
}

bool Contact::setInfo(const std::string &Info, std::string type)
{
	// std::cout << "test setter" << std::endl;
	if (type == "FirstName")
		this->first_name = Info;
	else if (type == "LastName")
		this->last_name = Info;
	else if (type == "NickName")
		this->nick_name = Info;
	else if (type == "PhoneNumber")
	{
		for (size_t i = 0; i < Info.length(); i++)
		{
			if (!isdigit(Info[i]))
			{
				std::cout << "Please enter only number please." << std::endl;
					return (false);
			}
			else
			{
					this->phone_number = Info;
					break;
			}	
		}
		
	}
	else if (type == "DarkestSecret")
		this->darkest_secret = Info;
	return (true);
}

std::string Contact::getInfo(std::string Info) const
{
	std::string str;

	if (Info == "FirstName")
		str = this->first_name;
	if (Info == "LastName")
		str = this->last_name;
	if (Info == "NickName")
		str = this->nick_name;
	if (Info == "PhoneNumber")
		str = this->phone_number;
	if (Info == "DarkestSecret")
		str = this->darkest_secret;
	
	return (str);
}
