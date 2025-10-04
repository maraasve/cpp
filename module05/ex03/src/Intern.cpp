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
    (void)src;
    return *this;
}

AForm *Intern::pardonForm(const std::string &target) const {
    return new PresidentialPardonForm(target);
}

AForm *Intern::robotomyForm(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

AForm *Intern::shrubberyForm(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    std::string formNames[3] = {
        "presidential request",
        "robotomy request",
        "shrubbery request"
    };

    AForm* (Intern::*formCreators[3])(const std::string &target) const = {
        &Intern::pardonForm,
        &Intern::robotomyForm,
        &Intern::shrubberyForm
    };

    for (size_t i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Intern could not find the form: " << formName << std::endl;
    return nullptr;
}