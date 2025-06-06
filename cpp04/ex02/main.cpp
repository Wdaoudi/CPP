#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include "./include/Brain.hpp"

int main()
{
    std::cout << "---------- Testing abstract Animal class ----------" << std::endl;
    {
        // This should cause a compile error:
        // Animal abstractAnimal; // Cannot instantiate abstract class
        
        // But pointers to abstract classes are allowed
        Animal *animal;
        
        // Creating concrete instances through polymorphism
        animal = new Dog();
        std::cout << "Type: " << animal->getType() << std::endl;
        animal->makeSound();
        delete animal;
        
        animal = new Cat();
        std::cout << "Type: " << animal->getType() << std::endl;
        animal->makeSound();
        delete animal;
    }
    
    std::cout << "\n---------- Testing array of Animals ----------" << std::endl;
    {
        const int numAnimals = 4;
        Animal *animals[numAnimals];
        
        // Create array with half Dogs and half Cats
        for (int i = 0; i < numAnimals; i++) {
            if (i % 2 == 0) {
                std::cout << "Creating Dog " << i << std::endl;
                animals[i] = new Dog();
            } else {
                std::cout << "Creating Cat " << i << std::endl;
                animals[i] = new Cat();
            }
        }
        
        // Test sounds from all animals
        for (int i = 0; i < numAnimals; i++) {
            std::cout << "Animal " << i << " of type " << animals[i]->getType() << " says: ";
            animals[i]->makeSound();
        }
        
        // Proper cleanup
        for (int i = 0; i < numAnimals; i++) {
            delete animals[i];
        }
    }
    
    std::cout << "\n---------- Testing deep copies ----------" << std::endl;
    {
        // Test Dog deep copy
        Dog* originalDog = new Dog();
        Dog* copyDog = new Dog(*originalDog);
        
        // Verify both make sounds
        std::cout << "Original Dog: ";
        originalDog->makeSound();
        std::cout << "Copy Dog: ";
        copyDog->makeSound();
        
        // Delete original, copy should still work
        delete originalDog;
        std::cout << "After deleting original, copy still works:" << std::endl;
        copyDog->makeSound();
        delete copyDog;
        
        // Same test with Cat
        Cat* originalCat = new Cat();
        Cat* copyCat = new Cat(*originalCat);
        
        delete originalCat;
        std::cout << "After deleting original cat, copy still works:" << std::endl;
        copyCat->makeSound();
        delete copyCat;
    }
    
    return 0;
}