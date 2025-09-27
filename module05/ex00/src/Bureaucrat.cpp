#include "Bureaucrat.hpp"

// constructors
Bureaucrat::Bureaucrat(): _name("Anonymous"), _grade(150) {
	std::cout << "Default Bureaucrat " << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, size_t grade) : _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(size_t grade): _name("Anonymous") {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " created with grade " << _grade << std::endl;
}

// destructor
Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " with grade " << _grade << " destroyed" << std::endl;
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// assignment operator
Bureaucrat& Bureaucrat::operator = (const Bureaucrat& src) {
	std::cout << "Copy assignemt operator called" << std::endl;
	if (this != &src) {
		_grade = src.getGrade();
	}
	return (*this);
}


// methods
size_t	Bureaucrat::getGrade() const {
	return _grade;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::incrementGrade(){
	if (_grade <= 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

// exceptions
const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return "Grade too high...";
} 

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return "Grade too low...";
}

// insertion operator overload
std::ostream &operator << (std::ostream &o, const Bureaucrat &src) {
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return o;
}