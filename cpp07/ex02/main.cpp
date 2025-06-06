#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

int main() {
    try {
        // Testing default constructor
        Array<int> defaultArray;
        std::cout << "Size of default array: " << defaultArray.size() << std::endl;

        // Testing parameterized constructor
        Array<int> intArray(5);
        std::cout << "\nSize of intArray: " << intArray.size() << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 2;
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        // Testing copy constructor
        Array<int> copyArray(intArray);
        std::cout << "\nCopy of intArray (copyArray):" << std::endl;
        for (unsigned int i = 0; i < copyArray.size(); i++) {
            std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
        }

        // Modifying the original array to ensure copy independence
        std::cout << "\nBefore modifying intArray[0] to 100:" << std::endl;
        std::cout << "Array[0] = "<<intArray[0] << std::endl;
        intArray[0] = 100;
        std::cout << "After modifying intArray[0] to 100:" << std::endl;
        std::cout << "intArray[0] = " << intArray[0] << std::endl;
        std::cout << "copyArray[0] = " << copyArray[0] << " (should not change)" << std::endl;

        // Testing assignment operator
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "\nAssigned array (assignedArray):" << std::endl;
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
        }

        // Testing bounds checking
        std::cout << "\nAccessing out-of-bounds element:" << std::endl;
        std::cout << intArray[10] << std::endl;  // Should throw an exception

    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}