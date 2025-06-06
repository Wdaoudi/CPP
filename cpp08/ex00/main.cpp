#include "easyfind.hpp"

int main() {
    // Test with vector
    std::vector<int> vec;
    vec.push_back(50);
    vec.push_back(40);
    vec.push_back(10);
    vec.push_back(30);
    vec.push_back(20);

    // Test with list
    std::list<int> lst;
    lst.push_back(15);
    lst.push_back(35);
    lst.push_back(55);
    lst.push_back(25);
    lst.push_back(45);

    // Test with deque
    std::deque<int> deq;
    deq.push_back(25);
    deq.push_back(15);
    deq.push_back(35);
    deq.push_back(45);
    deq.push_back(5);

    const std::vector<int> vec2(vec);
    testEasyfind(vec2, 30, "vector2"); //gestion de la forme const


    // Test successful finds
    std::cout << "successful find" <<std::endl;
    testEasyfind(vec, 30, "vector");
    testEasyfind(lst, 35, "list");
    testEasyfind(deq, 25, "deque");

    // Test values not in containers
    std::cout << "unsuccessful find" <<std::endl;
    testEasyfind(vec, 100, "vector");
    testEasyfind(lst, 100, "list");
    testEasyfind(deq, 100, "deque");

    return 0;
}