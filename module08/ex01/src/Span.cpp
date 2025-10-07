#include <Span.hpp>
#include <colors.hpp>

Span::Span(unsigned int N) : _N(N) {
    std::cout << GREEN << "Span constructor called" << RESET << std::endl;
}

Span::~Span() {
   std::cout << RED << "Span destructor called" << RESET << std::endl;
}

Span::Span(const Span& src) {
    std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Span& Span::operator=(const Span& src) {
    if (this != &src) {
        _N = src._N;
        _vec = src._vec;
    }
    std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
    return *this;
}

void Span::addNumber(int number) {
    if (_vec.size() >= _N) {
        throw std::overflow_error("Vector is full");
    }
    _vec.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) + _vec.size() > _N) {
        throw std::overflow_error("Adding these numbers would exceed the maximum size");
    }
    for (auto it = begin; it != end; ++it) {
        _vec.push_back(*it);
    }
}

long int Span::shortestSpan() const {
    if (_vec.size() <= 1) {
        throw NoSpan();
    }
    std::vector<int> sortedVec = _vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    long int minSpan = LONG_MAX;
    for (size_t i = 1; i < sortedVec.size(); ++i) {
        long int span = static_cast<long int>(sortedVec[i]) - static_cast<long int>(sortedVec[i - 1]);
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

long int Span::longestSpan() const {
    if (_vec.size() <= 1) {
        throw NoSpan();
    }
    auto minMax = std::minmax_element(_vec.begin(), _vec.end());
    return static_cast<long int>(*minMax.second) - static_cast<long int>(*minMax.first);
}

const char* Span::NoSpan::what() const throw() {
    return "No span can be found";
}