#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    {
        std::cout << "--- MutantStack Test ---" << std::endl;
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << "Top element: " << mstack.top() << std::endl;
        
        mstack.pop();
        
        std::cout << "Stack size after pop: " << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        std::cout << "- Iterating through elements:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    
    {
        std::cout << "\n--- std::list Validation Test ---" << std::endl;
        std::list<int> lstack;
        
        lstack.push_back(5);
        lstack.push_back(17);
        
        std::cout << "Top element: " << lstack.back() << std::endl;
        
        lstack.pop_back();
        
        std::cout << "Stack size after pop: " << lstack.size() << std::endl;
        
        lstack.push_back(3);
        lstack.push_back(5);
        lstack.push_back(737);
        lstack.push_back(0);
        
        std::list<int>::iterator it = lstack.begin();
        std::list<int>::iterator ite = lstack.end();
        
        ++it;
        --it;
        std::cout << "- Iterating through elements:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    
    return 0;
}
