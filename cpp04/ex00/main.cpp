#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include "./include/WrongAnimal.hpp"
#include "./include/WrongCat.hpp"


int main()
{

  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << i->getType() << " " << std::endl;
  std::cout << j->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();

  std::cout << "-------------------[Wrong part]----------------------" << std::endl;
  const WrongAnimal* meta2 = new WrongAnimal();
  const WrongCat* k = new WrongCat();
  std::cout << k->getType() << " " << std::endl;
  k->makeSound();
  meta2->makeSound();
  delete meta;
  delete j;
  delete i;
  delete meta2;
  delete k;
  return 0;
}