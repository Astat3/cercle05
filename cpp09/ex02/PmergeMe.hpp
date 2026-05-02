#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <algorithm>

namespace PmergeMe {

    size_t genAlgo(size_t n);

    template <typename PairContainer>
    void mergePairs(PairContainer& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        PairContainer L(n1);
        PairContainer R(n2);

        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].first <= R[j].first) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) { arr[k] = L[i]; i++; k++; }
        while (j < n2) { arr[k] = R[j]; j++; k++; }
    }

    template <typename PairContainer>
    void mergeSortPairs(PairContainer& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortPairs(arr, left, mid);
            mergeSortPairs(arr, mid + 1, right);
            mergePairs(arr, left, mid, right);
        }
    }

    template <typename Container, typename PairContainer>
    void fordJohnsonSort(Container& arr) {
        if (arr.size() < 2) return;

        PairContainer pairs;
        int straggler = -1;
        bool hasStraggler = false;

        if (arr.size() % 2 != 0) {
            straggler = arr.back();
            hasStraggler = true;
            arr.pop_back();
        }

        for (size_t i = 0; i < arr.size(); i += 2) {
            if (arr[i] > arr[i+1]) {
                pairs.push_back(std::make_pair(arr[i], arr[i+1]));
            } else {
                pairs.push_back(std::make_pair(arr[i+1], arr[i]));
            }
        }

        mergeSortPairs(pairs, 0, pairs.size() - 1);

        Container mainChain;
        Container pend;

        for (size_t i = 0; i < pairs.size(); ++i) {
            mainChain.push_back(pairs[i].first);
            pend.push_back(pairs[i].second);
        }

        if (!pend.empty()) {
            mainChain.insert(mainChain.begin(), pend[0]);
        }

        size_t insertedCount = 1;
        size_t jacobIdx = 3;

        while (insertedCount < pend.size()) {
            size_t jacobNumber = genAlgo(jacobIdx);
            size_t maxIdx = std::min(jacobNumber, pend.size());

            for (size_t i = maxIdx; i > insertedCount; --i) {
                int valueToInsert = pend[i - 1];
                typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
                mainChain.insert(pos, valueToInsert);   
            }
            insertedCount = maxIdx;
            jacobIdx++;
        }

        if (hasStraggler) {
            typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
            mainChain.insert(pos, straggler);
        }

        arr = mainChain;
    }

}

#endif
