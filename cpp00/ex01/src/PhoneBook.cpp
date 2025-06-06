/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:57:04 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/18 18:59:52 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "constructor for phonebook called" << std::endl;
	this->countCont = 0;
	this->one_turn = false;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "destructor for phonebook called" << std::endl;
}

void PhoneBook::StartPrompting()
{
	int	error;
	bool is_empty = true;

	std::string input;
	error = 0;
	while (std::cin)
	{
		if (std::cin)
		std::cout << "Please enter your command:" << std::endl;
		std::cout << "1.ADD" << std::endl;
		std::cout << "2.SEARCH" << std::endl;
		std::cout << "3.EXIT" << std::endl;
		std::cin >> input;
		if (input == "ADD" || input == "1")
		{
			std::cout << "ADD en cours" << std::endl;
			this->addContact();
			is_empty = false;
		}
		else if (input == "SEARCH" || input == "2")
		{
			std::cout << "searching en cours" << std::endl;
			this->searchContact(is_empty);
		}
		else if (input == "EXIT" || input == "3")
		{

			std::cout << "Are you sure ? All of your contact will be erased" << std::endl;
			std::cout << "Press 1. to Exit"<< std::endl << "Press any letter or number to Continue"<< std::endl;
			std::cin >> input;
			if (input == "1")
			{
				std::cout << "Exiting ..."<< std::endl;
				break;
			}
			else
				continue;
		}
		else
		{
			if (error % 5 == 0)
				std::cout << "Command not recognized. Please try again." << std::endl;
			if (error % 5 == 1)
				std::cout << "Invalid input again? Please enter a correct command." << std::endl;
			if (error % 5 == 2)
				std::cout << "Seriously? How hard is it to type a valid command?" << std::endl;
			if (error % 5 == 3)
				std::cout << "Wow. You really have a talent for entering the WRONG commands." << std::endl;
			if (error % 5 == 4)
				std::cout << "That is it! I give up. You clearly have no idea what you're doing. Figure it out yourself!" << std::endl;
			error++;
		}
	}
}

void PhoneBook::addContact()
{
	// Contact contact
	// contact.[this->countCont];
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	if (this->countCont == 8) // remplacer par 8 pour les test
	{
		std::cout << "PhoneBook is full,the oldest contact will be erased and the new one will take is place" << std::endl;
		this->countCont = this->countCont % 8;
		this->one_turn = true;// verifier si il faut pas envoyer un pointeur 
	}
	std::cout << "please enter the first name of the new contact" << std::endl;
	std::cin >> first_name;
	this->contacts[this->countCont].setInfo(first_name, "FirstName");

	std::cout << "Please enter the last name of your new contact" << std::endl;
	std::cin >> last_name;
	this->contacts[this->countCont].setInfo(last_name, "LastName");
	
	std::cout << "please enter the nick name of your new contact" << std::endl;
	std::cin >> nick_name;
	this->contacts[this->countCont].setInfo(nick_name, "NickName");
	
	while (1)
	{
		
		std::cout << "please enter the phone number of your new contact" << std::endl;
		std::cin >> phone_number;
		if (this->contacts[this->countCont].setInfo(phone_number, "PhoneNumber") == true)
			break;
	}
	
	std::cout << "please enter the darkest secret of your new contact" << std::endl;
	std::cin >> darkest_secret;
	this->contacts[this->countCont].setInfo(darkest_secret, "DarkestSecret");
	
	this->countCont++;
}


void PhoneBook::searchContact(bool is_empty)
{
	if (is_empty == true)
	{
		std::cout << "Sorry, the PhoneBook is empty, please add a contact and try again"<< std::endl;
		return;
	}
	this->displayContact();

	
}

void PhoneBook:: displayContact()
{
	int a = 0;
	bool is_empty = false;
	std::string index;

	std::cout << "-------------------------------------------------" << std::endl;
	std:: cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|"
				<< std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	if (this->one_turn == true)
	{
		while(a <= 7) // 7 ou 8
		{
			std::cout << std::setw(10) << a+1 << "|"
			<< std::setw(10) << formatColumn(this->contacts[a].getInfo("FirstName")) << "|"
			<< std::setw(10) << formatColumn(this->contacts[a].getInfo("LastName")) << "|"
			<< std::setw(10) << formatColumn(this->contacts[a].getInfo("NickName")) << "|"
			<< std::endl;
			a++;
		}
	}
	else
	{
		while (a < this->countCont)
		{
			std::cout << std::setw(10) << a+1 << "|"
			<< std::setw(10) << formatColumn(this->contacts[a].getInfo("FirstName")) << "|"
			<< std::setw(10) << formatColumn(this->contacts[a].getInfo("LastName")) << "|"
			<< std::setw(10) << formatColumn(this->contacts[a].getInfo("NickName")) << "|"
			<< std::endl;
			a++;
		}
	}
	std:: cout << "Please select the index of the contact whose information you want to display."<< std::endl;
	while (is_empty == false)
	{
		
		std::cin >> index;
		if (std::cin.eof())
		{
			std::cout << "Error: Invalid index! Exiting..." << std::endl;
			is_empty = true;
			continue;
		}
	
		else
		{
			
			if (checkIndex(index) == true)
			{

			if(this->one_turn == true && stoi(index)-1 >= 0 && stoi(index)-1 <= 8)
			{
				std::cout << "First Name : "<< this->contacts[stoi(index)-1].getInfo("FirstName") << std::endl;
				std::cout << "Last Name : "<< this->contacts[stoi(index)-1].getInfo("LastName") << std::endl; 
				std::cout << "Nick Name : "<< this->contacts[stoi(index)-1].getInfo("NickName") << std::endl; 
				std::cout << "Phone Number : "<< this->contacts[stoi(index)-1].getInfo("PhoneNumber") << std::endl; 
				std::cout << "Darkest Secret : "<< this->contacts[stoi(index)-1].getInfo("DarkestSecret") << std::endl; 
				break;

			}
			else if (stoi(index)-1 >= 0 && stoi(index)-1 <= this->countCont && this->one_turn == false)
			{
				std::cout << "First Name : "<< this->contacts[stoi(index)-1].getInfo("FirstName") << std::endl;
				std::cout << "Last Name : "<< this->contacts[stoi(index)-1].getInfo("LastName") << std::endl; 
				std::cout << "Nick Name : "<< this->contacts[stoi(index)-1].getInfo("NickName") << std::endl; 
				std::cout << "Phone Number : "<< this->contacts[stoi(index)-1].getInfo("PhoneNumber") << std::endl; 
				std::cout << "Darkest Secret : "<< this->contacts[stoi(index)-1].getInfo("DarkestSecret") << std::endl; 
				break;
			}
			else
			{
				std::cout << "Error: Invalid index! Please enter a valid number." << std::endl;
				continue;
			}

			}
			else
			{
				std::cout << "Error: Invalid index! Please enter a valid number." << std::endl;
				continue;
			}
		}
	}
}

std::string PhoneBook::formatColumn(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}
bool PhoneBook::checkIndex(std::string index)
{
	for (size_t i  =0; i < index.length() ; i++)
	{
		if(!isdigit(index[i]))
			return (false);
	}
	return (true);
}