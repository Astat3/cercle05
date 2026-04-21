#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>

long getTimeMicroseconds(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos) {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        long val = 0;
        char *endptr;
        val = std::strtol(arg.c_str(), &endptr, 10);
        
        if (*endptr != '\0' || val < 0 || val > INT_MAX) {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        vec.push_back(static_cast<int>(val));
        deq.push_back(static_cast<int>(val));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i + 1 < vec.size()) std::cout << " ";
        if (i == 4 && vec.size() > 5) {
            std::cout << " [...]";
            break;
        }
    }
    std::cout << std::endl;

    struct timeval start, end;

    // Vector sort
    gettimeofday(&start, NULL);
    PmergeMe::fordJohnsonSort< std::vector<int>, std::vector<std::pair<int, int> > >(vec);
    gettimeofday(&end, NULL);
    long time_vec = getTimeMicroseconds(start, end);

    // Deque sort
    gettimeofday(&start, NULL);
    PmergeMe::fordJohnsonSort< std::deque<int>, std::deque<std::pair<int, int> > >(deq);
    gettimeofday(&end, NULL);
    long time_deq = getTimeMicroseconds(start, end);

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i + 1 < vec.size()) std::cout << " ";
        if (i == 4 && vec.size() > 5) {
            std::cout << " [...]";
            break;
        }
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector " << " : " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque " << " : " << time_deq << " us" << std::endl;

    return 0;
}
