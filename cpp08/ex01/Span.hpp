#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template <typename Iter>
    void addNumber(Iter begin, Iter end) {
        if (static_cast<unsigned long>(std::distance(begin, end)) > static_cast<unsigned long>(_maxSize - _numbers.size())) {
            throw SpanFullException();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NotEnoughNumbersException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
