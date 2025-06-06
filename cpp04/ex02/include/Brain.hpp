#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{

    protected :

        std::string ideas[100];

    public :

        Brain(void);
        Brain(std::string type);
        Brain(const Brain &copy);
        Brain &operator=(const Brain &other);
        virtual ~Brain(void);

        void SetIdeas(std::string& ideas, int index);
        std::string GetIdeas(int index) const;        

};


#endif