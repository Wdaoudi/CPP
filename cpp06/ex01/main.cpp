#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
    // Create a Data object with a value
    Data* originalData = new Data;
    originalData->value = 42;
    
    // Print the original pointer and data
    std::cout << "Original pointer address: " << originalData << std::endl;
    std::cout << "Original data value: " << originalData->value << std::endl;
    
    // Serialize the pointer
    std::cout << "\nSerializing pointer..." << std::endl;
    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;
    
    // Deserialize back to a pointer
    std::cout << "\nDeserializing back to pointer..." << std::endl;
    Data* deserializedData = Serializer::deserialize(serialized);
    
    // Print the deserialized pointer and data
    std::cout << "Deserialized pointer address: " << deserializedData << std::endl;
    std::cout << "Deserialized data value: " << deserializedData->value << std::endl;
    
    // Compare pointers
    std::cout << "\nComparing original and deserialized pointers:" << std::endl;
    if (originalData == deserializedData)
        std::cout << "SUCCESS! Pointers are identical." << std::endl;
    else
        std::cout << "FAILURE! Pointers are different." << std::endl;
    
    // Compare data values
    std::cout << "\nComparing original and deserialized values:" << std::endl;
    if (originalData->value == deserializedData->value)
        std::cout << "SUCCESS! Values are identical." << std::endl;
    else
        std::cout << "FAILURE! Values are different." << std::endl;
    
    // Clean up memory
    delete originalData;
    
    return 0;
}