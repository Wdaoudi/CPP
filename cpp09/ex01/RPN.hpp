#pragma once 

#include <algorithm>
#include <climits>
#include <deque>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <limits>

class RPN
{
    private:
        std::stack<int> _stack;

    public:
        RPN();
        RPN(const std::string &string);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void fileStack(const std::string &string);
        bool handle_operator(char i);

};