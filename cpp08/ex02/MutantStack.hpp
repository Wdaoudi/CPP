#pragma once

#include <algorithm>
#include <climits>
#include <deque>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    private:
    
    public :
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    
    MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack& operator=(const MutantStack &other);
    ~MutantStack();
    
    
    iterator begin();
    iterator end();
    const_iterator begin()const;
    const_iterator end()const;
   
};

#include "MutantStack.tpp"