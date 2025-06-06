#pragma once

#include <iostream>
#include <exception>
#include <cstddef>
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h> 

template <typename T>
class Array
{
    private :
    T* _array;
    unsigned int _size;
    
    public :
    Array();//empty array
    Array(unsigned int n);//n element 
    Array(const Array<T> &other);//deep copy 
    Array<T> &operator=(const Array<T> &other);
    ~Array();
    
    T& operator[](unsigned int index); //verifier si je dois faire une version const
    unsigned int size() const; // 

    class OutOfRangeException : public std::exception
    {
        public: 
            virtual const char * what() const throw()
            {
                return ("Index is out of range");
            }
    };
    
};

#include "Array.tpp"
