#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include "./include/Brain.hpp"

int main()
{
    // Test 1: Création et suppression basiques comme dans le sujet
    {
        std::cout << "---------- Test 1: Création et suppression basiques ----------" << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        delete j;
        delete i;
    }
    
    // Test 2: Création et gestion d'un tableau d'animaux
    {
        std::cout << "\n---------- Test 2: Tableau d'Animals ----------" << std::endl;
        const int numAnimals = 10;
        Animal* animals[numAnimals];
        
        // Remplir le tableau avec moitié Dog, moitié Cat
        for (int i = 0; i < numAnimals; i++) {
            if (i < numAnimals/2) {
                std::cout << "Création Dog " << i << std::endl;
                animals[i] = new Dog();
            } else {
                std::cout << "Création Cat " << i << std::endl;
                animals[i] = new Cat();
            }
        }
        
        // Parcourir le tableau et supprimer les animaux
        for (int i = 0; i < numAnimals; i++) {
            std::cout << "Suppression animal " << i << std::endl;
            delete animals[i];
        }
    }
    
    // Test 3: Vérification de la copie profonde pour Dog
    {
        std::cout << "\n---------- Test 3: Copie profonde (Dog) ----------" << std::endl;
        
        // Création d'un Dog avec une idée spécifique
        Dog* originalDog = new Dog();
        std::string dogIdea = "Je veux manger un os";
        originalDog->SetIdeas(dogIdea, 0);
        
        // Création d'une copie
        Dog* copyDog = new Dog(*originalDog);
        
        // Vérification que c'est bien une copie profonde
        std::cout << "Avant modification:" << std::endl;
        std::cout << "Idée Dog original [0]: " << originalDog->GetIdeas(0) << std::endl;
        std::cout << "Idée Dog copie [0]: " << copyDog->GetIdeas(0) << std::endl;
        
        // Modification de l'idée dans l'original
        std::string newDogIdea = "Je préfère les croquettes finalement";
        originalDog->SetIdeas(newDogIdea, 0);
        
        // Si c'est une copie profonde, l'idée de la copie ne doit pas changer
        std::cout << "Après modification de l'original:" << std::endl;
        std::cout << "Idée Dog original [0]: " << originalDog->GetIdeas(0) << std::endl;
        std::cout << "Idée Dog copie [0]: " << copyDog->GetIdeas(0) << std::endl;
        
        // Nettoyage
        delete originalDog;
        delete copyDog;
    }
    
    // Test 4: Vérification de la copie profonde pour Cat
    {
        std::cout << "\n---------- Test 4: Copie profonde (Cat) ----------" << std::endl;
        
        // Création d'un Cat avec une idée spécifique
        Cat* originalCat = new Cat();
        std::string catIdea = "Je veux attraper une souris";
        originalCat->SetIdeas(catIdea, 0);
        
        // Création d'une copie avec l'opérateur d'affectation
        Cat* copyCat = new Cat();
        *copyCat = *originalCat;
        
        // Vérification que c'est bien une copie profonde
        std::cout << "Avant modification:" << std::endl;
        std::cout << "Idée Cat original [0]: " << originalCat->GetIdeas(0) << std::endl;
        std::cout << "Idée Cat copie [0]: " << copyCat->GetIdeas(0) << std::endl;
        
        // Modification de l'idée dans l'original
        std::string newCatIdea = "Je préfère dormir sur le canapé finalement";
        originalCat->SetIdeas(newCatIdea, 0);
        
        // Si c'est une copie profonde, l'idée de la copie ne doit pas changer
        std::cout << "Après modification de l'original:" << std::endl;
        std::cout << "Idée Cat original [0]: " << originalCat->GetIdeas(0) << std::endl;
        std::cout << "Idée Cat copie [0]: " << copyCat->GetIdeas(0) << std::endl;
        
        // Nettoyage
        delete originalCat;
        delete copyCat;
    }
    
    // Test 5: Vérification supplémentaire - destruction de l'original avant d'utiliser la copie
    {
        std::cout << "\n---------- Test 5: Validité après destruction de l'original ----------" << std::endl;
        
        Dog* originalDog = new Dog();
        std::string idea = "Idée originale";
        originalDog->SetIdeas(idea, 0);
        
        // Copie
        Dog* copyDog = new Dog(*originalDog);
        
        // Destruction de l'original
        delete originalDog;
        
        // La copie doit toujours être utilisable
        std::cout << "Après destruction de l'original, la copie contient toujours: " << copyDog->GetIdeas(0) << std::endl;
        copyDog->makeSound();
        
        delete copyDog;
    }
    
    return 0;
}