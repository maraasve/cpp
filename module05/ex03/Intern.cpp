#include <Intern.hpp>

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
   std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& src) {
    std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Intern& Intern::operator=(const Intern& src) {
    std::cout << "Copy assignemt operator called" << std::endl;
}
