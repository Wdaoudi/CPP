#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

//prototype
Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int	main(void)
{
	Base	*base = generate();
	std::cout << "Identifying using pointer: ";
	identify(base);
	std::cout << "Identifying using reference: ";
	identify(*base);
	delete	base;
	std::cout << std::endl;
	return (0);
}

/*
dynamic cast : 
conversion securise, pointeur et ref vers classe de base vers une enfant
speciale polymorphisme et heritage

static_cast : effectue la conversion à la compilation et n'effectue pas de vérification de type à l'exécution
reinterpret_cast : effectue une conversion bit à bit sans vérification
const_cast : permet de modifier la qualificateur const d'une variable
*/