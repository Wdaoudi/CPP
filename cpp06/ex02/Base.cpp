#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

//prototype
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

Base::~Base()
{
}

Base	*generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int random = std::rand() % 3;

	switch (random)
	{
	case 0:
		std::cout << "Generated instance of class A" << std::endl;
		return new A();
        break;
	case 1:
		std::cout << "Generated instance of class B" << std::endl;
		return new B();
        break;
	case 2:
		std::cout << "Generated instance of class C" << std::endl;
		return new C();
        break;
	default:
		return (NULL);
	}
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception&){}
//continue so don t catch any error
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::exception&){}
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::exception&){}
    {
        std::cout << "Unknown type" << std::endl;
    }
}