#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
  	protected:
  	std::string _type;
  
	public:
	//constructeur
	AMateria(void);//default
 	AMateria(std::string const &type);//personalise

	AMateria(const AMateria &copy);//copy
	AMateria &operator=(const AMateria &other);//surcharge =
	virtual ~AMateria(void);//dest

	std::string const &getType() const; //Returns the materia type
	virtual AMateria *clone() const = 0; //  a voir plus tard
	virtual void use(ICharacter &target); 


};

#endif