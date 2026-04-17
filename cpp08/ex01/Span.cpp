#include "Span.hpp"
#include <limits>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}


Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int shortest = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        unsigned int diff = static_cast<unsigned int>(sortedNumbers[i]) - static_cast<unsigned int>(sortedNumbers[i - 1]);
        if (diff == 0) {
            return 0;
        }
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(maxVal) - static_cast<unsigned int>(minVal);
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is full, cannot add more numbers";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
    return "Not enough numbers to find a span";
}
