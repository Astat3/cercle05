#include "PmergeMe.hpp"

namespace PmergeMe {

    size_t genAlgo(size_t n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        long long prev2 = 0;
        long long prev1 = 1;
        long long current = 0;
        
        for (size_t i = 2; i <= n; i++) {
            current = prev1 + 2 * prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }

}
