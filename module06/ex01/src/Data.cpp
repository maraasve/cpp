#include <Data.hpp>

Data::Data(size_t num1, size_t num2) : _num1(num1), _num2(num2) {
    std::cout << "Data constructor called" << std::endl;
}

Data::~Data() {
   std::cout << "Data destructor called" << std::endl;
}

Data::Data(const Data& src) {
    std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Data& Data::operator=(const Data& src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src) {
        _num1 = src.getNum1();
        _num2 = src.getNum2();
    }
    return *this;
}

size_t Data::getNum1() const {
    return _num1;
}

size_t Data::getNum2() const {
    return _num2;
}
