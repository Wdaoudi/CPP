#pragma once 

#include <algorithm>
#include <climits>
#include <deque>
#include <exception>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <ctime>
#include <limits.h>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::deque<int> _deque;
        std::vector<int> _vector;
    public :
        PmergeMe();
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        
        bool validateArgs(int ac, char **av);
        std::vector<int> vector_Sort(std::vector<int> &tab);
        std::deque<int> deque_Sort(std::deque<int> &tab);


        std::vector<long long> jacobsthal_vec(int n);
        std::deque<long long> jacobsthal_deq(int n);

        void sortNumbers();
};