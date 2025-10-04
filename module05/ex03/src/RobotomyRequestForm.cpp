#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
   std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) {
    std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
    std::cout << "Copy assignemt operator called" << std::endl;
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

const std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::formAction() const {
    std::cout << "(drilling noises) Bzzzz..." << std::endl;
    srand(time(NULL));
    int num = rand() % 100;
    
    if (num < 50) {
        std::cout << _target << " has been robotomized" << std::endl;
    }
    else {
        std::cout << "This robotomy has failed..." << std::endl;
    }
}