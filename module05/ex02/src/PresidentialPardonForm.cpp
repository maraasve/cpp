#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm() {
   std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) {
    std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    std::cout << "Copy assignemt operator called" << std::endl;
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

const std::string PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::formAction() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}