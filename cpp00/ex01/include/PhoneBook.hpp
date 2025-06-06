#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include "./Contact.hpp"

        
class PhoneBook
{
                public:
                PhoneBook(void); // constructeur
                ~PhoneBook(void); // destructeur
                
                //methodes
                void StartPrompting();//recuperer les differents prompting

                void addContact();//ajout
                void displayContact();//afficher
                void searchContact(bool is_empty);//chercher
                void Exit(); //sortir proprement

                std::string formatColumn(std::string str);
                bool checkIndex(std::string index);

                
                private:
                Contact contacts[8];//tableau de 8 Contact va de 0 a 7
                int countCont; //permet de savoir combien de contact creee+
                bool one_turn;
};


#endif 