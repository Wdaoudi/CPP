#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}
PmergeMe::PmergeMe(int ac,char **av)
{
    // (void) str;
    std::cout << "Before: ";
    for (int i = 1; i < ac; i++)
    {
        int value = atoi(av[i]);
        std::cout << value << " ";
        _vector.push_back(value);
        _deque.push_back(value);
    }
    std::cout << std::endl;    
}

PmergeMe::PmergeMe(const PmergeMe &other):_deque(other._deque),_vector(other._vector)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if(this != &other)
    {
        _deque = other._deque;
        _vector =other._vector;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{}

std::vector<long long> PmergeMe::jacobsthal_vec(int n)
{
    std::vector<long long> jacobsthal(n + 1);
    jacobsthal[0] = 0;
    if (n > 0) jacobsthal[1] = 1;
    
    for (int i = 2; i <= n; ++i)
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
    
    return jacobsthal;
}

std::deque<long long> PmergeMe::jacobsthal_deq(int n)
{
    std::deque<long long> jacobsthal(n + 1);
    jacobsthal[0] = 0;
    if (n > 0) jacobsthal[1] = 1;
    
    for (int i = 2; i <= n; ++i)
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
    
    return jacobsthal;
}

std::vector<int> PmergeMe::vector_Sort(std::vector<int> &tab)
{
    // Cas de base
    if (tab.size() <= 1)
        return tab;
    
    // Création des groupes de paires
    std::vector<int> mini;
    std::vector<int> maxi;
    
    for (size_t i = 0; i < tab.size(); i += 2)
    {
        if (i + 1 >= tab.size())
        {
            // std::cout << "elemnt unique vers mini: "<< tab[i] << std::endl;
            // Élément unique restant
            mini.push_back(tab[i]);
        }
        else
        {
            // Paire d'éléments
            if (tab[i] > tab[i+1])
            {
                // std::cout << "paire d element vers maxi:"<< tab[i] << std::endl;
                // std::cout << "paire d element vers mini:"<< tab[i+1] << std::endl;
                maxi.push_back(tab[i]);
                mini.push_back(tab[i+1]);
                
            }
            else
            {
                // std::cout << "paire d element vers maxi:"<< tab[i+1] << std::endl;
                // std::cout << "paire d element vers mini:"<< tab[i] << std::endl;
                maxi.push_back(tab[i+1]);
                mini.push_back(tab[i]);
            }
        }
    }
    
    // Cas spécial pour une paire unique
    if (mini.size() == 1 && !maxi.empty())
    {
        mini.push_back(maxi[0]);
        tab = mini;
        return mini;
    }
    
    // Récursion pour trier les maximums
    maxi = vector_Sort(maxi);
    
    // Insertion des minimums dans la séquence triée
    std::vector<int>::iterator insert_pos;
    long long lastIndex = -1;
    std::vector<long long> jacobsthal = jacobsthal_vec(50);
    
    // Insertion basée sur les nombres de Jacobsthal
    for (int i = 2; i < 50; i++)
    {
        long long currentIndex = jacobsthal[i];
        if (currentIndex >= (long long)mini.size())
        {
            if (lastIndex >= (long long)mini.size() - 1)
             break;
            currentIndex = mini.size() - 1;
    }
    
    for (long long j = currentIndex; j > lastIndex; j--)
    {
        if (j < (long long)mini.size())
        {
            insert_pos = std::lower_bound(maxi.begin(), maxi.end(), mini[j]);
            maxi.insert(insert_pos, mini[j]);
        }
    }
    
    lastIndex = currentIndex;
}
    tab = maxi;
    return maxi;
}

std::deque<int> PmergeMe::deque_Sort(std::deque<int> &tab)
{
    // Cas de base
    if (tab.size() <= 1)
        return tab;
    
    // Création des groupes de paires
    std::deque<int> mini;
    std::deque<int> maxi;
    
    for (size_t i = 0; i < tab.size(); i += 2)
    {
        if (i + 1 >= tab.size())
        {
            // std::cout << "elemnt unique vers mini: "<< tab[i] << std::endl;
            // Élément unique restant
            mini.push_back(tab[i]);
        }
        else
        {
            // Paire d'éléments
            if (tab[i] > tab[i+1])
            {
                // std::cout << "paire d element vers maxi:"<< tab[i] << std::endl;
                // std::cout << "paire d element vers mini:"<< tab[i+1] << std::endl;
                maxi.push_back(tab[i]);
                mini.push_back(tab[i+1]);
                
            }
            else
            {
                // std::cout << "paire d element vers maxi:"<< tab[i+1] << std::endl;
                // std::cout << "paire d element vers mini:"<< tab[i] << std::endl;
                maxi.push_back(tab[i+1]);
                mini.push_back(tab[i]);
            }
        }
    }
    
    // Cas spécial pour une paire unique
    if (mini.size() == 1 && !maxi.empty())
    {
        mini.push_back(maxi[0]);
        tab = mini;
        return mini;
    }
    
    // Récursion pour trier les maximums
    maxi = deque_Sort(maxi);
    
    // Insertion des minimums dans la séquence triée
    std::deque<int>::iterator insert_pos;
    long long lastIndex = -1;
    std::deque<long long> jacobsthal = jacobsthal_deq(50);
    
    // Insertion basée sur les nombres de Jacobsthal
    for (int i = 2; i < 50; i++)
    {
        long long currentIndex = jacobsthal[i];
        if (currentIndex >= (long long)mini.size())
        {
            if (lastIndex >= (long long)mini.size() - 1)
             break;
            currentIndex = mini.size() - 1;
    }
    
    for (long long j = currentIndex; j > lastIndex; j--)
    {
        if (j < (long long)mini.size())
        {
            insert_pos = std::lower_bound(maxi.begin(), maxi.end(), mini[j]);
            maxi.insert(insert_pos, mini[j]);
        }
    }
    
    lastIndex = currentIndex;
}
    tab = maxi;
    return maxi;
}


void PmergeMe::sortNumbers()
{
    // Variables pour la mesure du temps
    struct timeval start_vec, end_vec, start_deq, end_deq;
    (void)start_deq;
    (void)end_deq;
    // Tri avec vector et mesure du temps
    gettimeofday(&start_vec, NULL);
    vector_Sort(_vector);
    gettimeofday(&end_vec, NULL);
    
    // Tri avec list et mesure du temps
    gettimeofday(&start_deq, NULL);
    deque_Sort(_deque);
    gettimeofday(&end_deq, NULL);
    
    // Affichage de la séquence après tri
    std::cout << "After: ";
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Calcul des temps d'exécution en microsecondes
    long vec_time = (end_vec.tv_sec - start_vec.tv_sec) * 1000000 + (end_vec.tv_usec - start_vec.tv_usec);
    long deq_time = (end_deq.tv_sec - start_deq.tv_sec) * 1000000 + (end_deq.tv_usec - start_deq.tv_usec);
    // conversion des seconde et ajout des usec

    // Affichage des temps d'exécution
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << vec_time << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " 
              << std::fixed << std::setprecision(5) << deq_time << " us" << std::endl;
}

// Validation des arguments
bool PmergeMe::validateArgs(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: not enough arguments" << std::endl;
        return false;
    }
    
    for (int i = 1; i < ac; i++)
    {
        // Vérification que l'argument est un nombre positif
        char *endptr;
        long value = strtol(av[i], &endptr, 10);
        
        if (*endptr != '\0' || value < 0 || value > INT_MAX)
        {
            std::cerr << "Error: invalid argument '" << av[i] << "'" << std::endl;
            return false;
        }
    }
    
    return true;
}